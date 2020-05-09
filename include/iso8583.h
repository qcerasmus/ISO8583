#pragma once

#include <bitset>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

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

    /**
     * @brief values
     * After calling process_iso_message, the values are stored
     * in this member.
     */
    std::map<int, std::string> values;

private:
    setup s;
    std::string mti_message;
    std::bitset<64> bitmap;
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
     * @param field Number of the field to read.
     * @return a string value.
     */
    void read_values();
};

iso8583::iso8583()
{
    logger = spdlog::get("console");
}

bool iso8583::process_iso_message(const std::string_view iso_message)
{
    full_message = iso_message;
    mti_message = std::string(&iso_message[0], 4);
    setup_bitmap(std::string(&iso_message[4], 16));

    read_values();

    return true;
}

void iso8583::setup_bitmap(const std::string_view bitmap_string)
{
    bitmap.reset();
    int count = 0;
    logger->trace(fmt::format("setting up bitmap with string: {0}", bitmap_string));
    for(int i = 0; i < 16; i++)
    {
        if ((bitmap_string[i] & 'F') == 'F')
        {
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & 'E') == 'E')
        {
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            count++;
        }
        else if ((bitmap_string[i] & 'D') == 'D')
        {
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & 'C') == 'C')
        {
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & 'B') == 'B')
        {
            bitmap[count] = 1; count++;
            count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & 'A') == 'A')
        {
            bitmap[count] = 1; count++;
            count++;
            bitmap[count] = 1; count++;
            count++;
        }
        else if ((bitmap_string[i] & '9') == '9')
        {
            bitmap[count] = 1; count++;
            count++;
            count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & '8') == '8')
        {
            bitmap[count] = 1; count++;
            count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & '7') == '7')
        {
            count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & '6') == '6')
        {
            count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
            count++;
        }
        else if ((bitmap_string[i] & '5') == '5')
        {
            count++;
            bitmap[count] = 1; count++;
            count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & '4') == '4')
        {
            count++;
            bitmap[count] = 1; count++;
            count++;
            count++;
        }
        else if ((bitmap_string[i] & '3') == '3')
        {
            count++;
            count++;
            bitmap[count] = 1; count++;
            bitmap[count] = 1; count++;
        }
        else if ((bitmap_string[i] & '2') == '2')
        {
            count++;
            count++;
            bitmap[count] = 1; count++;
            count++;
        }
        else if ((bitmap_string[i] & '1') == '1')
        {
            count++;
            count++;
            count++;
            bitmap[count] = 1; count++;
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

void iso8583::read_values()
{
    bool second_bitmap = false;
    for (int i = BITMAP_1::_02_PAN; i <= BITMAP_2::_128_MESSAGE_AUTH_CODE; i++)
    {
        if (i == BITMAP_2::_065_EXTENDED_BITMAP_INDICATOR)
        {
            setup_bitmap(std::string(&full_message[position], 16));
            position += 16;
            second_bitmap = true;
        }
        if (!bitmap.test(i - (second_bitmap ? 64 : 0) ))
            continue;

        auto setting = s.settings[i];

        if (setting.field_length == FIELD_LENGTH::fixed)
        {
            std::string value = std::string(full_message, position, setting.max_length);
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            position += setting.max_length;
            values[i] = value;
        }
        else if (setting.field_length == FIELD_LENGTH::length_variable)
        {
            int length = full_message[position] - '0';
            position += length + 1;
            std::string value = std::string(full_message, position, length);
            values[i] = value;
        }
        else if (setting.field_length == FIELD_LENGTH::double_length_variable)
        {
            std::string length_as_string = std::string(full_message, position, 2);
            position += 2;
            int length = std::stoi(length_as_string);
            std::string value = std::string(full_message, position, length);
            position += length;
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            values[i] =  value;
        }
        else if (setting.field_length == FIELD_LENGTH::tripple_length_variable)
        {
            std::string length_as_string = std::string(full_message, position, 3);
            position += 3;
            int length = std::stoi(length_as_string);
            std::string value = std::string(full_message, position, length);
            position += length;
            logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
            values[i] =  value;
        }
    }
}
