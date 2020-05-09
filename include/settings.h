#pragma once

#include <map>

#include "constants.h"

enum class TYPES
{
    alpha = 0,
    binary = 1,
    numeric = 2,
    journal = 3, //Will be something like 'C' or 'D' and then a number. 'C'redit or 'D'ebit
    special = 4,
    alpha_numeric = 5,
    numeric_and_special = 6,
    alpha_numeric_special = 7,
    track_2_3_code = 8
};

enum class FIELD_LENGTH
{
    fixed = 0,
    length_variable = 1,
    double_length_variable = 2,
    tripple_length_variable = 3
};

class setting
{
public:
    int bit;
    TYPES type;
    FIELD_LENGTH field_length;
    int max_length;
};

class setup
{
public:
    setup()
    {
        setup_bitmap_1();
        setup_bitmap_2();
    }
    std::map<int, setting> settings;

private:
    void setup_bitmap_1()
    {
        setting temp_setting;
        temp_setting.bit = BITMAP_1::_01_SECOND_BITMAP;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 64;
        settings[BITMAP_1::_01_SECOND_BITMAP] = temp_setting;

        temp_setting.bit = BITMAP_1::_02_PAN;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 19;
        settings[BITMAP_1::_02_PAN] = temp_setting;

        temp_setting.bit = BITMAP_1::_03_PROCESSING_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 6;
        settings[BITMAP_1::_03_PROCESSING_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_04_AMOUNT_TRANSACTION;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_1::_04_AMOUNT_TRANSACTION] = temp_setting;

        temp_setting.bit = BITMAP_1::_05_AMOUNT_SETTLEMENT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_1::_05_AMOUNT_SETTLEMENT] = temp_setting;

        temp_setting.bit = BITMAP_1::_06_AMOUNT_CARDHOLDER_BILLING;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_1::_06_AMOUNT_CARDHOLDER_BILLING] = temp_setting;

        temp_setting.bit = BITMAP_1::_07_TRANSMISSION_DATE_TIME;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_1::_07_TRANSMISSION_DATE_TIME] = temp_setting;

        temp_setting.bit = BITMAP_1::_08_AMOUNT_CARDHOLDER_FEE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 8;
        settings[BITMAP_1::_08_AMOUNT_CARDHOLDER_FEE] = temp_setting;

        temp_setting.bit = BITMAP_1::_09_CONVERSION_RATE_SETTLEMENT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 8;
        settings[BITMAP_1::_09_CONVERSION_RATE_SETTLEMENT] = temp_setting;

        temp_setting.bit = BITMAP_1::_10_CONVERSION_RATE_CARDHOLDER_BILLING;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 8;
        settings[BITMAP_1::_10_CONVERSION_RATE_CARDHOLDER_BILLING] = temp_setting;

        temp_setting.bit = BITMAP_1::_11_SYSTEM_TRACE_AUDIT_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 6;
        settings[BITMAP_1::_11_SYSTEM_TRACE_AUDIT_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_1::_12_LOCAL_TRANSACTION_TIME;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 6;
        settings[BITMAP_1::_12_LOCAL_TRANSACTION_TIME] = temp_setting;

        temp_setting.bit = BITMAP_1::_13_LOCAL_TRANSACTION_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_13_LOCAL_TRANSACTION_DATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_14_EXPIRATION_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_14_EXPIRATION_DATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_15_SETTLEMENT_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_15_SETTLEMENT_DATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_16_CURRENCY_CONVERSION_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_16_CURRENCY_CONVERSION_DATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_17_CAPTURE_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_17_CAPTURE_DATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_18_MERCHANT_TYPE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_1::_18_MERCHANT_TYPE] = temp_setting;

        temp_setting.bit = BITMAP_1::_19_ACQUIRING_INSTITUTION;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_19_ACQUIRING_INSTITUTION] = temp_setting;

        temp_setting.bit = BITMAP_1::_20_PAN_EXTENDED;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_20_PAN_EXTENDED] = temp_setting;

        temp_setting.bit = BITMAP_1::_21_FORWARDING_INSTITUTION;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_21_FORWARDING_INSTITUTION] = temp_setting;

        temp_setting.bit = BITMAP_1::_22_POINT_OF_SERVICE_ENTRY_MODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_22_POINT_OF_SERVICE_ENTRY_MODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_23_APPLICATION_PAN_SEQUENCE_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_23_APPLICATION_PAN_SEQUENCE_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_1::_24_FUNCTION_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_24_FUNCTION_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_25_POINT_OF_SERVICE_CONDITION_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 2;
        settings[BITMAP_1::_25_POINT_OF_SERVICE_CONDITION_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_26_POINT_OF_SERVICE_CAPTURE_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 2;
        settings[BITMAP_1::_26_POINT_OF_SERVICE_CAPTURE_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_27_AUTHORIZING_ID_RESPONSE_LENGTH;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 1;
        settings[BITMAP_1::_27_AUTHORIZING_ID_RESPONSE_LENGTH] = temp_setting;

        temp_setting.bit = BITMAP_1::_28_AMOUNT_TRANSACTION_FEE;
        temp_setting.type = TYPES::journal;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 9;
        settings[BITMAP_1::_28_AMOUNT_TRANSACTION_FEE] = temp_setting;

        temp_setting.bit = BITMAP_1::_29_AMOUNT_SETTLEMENT_FEE;
        temp_setting.type = TYPES::journal;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 9;
        settings[BITMAP_1::_29_AMOUNT_SETTLEMENT_FEE] = temp_setting;

        temp_setting.bit = BITMAP_1::_30_AMOUNT_TRANSACTION_PROCESSING_FEE;
        temp_setting.type = TYPES::journal;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 9;
        settings[BITMAP_1::_30_AMOUNT_TRANSACTION_PROCESSING_FEE] = temp_setting;

        temp_setting.bit = BITMAP_1::_31_AMOUNT_SETTLEMENT_PROCESSING_FEE;
        temp_setting.type = TYPES::journal;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 9;
        settings[BITMAP_1::_31_AMOUNT_SETTLEMENT_PROCESSING_FEE] = temp_setting;

        temp_setting.bit = BITMAP_1::_32_ACQUIRING_INSTITUTION_ID_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 11;
        settings[BITMAP_1::_32_ACQUIRING_INSTITUTION_ID_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_33_FORWARDING_INSTITUTION_ID_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 11;
        settings[BITMAP_1::_33_FORWARDING_INSTITUTION_ID_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_34_PAN_EXTENDED_1;
        temp_setting.type = TYPES::numeric_and_special;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 28;
        settings[BITMAP_1::_34_PAN_EXTENDED_1] = temp_setting;

        temp_setting.bit = BITMAP_1::_35_TRACK_2_DATA;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 37;
        settings[BITMAP_1::_35_TRACK_2_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_36_TRACK_3_DATA;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 104;
        settings[BITMAP_1::_36_TRACK_3_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_37_RETRIEVAL_REFERENCE_NUMBER;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_1::_37_RETRIEVAL_REFERENCE_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_1::_38_AUTHORIZATION_ID_RESPONSE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 6;
        settings[BITMAP_1::_38_AUTHORIZATION_ID_RESPONSE] = temp_setting;

        temp_setting.bit = BITMAP_1::_39_RESPONSE_CODE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 2;
        settings[BITMAP_1::_39_RESPONSE_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_40_SERVICE_RESTRICTION_CODE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_40_SERVICE_RESTRICTION_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_41_CARD_ACCEPTOR_TERMINAL_ID;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 8;
        settings[BITMAP_1::_41_CARD_ACCEPTOR_TERMINAL_ID] = temp_setting;

        temp_setting.bit = BITMAP_1::_42_CARD_ACCEPTOR_ID_CODE;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 15;
        settings[BITMAP_1::_42_CARD_ACCEPTOR_ID_CODE] = temp_setting;

        temp_setting.bit = BITMAP_1::_43_CARD_ACCEPTOR_NAME_LOCATION;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 40;
        settings[BITMAP_1::_43_CARD_ACCEPTOR_NAME_LOCATION] = temp_setting;

        temp_setting.bit = BITMAP_1::_44_ADDITIONAL_RESPONSE_DATA;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 25;
        settings[BITMAP_1::_44_ADDITIONAL_RESPONSE_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_45_TRACK_1_DATA;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 76;
        settings[BITMAP_1::_45_TRACK_1_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_46_ADDITIONAL_DATA_ISO;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_46_ADDITIONAL_DATA_ISO] = temp_setting;

        temp_setting.bit = BITMAP_1::_47_ADDITIONAL_DATA_NATIONAL;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_47_ADDITIONAL_DATA_NATIONAL] = temp_setting;

        temp_setting.bit = BITMAP_1::_48_ADDITIONAL_DATA_PRIVATE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_48_ADDITIONAL_DATA_PRIVATE] = temp_setting;

        temp_setting.bit = BITMAP_1::_49_CURRENCY_CODE_TRANSACTION;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_49_CURRENCY_CODE_TRANSACTION] = temp_setting;

        temp_setting.bit = BITMAP_1::_50_CURRENCY_CODE_SETTLEMENT;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_50_CURRENCY_CODE_SETTLEMENT] = temp_setting;

        temp_setting.bit = BITMAP_1::_51_CURRENCY_CODE_CARDHOLDER_BILLING;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_1::_51_CURRENCY_CODE_CARDHOLDER_BILLING] = temp_setting;

        temp_setting.bit = BITMAP_1::_52_PERSONAL_ID_NUMBER_DATA;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 64;
        settings[BITMAP_1::_52_PERSONAL_ID_NUMBER_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_53_SECURITY_RELATED_CONTROL_INFO;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 16;
        settings[BITMAP_1::_53_SECURITY_RELATED_CONTROL_INFO] = temp_setting;

        temp_setting.bit = BITMAP_1::_54_ADDITIONAL_AMOUNTS;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 120;
        settings[BITMAP_1::_54_ADDITIONAL_AMOUNTS] = temp_setting;

        temp_setting.bit = BITMAP_1::_55_ICC_DATA;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_55_ICC_DATA] = temp_setting;

        temp_setting.bit = BITMAP_1::_56_RESERVED_ISO;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_56_RESERVED_ISO] = temp_setting;

        temp_setting.bit = BITMAP_1::_57_RESERVED_NATIONAL_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_57_RESERVED_NATIONAL_1] = temp_setting;

        temp_setting.bit = BITMAP_1::_58_RESERVED_NATIONAL_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_58_RESERVED_NATIONAL_2] = temp_setting;

        temp_setting.bit = BITMAP_1::_59_RESERVED_NATIONAL_3;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_59_RESERVED_NATIONAL_3] = temp_setting;

        temp_setting.bit = BITMAP_1::_60_RESERVED_NATIONAL_4;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_60_RESERVED_NATIONAL_4] = temp_setting;

        temp_setting.bit = BITMAP_1::_61_RESERVED_PRIVATE_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_61_RESERVED_PRIVATE_1] = temp_setting;

        temp_setting.bit = BITMAP_1::_62_RESERVED_PRIVATE_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_62_RESERVED_PRIVATE_2] = temp_setting;

        temp_setting.bit = BITMAP_1::_63_RESERVED_PRIVATE_3;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_1::_63_RESERVED_PRIVATE_3] = temp_setting;

        temp_setting.bit = BITMAP_1::_64_MESSAGE_AUTH_CODE;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 64;
        settings[BITMAP_1::_64_MESSAGE_AUTH_CODE] = temp_setting;
    }

    void setup_bitmap_2()
    {
        setting temp_setting;
        temp_setting.bit = BITMAP_2::_065_EXTENDED_BITMAP_INDICATOR;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 1;
        settings[BITMAP_2::_065_EXTENDED_BITMAP_INDICATOR] = temp_setting;

        temp_setting.bit = BITMAP_2::_066_SETTLMENT_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 1;
        settings[BITMAP_2::_066_SETTLMENT_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_067_EXTENDED_PAYMENT_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 2;
        settings[BITMAP_2::_067_EXTENDED_PAYMENT_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_068_RECIEVING_INSTITUTION_COUNTRY_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_2::_068_RECIEVING_INSTITUTION_COUNTRY_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_069_SETTLEMENT_INSTITUTION_COUNTRY_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_2::_069_SETTLEMENT_INSTITUTION_COUNTRY_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_070_NETWORK_MANAGEMENT_INFO_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 3;
        settings[BITMAP_2::_070_NETWORK_MANAGEMENT_INFO_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_071_MESSAGE_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_2::_071_MESSAGE_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_072_LAST_MESSAGE_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 4;
        settings[BITMAP_2::_072_LAST_MESSAGE_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_073_ACTION_DATE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 6;
        settings[BITMAP_2::_073_ACTION_DATE] = temp_setting;

        temp_setting.bit = BITMAP_2::_074_NUMBER_OF_CREDITS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_074_NUMBER_OF_CREDITS] = temp_setting;

        temp_setting.bit = BITMAP_2::_075_CREDITS_REVERSAL_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_075_CREDITS_REVERSAL_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_076_NUMBER_OF_DEBITS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_076_NUMBER_OF_DEBITS] = temp_setting;

        temp_setting.bit = BITMAP_2::_077_DEBITS_REVERSAL_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_077_DEBITS_REVERSAL_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_078_TRANSFER_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_078_TRANSFER_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_079_TRANSFER_REVERSAL_NUMBER;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_079_TRANSFER_REVERSAL_NUMBER] = temp_setting;

        temp_setting.bit = BITMAP_2::_080_NUMBER_OF_INQUIRIES;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_080_NUMBER_OF_INQUIRIES] = temp_setting;

        temp_setting.bit = BITMAP_2::_081_NUMBER_OF_AUTHORIZATIONS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 10;
        settings[BITMAP_2::_081_NUMBER_OF_AUTHORIZATIONS] = temp_setting;

        temp_setting.bit = BITMAP_2::_082_CREDITS_PROCESSING_FEE_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_2::_082_CREDITS_PROCESSING_FEE_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_083_CREDITS_TRANSACTION_FEE_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_2::_083_CREDITS_TRANSACTION_FEE_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_084_DEBITS_PROCESSING_FEE_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_2::_084_DEBITS_PROCESSING_FEE_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_085_DEBITS_TRANSACTION_FEE_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 12;
        settings[BITMAP_2::_085_DEBITS_TRANSACTION_FEE_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_086_TOTAL_AMOUNT_OF_CREDITS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 16;
        settings[BITMAP_2::_086_TOTAL_AMOUNT_OF_CREDITS] = temp_setting;

        temp_setting.bit = BITMAP_2::_087_CREDITS_REVERSAL_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 16;
        settings[BITMAP_2::_087_CREDITS_REVERSAL_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_088_TOTAL_AMOUNT_OF_DEBITS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 16;
        settings[BITMAP_2::_088_TOTAL_AMOUNT_OF_DEBITS] = temp_setting;

        temp_setting.bit = BITMAP_2::_089_DEBITS_REVERSAL_AMOUNT;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 16;
        settings[BITMAP_2::_089_DEBITS_REVERSAL_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_090_ORIGINAL_DATA_ELEMENTS;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 42;
        settings[BITMAP_2::_090_ORIGINAL_DATA_ELEMENTS] = temp_setting;

        temp_setting.bit = BITMAP_2::_091_FILE_UPDATE_CODE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 1;
        settings[BITMAP_2::_091_FILE_UPDATE_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_092_FILE_SECURITY_CODE;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 2;
        settings[BITMAP_2::_092_FILE_SECURITY_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_093_RESPONSE_INDICATOR;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 5;
        settings[BITMAP_2::_093_RESPONSE_INDICATOR] = temp_setting;

        temp_setting.bit = BITMAP_2::_094_SERVICE_INDICATOR;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 7;
        settings[BITMAP_2::_094_SERVICE_INDICATOR] = temp_setting;

        temp_setting.bit = BITMAP_2::_095_REPLACEMENT_AMOUNTS;
        temp_setting.type = TYPES::alpha_numeric;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 42;
        settings[BITMAP_2::_095_REPLACEMENT_AMOUNTS] = temp_setting;

        temp_setting.bit = BITMAP_2::_096_MESSAGE_SECURITY_CODE;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 64;
        settings[BITMAP_2::_096_MESSAGE_SECURITY_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_097_NET_SETTLEMENT_AMOUNT;
        temp_setting.type = TYPES::journal;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 17;
        settings[BITMAP_2::_097_NET_SETTLEMENT_AMOUNT] = temp_setting;

        temp_setting.bit = BITMAP_2::_098_PAYEE;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 25;
        settings[BITMAP_2::_098_PAYEE] = temp_setting;

        temp_setting.bit = BITMAP_2::_099_SETTLEMENT_INSTITUTION_ID_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 11;
        settings[BITMAP_2::_099_SETTLEMENT_INSTITUTION_ID_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_100_RECEIVING_INSTITUTION_ID_CODE;
        temp_setting.type = TYPES::numeric;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 11;
        settings[BITMAP_2::_100_RECEIVING_INSTITUTION_ID_CODE] = temp_setting;

        temp_setting.bit = BITMAP_2::_101_FILE_NAME;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 17;
        settings[BITMAP_2::_101_FILE_NAME] = temp_setting;

        temp_setting.bit = BITMAP_2::_102_ACCOUNT_ID_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 28;
        settings[BITMAP_2::_102_ACCOUNT_ID_1] = temp_setting;

        temp_setting.bit = BITMAP_2::_103_ACCOUNT_ID_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::double_length_variable;
        temp_setting.max_length = 28;
        settings[BITMAP_2::_103_ACCOUNT_ID_2] = temp_setting;

        temp_setting.bit = BITMAP_2::_104_TRANSACTION_DESCRIPTION;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 100;
        settings[BITMAP_2::_104_TRANSACTION_DESCRIPTION] = temp_setting;

        temp_setting.bit = BITMAP_2::_105_RESERVED_FOR_ISO_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_105_RESERVED_FOR_ISO_1] = temp_setting;

        temp_setting.bit = BITMAP_2::_106_RESERVED_FOR_ISO_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_106_RESERVED_FOR_ISO_2] = temp_setting;

        temp_setting.bit = BITMAP_2::_107_RESERVED_FOR_ISO_3;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_107_RESERVED_FOR_ISO_3] = temp_setting;

        temp_setting.bit = BITMAP_2::_108_RESERVED_FOR_ISO_4;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_108_RESERVED_FOR_ISO_4] = temp_setting;

        temp_setting.bit = BITMAP_2::_109_RESERVED_FOR_ISO_5;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_109_RESERVED_FOR_ISO_5] = temp_setting;

        temp_setting.bit = BITMAP_2::_110_RESERVED_FOR_ISO_6;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_110_RESERVED_FOR_ISO_6] = temp_setting;

        temp_setting.bit = BITMAP_2::_111_RESERVED_FOR_ISO_7;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_111_RESERVED_FOR_ISO_7] = temp_setting;

        temp_setting.bit = BITMAP_2::_112_RESERVED_FOR_NATIONAL_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_112_RESERVED_FOR_NATIONAL_1] = temp_setting;

        temp_setting.bit = BITMAP_2::_113_RESERVED_FOR_NATIONAL_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_113_RESERVED_FOR_NATIONAL_2] = temp_setting;

        temp_setting.bit = BITMAP_2::_114_RESERVED_FOR_NATIONAL_3;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_114_RESERVED_FOR_NATIONAL_3] = temp_setting;

        temp_setting.bit = BITMAP_2::_115_RESERVED_FOR_NATIONAL_4;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_115_RESERVED_FOR_NATIONAL_4] = temp_setting;

        temp_setting.bit = BITMAP_2::_116_RESERVED_FOR_NATIONAL_5;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_116_RESERVED_FOR_NATIONAL_5] = temp_setting;

        temp_setting.bit = BITMAP_2::_117_RESERVED_FOR_NATIONAL_6;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_117_RESERVED_FOR_NATIONAL_6] = temp_setting;

        temp_setting.bit = BITMAP_2::_118_RESERVED_FOR_NATIONAL_7;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_118_RESERVED_FOR_NATIONAL_7] = temp_setting;

        temp_setting.bit = BITMAP_2::_119_RESERVED_FOR_NATIONAL_8;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_119_RESERVED_FOR_NATIONAL_8] = temp_setting;

        temp_setting.bit = BITMAP_2::_120_RESERVED_FOR_PRIVATE_1;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_120_RESERVED_FOR_PRIVATE_1] = temp_setting;

        temp_setting.bit = BITMAP_2::_121_RESERVED_FOR_PRIVATE_2;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_121_RESERVED_FOR_PRIVATE_2] = temp_setting;

        temp_setting.bit = BITMAP_2::_122_RESERVED_FOR_PRIVATE_3;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_122_RESERVED_FOR_PRIVATE_3] = temp_setting;

        temp_setting.bit = BITMAP_2::_123_RESERVED_FOR_PRIVATE_4;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_123_RESERVED_FOR_PRIVATE_4] = temp_setting;

        temp_setting.bit = BITMAP_2::_124_RESERVED_FOR_PRIVATE_5;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_124_RESERVED_FOR_PRIVATE_5] = temp_setting;

        temp_setting.bit = BITMAP_2::_125_RESERVED_FOR_PRIVATE_6;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_125_RESERVED_FOR_PRIVATE_6] = temp_setting;

        temp_setting.bit = BITMAP_2::_126_RESERVED_FOR_PRIVATE_7;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_126_RESERVED_FOR_PRIVATE_7] = temp_setting;

        temp_setting.bit = BITMAP_2::_127_RESERVED_FOR_PRIVATE_8;
        temp_setting.type = TYPES::alpha_numeric_special;
        temp_setting.field_length = FIELD_LENGTH::tripple_length_variable;
        temp_setting.max_length = 999;
        settings[BITMAP_2::_127_RESERVED_FOR_PRIVATE_8] = temp_setting;

        temp_setting.bit = BITMAP_2::_128_MESSAGE_AUTH_CODE;
        temp_setting.type = TYPES::binary;
        temp_setting.field_length = FIELD_LENGTH::fixed;
        temp_setting.max_length = 64;
        settings[BITMAP_2::_128_MESSAGE_AUTH_CODE] = temp_setting;
    }
};
