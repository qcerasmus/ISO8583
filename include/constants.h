#pragma once

#include <string>

/**
 * namespace for the MTI Message types.
 */
namespace MTI_MESSAGE
{
    constexpr std::string_view AUTHORIZATION_REQUEST = "0100";
    constexpr std::string_view AUTHORIZATION_RESPONSE = "0110";
    constexpr std::string_view AUTHORIZATION_ADVICE = "0120";
    constexpr std::string_view AUTHORIZATION_ADVICE_REPEAT = "0121";
    constexpr std::string_view ISSUER_RESPONSE_TO_AUTHORIZATION_ADVICE = "0130";
    constexpr std::string_view ACQUIRER_FINANCIAL_REQUEST = "0200";
    constexpr std::string_view ISSUER_RESPONSE_TO_FINANCIAL_REQUEST = "0210";
    constexpr std::string_view ACQUIRER_FINANCIAL_ADVICE = "0220";
    constexpr std::string_view ACQUIRER_FINANCIAL_ADVICE_REPEAT = "0221";
    constexpr std::string_view ISSUER_RESPONSE_TO_FINANCIAL_ADVICE = "0230";
    constexpr std::string_view BATCH_UPLOAD = "0320";
    constexpr std::string_view BATCH_UPLOAD_RESPONSE = "0330";
    constexpr std::string_view ACQUIRER_REVERSAL_REQUEST = "0400";
    constexpr std::string_view ACQUIRER_REVERSAL_ADVICE = "0420";
    constexpr std::string_view ACQUIRER_REVERSAL_ADVICE_RESPONSE = "0430";
    constexpr std::string_view BATCH_SETTLEMENT_RESPONSE = "0510";
    constexpr std::string_view NETWORK_MANAGEMENT_REQUEST = "0800";
    constexpr std::string_view NETWORK_MANAGEMENT_RESPONSE = "0810";
    constexpr std::string_view NETWORK_MANAGEMENT_ADVICE = "0820";
}

/**
 * First bitmap positions.
 */
namespace BITMAP_1
{
    constexpr int _01_SECOND_BITMAP = 0;
    constexpr int _02_PAN = 1;
    constexpr int _03_PROCESSING_CODE = 2;
    constexpr int _04_AMOUNT_TRANSACTION = 3;
    constexpr int _05_AMOUNT_SETTLEMENT = 4;
    constexpr int _06_AMOUNT_CARDHOLDER_BILLING = 5;
    constexpr int _07_TRANSMISSION_DATE_TIME = 6;
    constexpr int _08_AMOUNT_CARDHOLDER_FEE = 7;
    constexpr int _09_CONVERSION_RATE_SETTLEMENT = 8;
    constexpr int _10_CONVERSION_RATE_CARDHOLDER_BILLING = 9;
    constexpr int _11_SYSTEM_TRACE_AUDIT_NUMBER = 10;
    constexpr int _12_LOCAL_TRANSACTION_TIME = 11; //hhmmss
    constexpr int _13_LOCAL_TRANSACTION_DATE = 12; //MMDD
    constexpr int _14_EXPIRATION_DATE = 13;
    constexpr int _15_SETTLEMENT_DATE = 14;
    constexpr int _16_CURRENCY_CONVERSION_DATE = 15;
    constexpr int _17_CAPTURE_DATE = 16;
    constexpr int _18_MERCHANT_TYPE = 17; //or category code
    constexpr int _19_ACQUIRING_INSTITUTION = 18; //country code ZAF for example
    constexpr int _20_PAN_EXTENDED = 19; //country code
    constexpr int _21_FORWARDING_INSTITUTION = 20; //country code
    constexpr int _22_POINT_OF_SERVICE_ENTRY_MODE = 21;
    constexpr int _23_APPLICATION_PAN_SEQUENCE_NUMBER = 22;
    constexpr int _24_FUNCTION_CODE = 23; //ISO8583 or ISO1993 or network international id.
    constexpr int _25_POINT_OF_SERVICE_CONDITION_CODE = 24;
    constexpr int _26_POINT_OF_SERVICE_CAPTURE_CODE = 25;
    constexpr int _27_AUTHORIZING_ID_RESPONSE_LENGTH = 26;
    constexpr int _28_AMOUNT_TRANSACTION_FEE = 27;
    constexpr int _29_AMOUNT_SETTLEMENT_FEE = 28;
    constexpr int _30_AMOUNT_TRANSACTION_PROCESSING_FEE = 29;
    constexpr int _31_AMOUNT_SETTLEMENT_PROCESSING_FEE = 30;
    constexpr int _32_ACQUIRING_INSTITUTION_ID_CODE = 31;
    constexpr int _33_FORWARDING_INSTITUTION_ID_CODE = 32;
    constexpr int _34_PAN_EXTENDED_1 = 33;
    constexpr int _35_TRACK_2_DATA = 34;
    constexpr int _36_TRACK_3_DATA = 35;
    constexpr int _37_RETRIEVAL_REFERENCE_NUMBER = 36;
    constexpr int _38_AUTHORIZATION_ID_RESPONSE = 37;
    constexpr int _39_RESPONSE_CODE = 38;
    constexpr int _40_SERVICE_RESTRICTION_CODE = 39;
    constexpr int _41_CARD_ACCEPTOR_TERMINAL_ID = 40;
    constexpr int _42_CARD_ACCEPTOR_ID_CODE = 41;
    constexpr int _43_CARD_ACCEPTOR_NAME_LOCATION = 42; //1-23 street-address, 36 city, 38 state, 39-40 country
    constexpr int _44_ADDITIONAL_RESPONSE_DATA = 43;
    constexpr int _45_TRACK_1_DATA = 44;
    constexpr int _46_ADDITIONAL_DATA_ISO = 45;
    constexpr int _47_ADDITIONAL_DATA_NATIONAL = 46;
    constexpr int _48_ADDITIONAL_DATA_PRIVATE = 47;
    constexpr int _49_CURRENCY_CODE_TRANSACTION = 48;
    constexpr int _50_CURRENCY_CODE_SETTLEMENT = 49;
    constexpr int _51_CURRENCY_CODE_CARDHOLDER_BILLING = 50;
    constexpr int _52_PERSONAL_ID_NUMBER_DATA = 51;
    constexpr int _53_SECURITY_RELATED_CONTROL_INFO = 52;
    constexpr int _54_ADDITIONAL_AMOUNTS = 53;
    constexpr int _55_ICC_DATA = 54; //EMV Having multiple tags
    constexpr int _56_RESERVED_ISO = 55;
    constexpr int _57_RESERVED_NATIONAL_1 = 56;
    constexpr int _58_RESERVED_NATIONAL_2 = 57;
    constexpr int _59_RESERVED_NATIONAL_3 = 58;
    constexpr int _60_RESERVED_NATIONAL_4 = 59;
    constexpr int _61_RESERVED_PRIVATE_1 = 60;
    constexpr int _62_RESERVED_PRIVATE_2 = 61;
    constexpr int _63_RESERVED_PRIVATE_3 = 62;
    constexpr int _64_MESSAGE_AUTH_CODE = 63;
}

/**
 * Second bitmap positions.
 */
namespace BITMAP_2
{
    constexpr int _065_EXTENDED_BITMAP_INDICATOR = 64;
    constexpr int _066_SETTLEMENT_CODE = 65;
    constexpr int _067_EXTENDED_PAYMENT_CODE = 66;
    constexpr int _068_RECEIVING_INSTITUTION_COUNTRY_CODE = 67;
    constexpr int _069_SETTLEMENT_INSTITUTION_COUNTRY_CODE = 68;
    constexpr int _070_NETWORK_MANAGEMENT_INFO_CODE = 69;
    constexpr int _071_MESSAGE_NUMBER = 70;
    constexpr int _072_LAST_MESSAGE_NUMBER = 71;
    constexpr int _073_ACTION_DATE = 72; //YYMMDD
    constexpr int _074_NUMBER_OF_CREDITS = 73;
    constexpr int _075_CREDITS_REVERSAL_NUMBER = 74;
    constexpr int _076_NUMBER_OF_DEBITS = 75;
    constexpr int _077_DEBITS_REVERSAL_NUMBER = 76;
    constexpr int _078_TRANSFER_NUMBER = 77;
    constexpr int _079_TRANSFER_REVERSAL_NUMBER = 78;
    constexpr int _080_NUMBER_OF_INQUIRIES = 79;
    constexpr int _081_NUMBER_OF_AUTHORIZATIONS = 80;
    constexpr int _082_CREDITS_PROCESSING_FEE_AMOUNT = 81;
    constexpr int _083_CREDITS_TRANSACTION_FEE_AMOUNT = 82;
    constexpr int _084_DEBITS_PROCESSING_FEE_AMOUNT = 83;
    constexpr int _085_DEBITS_TRANSACTION_FEE_AMOUNT = 84;
    constexpr int _086_TOTAL_AMOUNT_OF_CREDITS = 85;
    constexpr int _087_CREDITS_REVERSAL_AMOUNT = 86;
    constexpr int _088_TOTAL_AMOUNT_OF_DEBITS = 87;
    constexpr int _089_DEBITS_REVERSAL_AMOUNT = 88;
    constexpr int _090_ORIGINAL_DATA_ELEMENTS = 89;
    constexpr int _091_FILE_UPDATE_CODE = 90;
    constexpr int _092_FILE_SECURITY_CODE = 91;
    constexpr int _093_RESPONSE_INDICATOR = 92;
    constexpr int _094_SERVICE_INDICATOR = 93;
    constexpr int _095_REPLACEMENT_AMOUNTS = 94;
    constexpr int _096_MESSAGE_SECURITY_CODE = 95;
    constexpr int _097_NET_SETTLEMENT_AMOUNT = 96;
    constexpr int _098_PAYEE = 97;
    constexpr int _099_SETTLEMENT_INSTITUTION_ID_CODE = 98;
    constexpr int _100_RECEIVING_INSTITUTION_ID_CODE = 99;
    constexpr int _101_FILE_NAME = 100;
    constexpr int _102_ACCOUNT_ID_1 = 101;
    constexpr int _103_ACCOUNT_ID_2 = 102;
    constexpr int _104_TRANSACTION_DESCRIPTION = 103;
    constexpr int _105_RESERVED_FOR_ISO_1 = 104;
    constexpr int _106_RESERVED_FOR_ISO_2 = 105;
    constexpr int _107_RESERVED_FOR_ISO_3 = 106;
    constexpr int _108_RESERVED_FOR_ISO_4 = 107;
    constexpr int _109_RESERVED_FOR_ISO_5 = 108;
    constexpr int _110_RESERVED_FOR_ISO_6 = 109;
    constexpr int _111_RESERVED_FOR_ISO_7 = 110;
    constexpr int _112_RESERVED_FOR_NATIONAL_1 = 111;
    constexpr int _113_RESERVED_FOR_NATIONAL_2 = 112;
    constexpr int _114_RESERVED_FOR_NATIONAL_3 = 113;
    constexpr int _115_RESERVED_FOR_NATIONAL_4 = 114;
    constexpr int _116_RESERVED_FOR_NATIONAL_5 = 115;
    constexpr int _117_RESERVED_FOR_NATIONAL_6 = 116;
    constexpr int _118_RESERVED_FOR_NATIONAL_7 = 117;
    constexpr int _119_RESERVED_FOR_NATIONAL_8 = 118;
    constexpr int _120_RESERVED_FOR_PRIVATE_1 = 119;
    constexpr int _121_RESERVED_FOR_PRIVATE_2 = 120;
    constexpr int _122_RESERVED_FOR_PRIVATE_3 = 121;
    constexpr int _123_RESERVED_FOR_PRIVATE_4 = 122;
    constexpr int _124_RESERVED_FOR_PRIVATE_5 = 123;
    constexpr int _125_RESERVED_FOR_PRIVATE_6 = 124;
    constexpr int _126_RESERVED_FOR_PRIVATE_7 = 125;
    constexpr int _127_RESERVED_FOR_PRIVATE_8 = 126;
    constexpr int _128_MESSAGE_AUTH_CODE = 127;
}

namespace RESPONSE_CODES_1987
{
    constexpr std::string_view SUCCESSFUL = "00";
    constexpr std::string_view REFER_TO_CARD_ISSUER = "01";
    constexpr std::string_view REFER_TO_CARD_ISSUER_CONDITION = "02";
    constexpr std::string_view INVALID_MERCHANT = "03";
    constexpr std::string_view PICKUP = "04"; //swallows the card I believe
    constexpr std::string_view DO_NOT_HONOR = "05";
    constexpr std::string_view GENERAL_ERROR = "06";
    constexpr std::string_view PICKUP_CONDITION = "07";
    constexpr std::string_view HONOR_WITH_ID = "08";
    constexpr std::string_view REQUEST_IN_PROGRESS = "09";
    constexpr std::string_view PARTIAL_APPROVAL = "10";
    constexpr std::string_view VIP_APPROVAL = "11";
    constexpr std::string_view INVALID_TRANSACTION = "12";
    constexpr std::string_view INVALID_AMOUNT = "13"; //Currency conversion field overflow or amount exceeds max for card program
    constexpr std::string_view INVALID_ACCOUNT_NUMBER = "14"; //No such number
    constexpr std::string_view NO_SUCH_ISSUER = "15";
    constexpr std::string_view INSUFFICIENT_FUNDS = "16";
    constexpr std::string_view CUSTOMER_CANCELLATION = "17";
    constexpr std::string_view RE_ENTER_TRANSACTION = "19";
    constexpr std::string_view INVALID_RESPONSE = "20";
    constexpr std::string_view NO_ACTION_TAKEN = "21"; //unable to back out prior transaction
    constexpr std::string_view SUSPECTED_MALFUNCTION = "22";
    constexpr std::string_view UNABLE_TO_LOCATE_RECORD = "25";
    constexpr std::string_view FILE_IS_TEMPORARILY_UNAVAILABLE = "28";
    constexpr std::string_view FORMAT_ERROR = "30";
    constexpr std::string_view BANK_NOT_SUPPORTED = "31";
    constexpr std::string_view MERCHANT_SHOULD_RETAIN_CARD_LOST = "41";
    constexpr std::string_view MERCHANT_SHOULD_RETAIN_CARD_STOLEN = "43";
    constexpr std::string_view INSUFFICIENT_FUNDS_1 = "51";
    constexpr std::string_view NO_CHECKING_ACCOUNT = "52";
    constexpr std::string_view NO_SAVINGS_ACCOUNT = "53";
    constexpr std::string_view EXPIRED_CARD = "54";
    constexpr std::string_view INCORRECT_PIN = "55";
    constexpr std::string_view NO_CARD_RECORD = "56";
    constexpr std::string_view TRANSACTION_NOT_PERMITTED_TO_CARDHOLDER = "57";
    constexpr std::string_view TRANSACTION_NOT_ALLOWED_AT_TERMINAL = "58";
    constexpr std::string_view SUSPECTED_FRAUD = "59";
    constexpr std::string_view ACTIVITY_AMOUNT_LIMIT_EXCEEDED = "61";
    constexpr std::string_view RESTRICTED_CARD = "62"; //for example in country exclusion table
    constexpr std::string_view SECURITY_VIOLATION = "63";
    constexpr std::string_view ACTIVITY_AMOUNT_LIMIT_EXCEEDED_1 = "64";
    constexpr std::string_view RESPONSE_RECEIVED_TOO_LATE = "68";
    constexpr std::string_view ALLOWABLE_PIN_TRIES_EXCEEDED = "75";
    constexpr std::string_view UNABLE_TO_LOCATE_PREVIOUS_MESSAGE = "76"; //no match on RRN
    constexpr std::string_view REPEAT_OR_REVERSAL_DATA_IS_DIFFERENT = "77";
    constexpr std::string_view BLOCKED_FIRST_USED = "78"; //Transaction is from a new cardholder and the card has not been properly unlocked.
    constexpr std::string_view VISA_TRANSACTIONS_CREDIT_ISSUER_UNAVAILABLE = "80";
    constexpr std::string_view PIN_CRYPTO_ERROR_FOUND = "81";
    constexpr std::string_view NEGATIVE_CAM_CVV_RESULTS = "82";
    constexpr std::string_view UNABLE_TO_VERIFY_PIN = "83";
    constexpr std::string_view NO_REASON_TO_DECLINE = "85";
    constexpr std::string_view ISSUER_UNAVAILABLE_OR_SWITCH_INOPERATIVE = "91";
    constexpr std::string_view DESTINATION_CANNOT_BE_FOUND_FOR_ROUTING = "92";
    constexpr std::string_view TRANSACTION_CANNOT_BE_COMPLETED = "93"; //violation of law
    constexpr std::string_view DUPLICATE_TRANSMISSION = "94";
    constexpr std::string_view RECONCILE_ERROR = "95";
    constexpr std::string_view SYSTEM_MALFUNCTION = "96"; //or certain field error conditions
    constexpr std::string_view SURCHARGE_AMOUNT_NOT_PERMITTED_ON_VISA_CARDS = "B1"; //US Acquirers only
    constexpr std::string_view FORCE_STRIP = "N0";
    constexpr std::string_view CASH_SERVICE_NOT_AVAILABLE = "N3";
    constexpr std::string_view CASH_BACK_REQUEST_EXCEEDS_ISSUER_LIMIT = "N4";
    constexpr std::string_view DECLINE_FOR_CVV2_FAILURE = "N7";
    constexpr std::string_view INVALID_BILLING_INFO = "P2";
    constexpr std::string_view PIN_CHANGE_REQUEST_DECLINED = "P5";
    constexpr std::string_view UNSAFE_PIN = "P6";
    constexpr std::string_view CARD_AUTHENTICATION_FAILED = "Q1";
    constexpr std::string_view STOP_PAYMENT_ORDER = "R0";
    constexpr std::string_view REVOCATION_OF_AUTHORIZATION_ORDER = "R1";
    constexpr std::string_view REVOCATION_OF_ALL_AUTHORIZATIONS_ORDER = "R3";
    constexpr std::string_view FORWARD_TO_ISSUER = "XA";
    constexpr std::string_view FORWARD_TO_ISSUER_1 = "XD";
    constexpr std::string_view UNABLE_TO_GO_ONLINE = "Z3";
}

/*I'm lazy for now so no 1993 version yet...*/
namespace RESPONSE_CODES_1993
{

}
