#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "iso8583.h"

int main()
{
    auto console = spdlog::stdout_color_mt("console");
    console->set_level(spdlog::level::debug);

    // This could be something that we received over the network.
    char message_received[] = {
        0x30, 0x32, 0x30, 0x30,                                                                         // MTI TYPE
        0x43, 0x32, 0x30, 0x30, 0x30, 0x34, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x34, // BITMAP
        0x31, 0x36,                                                                                     // LENGTH OF PAN
        0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, // PAN
        0x30, 0x36, 0x30, 0x39, 0x31, 0x37, 0x33, 0x30, 0x33, 0x30,                                     // DE7
        0x41, 0x42, 0x43,                                                                               // DE22
        0x30, 0x31, 0x39, // Length of DE063
        0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38,
        0x39, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30,
        0x30,            // SECOND BITMAP
        0x30, 0x33,      // LENGTH OF DE101
        0x44, 0x45, 0x46 // DE101
    };

    iso8583 i(RESPONSE_CODES::V1993);
    i.process_iso_message(std::string(&message_received[0]));
    for (const auto &value : i.values)
    {
        console->debug("DE: {0}\t VALUE: {1}", (value.first) + 1, value.second);
    }

    console->debug("resetting");

    i.reset();
    i.mti_message = "0200";
    i.set_value(BITMAP_1::_02_PAN, "1234567890123456");
    i.set_value(BITMAP_1::_07_TRANSMISSION_DATE_TIME, "0609173030");
    i.set_value(BITMAP_1::_22_POINT_OF_SERVICE_ENTRY_MODE, "ABC");
    i.set_value(BITMAP_1::_39_RESPONSE_CODE, std::string{RESPONSE_CODES_1993::MESSAGES_0::APPROVED});
    i.set_value(BITMAP_1::_63_RESERVED_PRIVATE_3, "1234567890123456789");
    i.set_value(BITMAP_2::_101_FILE_NAME, "DEF");
    const auto generated_iso_message = i.generate_iso_message();
    console->debug(fmt::format("generated iso string: {0}", generated_iso_message));

    i.reset();
    console->debug("processing the generated string");
    i.process_iso_message(generated_iso_message);
    for (const auto &value : i.values)
    {
        console->debug("DE: {0}\t VALUE: {1}", (value.first) + 1, value.second);
    }

    return 0;
}
