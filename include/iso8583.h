#pragma once

#include <bitset>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "settings.h"

class iso8583
{
public:
    iso8583()
    {
        logger = spdlog::get("console");
    }

    void setup_bitmap_1(const std::string_view bitmap_string)
    {
        int count = 0;
        for(int i = 0; i < 16; i++)
        {
            if ((bitmap_string[i] & '8') == '8')
                bitmap_1[count] = 1;
            count++;

            if ((bitmap_string[i] & '4') == '4')
                bitmap_1[count] = 1;
            count++;

            if ((bitmap_string[i] & '2') == '2')
                bitmap_1[count] = 1;
            count++;

            if ((bitmap_string[i] & '1') == '1')
                bitmap_1[count] = 1;
            count++;
        }
        logger->trace("bitmap1: {0}", bitmap_1.to_string());
    }

    std::string read_value(int field)
    {
        if (field > 63 && !bitmap_1.test(BITMAP_1::_01_SECOND_BITMAP))
            throw std::runtime_error(fmt::format("The field {0} is not in this message", field));
        if (field > 123 || field < 0)
            throw std::runtime_error(fmt::format("The field {0} is not in this message", field));
        if (!bitmap_1.test(field))
            throw std::runtime_error(fmt::format("the field {0} was not set", field));

        unsigned long long position = 20;
        //Get position where the actual values start:
        if (bitmap_1.test(BITMAP_1::_01_SECOND_BITMAP))
            position += 16;

        for (int i = BITMAP_1::_02_PAN; i <= field; i++)
        {
            if (!bitmap_1.test(i))
                continue;

            auto setting = s.settings[i];

            //We skip the bytes we would've needed.
            if (i != field)
            {
                if (setting.field_length == FIELD_LENGTH::fixed)
                    position += setting.max_length;
                else if (setting.field_length == FIELD_LENGTH::length_variable)
                {
                    int length = full_message[position] - '0';
                    position += length + 1;
                }
                else if (setting.field_length == FIELD_LENGTH::double_length_variable)
                {
                    std::string length_as_string = std::string(full_message, position, 2);
                    position += std::stoi(length_as_string) + 2;
                }
                else if (setting.field_length == FIELD_LENGTH::tripple_length_variable)
                {
                    std::string length_as_string = std::string(full_message, position, 3);
                    position += std::stoi(length_as_string) + 3;
                }
            }

            else
            {
                if (setting.field_length == FIELD_LENGTH::fixed)
                {
                    std::string value = std::string(full_message, position, setting.max_length);
                    logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
                    return value;
                }
                else if (setting.field_length == FIELD_LENGTH::length_variable)
                {
                    int length = full_message[position] - '0';
                    position += length + 1;
                    std::string value = std::string(full_message, position, length);
                    return value;
                }
                else if (setting.field_length == FIELD_LENGTH::double_length_variable)
                {
                    std::string length_as_string = std::string(full_message, position, 2);
                    position += 2;
                    int length = std::stoi(length_as_string);
                    std::string value = std::string(full_message, position, length);
                    position += length;
                    logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
                    return value;
                }
                else if (setting.field_length == FIELD_LENGTH::tripple_length_variable)
                {
                    std::string length_as_string = std::string(full_message, position, 3);
                    position += 3;
                    int length = std::stoi(length_as_string);
                    std::string value = std::string(full_message, position, length);
                    position += length;
                    logger->trace(fmt::format("field: {0} value: {1}", i + 1, value));
                    return value;
                }
            }
        }

        //This should be an error
        throw std::runtime_error("No value was found");
    }

    bool process_iso_message(const std::string_view iso_message)
    {
        full_message = iso_message;
        mti_message = std::string(&iso_message[0], 4);
        setup_bitmap_1(std::string(&iso_message[4], 16));

        for (std::size_t i = 0; i < bitmap_1.size(); i++)
        {
            if (bitmap_1.test(i))
            {
                values[i] = read_value(i);
            }
        }

        return true;
    }

    std::map<int, std::string> values;

private:
    setup s;
    std::string mti_message;
    std::bitset<64> bitmap_1;
    std::string_view full_message;
    std::shared_ptr<spdlog::logger> logger;
};
