#pragma once

#include <bitset>
#include <iomanip>
#include <sstream>
#include <spdlog/spdlog.h>

#include "settings.h"

class iso8583
{
public:
    /**
     * @brief iso8583
     * Sets up the logger to be used in this class.
     */
    iso8583();

    /**
     * @brief process_iso_message
     * Sets up the bitmap and reads the values.
     * The values are stored in the std::map of values.
     * @param iso_message The message that was received.
     * @return True if the message was parsed successfully.
     */
    bool process_iso_message(const std::string_view iso_message);

    void reset();

    bool set_value(int bit, const std::string& value);

    std::string generate_iso_message();

    /**
     * @brief values
     * After calling process_iso_message, the values are stored
     * in this member.
     */
    std::map<int, std::string> values;

    std::string mti_message;
private:
    setup s;
    std::bitset<64> bitmap;
    std::bitset<64> second_bitmap;
    std::string_view full_message;
    std::shared_ptr<spdlog::logger> logger;
    unsigned long long position = 20;

    /**
     * @brief setup_bitmap_1
     * Sets up the first bitmap of the message received.
     * @param bitmap_string basically the first 16 characters after the MTI.
     */
    void setup_bitmap(const std::string_view bitmap_string);

    /**
     * @brief read_value
     * Goes through the message and reads the fields that were set in the bitmap.
     * @return a string value.
     */
    void read_values();

    template<std::size_t N>
    void reverse_bitset(std::bitset<N>& b);
};

template <std::size_t N>
void iso8583::reverse_bitset(std::bitset<N>& b)
{
    for (std::size_t i = 0; i < N / 2; ++i)
    {
        bool t = b[i];
        b[i] = b[N - i - 1];
        b[N - i - 1] = t;
    }
}

inline iso8583::iso8583()
{
    logger = spdlog::get("console");
}

inline bool iso8583::process_iso_message(const std::string_view iso_message)
{
    full_message = iso_message;
    mti_message = std::string(&iso_message[0], 4);
    setup_bitmap(std::string(&iso_message[4], 16));

    read_values();

    return true;
}

inline void iso8583::reset()
{
    mti_message = "";
    bitmap.reset();
    full_message = "";
    values.clear();
    position = 20;
}

inline bool iso8583::set_value(int bit, const std::string& value)
{
    const auto setting = s.settings[bit];
    if (bit < 0 || bit > 128 || value.empty())
        return false;
    if (value.length() > static_cast<size_t>(setting.max_length))
        return false;

    if (setting.field_length == FIELD_LENGTH::fixed)
        values[bit] = value;
    else if (setting.field_length == FIELD_LENGTH::length_variable)
        values[bit] = std::to_string(value.length()) + value;
    else if (setting.field_length == FIELD_LENGTH::double_length_variable)
    {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(2) << value.length();
        values[bit] = oss.str() + value;
    }
    else if (setting.field_length == FIELD_LENGTH::tripple_length_variable)
    {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(3) << value.length();
        values[bit] = oss.str() + value;
    }

    if (bit <= 63)
        bitmap.set(bit);
    else
    {
        bitmap.set(0);
        second_bitmap.set(bit - 64);
    }

    return true;
}

inline std::string iso8583::generate_iso_message()
{
    auto result = mti_message;
    auto temp_bit_str = bitmap.to_string();
    for (auto i = 15; i >= 0; i--)
    {
        std::bitset<4> temp_bit_set(temp_bit_str.substr(i * 4, (i * 4) + 3));
        reverse_bitset(temp_bit_set);
        std::stringstream stream;
        stream << std::uppercase << std::hex << temp_bit_set.to_ullong();
        result += stream.str();
    }
    for (auto i = 0; i < 64; i++)
    {
        if (values.find(i) == values.end())
            continue;

        result += values[i];
    }
    if (!bitmap.test(0))
        return result;

    temp_bit_str = second_bitmap.to_string();
    for (auto i = 15; i >= 0; i--)
    {
        std::bitset<4> temp_bit_set(temp_bit_str.substr(i * 4, (i * 4) + 3));
        reverse_bitset(temp_bit_set);
        std::stringstream stream;
        stream << std::uppercase << std::hex << temp_bit_set.to_ullong();
        result += stream.str();
    }
    for (auto i = 64; i < 128; i++)
    {
        if (values.find(i) == values.end())
            continue;

        result += values[i];
    }

    return result;
}

inline void iso8583::setup_bitmap(const std::string_view bitmap_string)
{
    bitmap.reset();
    auto count = 0;
    logger->trace(fmt::format("setting up bitmap with string: {0}", bitmap_string));
    for(auto i = 0; i < 16; i++)
    {
        if ((bitmap_string[i] & 'F') == 'F')
        {
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & 'E') == 'E')
        {
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            count++;
        }
        else if ((bitmap_string[i] & 'D') == 'D')
        {
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & 'C') == 'C')
        {
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & 'B') == 'B')
        {
            bitmap[count] = true; count++;
            count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & 'A') == 'A')
        {
            bitmap[count] = true; count++;
            count++;
            bitmap[count] = true; count++;
            count++;
        }
        else if ((bitmap_string[i] & '9') == '9')
        {
            bitmap[count] = true; count++;
            count++;
            count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & '8') == '8')
        {
            bitmap[count] = true; count++;
            count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & '7') == '7')
        {
            count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & '6') == '6')
        {
            count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
            count++;
        }
        else if ((bitmap_string[i] & '5') == '5')
        {
            count++;
            bitmap[count] = true; count++;
            count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & '4') == '4')
        {
            count++;
            bitmap[count] = true; count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & '3') == '3')
        {
            count++;
            count++;
            bitmap[count] = true; count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & '2') == '2')
        {
            count++;
            count++;
            bitmap[count] = true; count++;
            count++;
        }
        else if ((bitmap_string[i] & '1') == '1')
        {
            count++;
            count++;
            count++;
            bitmap[count] = true; count++;
        }
        else if ((bitmap_string[i] & '0') == '0')
        {
            count++;
            count++;
            count++;
            count++;
        }
    }
    logger->trace("bitmap: {0}", bitmap.to_string());
}

inline void iso8583::read_values()
{
    auto second_bitmap_bool = false;
    for (auto i = BITMAP_1::_02_PAN; i <= BITMAP_2::_128_MESSAGE_AUTH_CODE; i++)
    {
        if (i == BITMAP_2::_065_EXTENDED_BITMAP_INDICATOR)
        {
            setup_bitmap(std::string(&full_message[position], 16));
            position += 16;
            second_bitmap_bool = true;
        }
        if (!bitmap.test(static_cast<size_t>(i) - (second_bitmap_bool ? 64 : 0)))
            continue;

        const auto setting = s.settings[i];

        if (setting.field_length == FIELD_LENGTH::fixed)
        {
            auto value = std::string(full_message, position, setting.max_length);
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            position += setting.max_length;
            values[i] = value;
        }
        else if (setting.field_length == FIELD_LENGTH::length_variable)
        {
            const auto length = full_message[position] - static_cast<unsigned long long>('0');
            position += length + 1;
            const auto value = std::string(full_message, position, length);
            values[i] = value;
        }
        else if (setting.field_length == FIELD_LENGTH::double_length_variable)
        {
            auto length_as_string = std::string(full_message, position, 2);
            position += 2;
            const auto length = std::stoi(length_as_string);
            auto value = std::string(full_message, position, length);
            position += length;
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            values[i] =  value;
        }
        else if (setting.field_length == FIELD_LENGTH::tripple_length_variable)
        {
            auto length_as_string = std::string(full_message, position, 3);
            position += 3;
            const auto length = std::stoi(length_as_string);
            auto value = std::string(full_message, position, length);
            position += length;
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            values[i] =  value;
        }
    }
}
