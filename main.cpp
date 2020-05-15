#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "iso8583.h"

int main()
{
    auto console = spdlog::stdout_color_mt("console");
    console->set_level(spdlog::level::trace);

    //This could be something that we received over the network.
    char message_received[] = { 0x30, 0x32, 0x30, 0x30, //MTI TYPE
                                0x43, 0x32, 0x30, 0x30, 0x30, 0x34, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x34, //BITMAP
                                0x31, 0x36, //LENGTH OF PAN
                                0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,  //PAN
                                0x30, 0x36, 0x30, 0x39, 0x31, 0x37, 0x33, 0x30, 0x33, 0x30, //DE7
                                0x41, 0x42, 0x43, //DE22
                                0x30, 0x31, 0x39, //Length of DE063
                                0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30,
                                0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
                                0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x38, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, //SECOND BITMAP
                                0x30, 0x33, //LENGTH OF DE101
                                0x44, 0x45, 0x46 //DE101
                              };

    iso8583 i;
    i.process_iso_message(std::string(&message_received[0]));
    for (const auto value : i.values)
    {
        console->debug("DE: {0}\t VALUE: {1}", (value.first) + 1, value.second);
    }

    i.reset();
    i.mti_message = "0200";
    i.set_value(BITMAP_1::_02_PAN, "1234567890123456");
    i.set_value(BITMAP_1::_07_TRANSMISSION_DATE_TIME, "0609173030");
    i.set_value(BITMAP_1::_22_POINT_OF_SERVICE_ENTRY_MODE, "ABC");
    i.set_value(BITMAP_1::_63_RESERVED_PRIVATE_3, "1234567890123456789");
    i.set_value(BITMAP_2::_101_FILE_NAME, "DEF");
    console->trace(i.generate_iso_message());
    i.reset();
    i.process_iso_message("0200C2000400000000041612345678901234560609173030ABC0191234567890123456789000000000800000003DEF");

    return 0;
}
