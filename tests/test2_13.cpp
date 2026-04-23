#include "iotest.hpp"

int main() {
    test_exact("12 18",                 "6");
    test_exact("25 0",                  "25");
    test_exact("48 18",                 "6");
    test_exact("100 100",               "100");
    test_exact("1071 462",              "21");
    test_exact("123456 7890",           "6");
    test_exact("360 840",               "120");
    test_exact("2147483647 2147483646", "1");
    test_exact("999999 333333",         "333333");
    test_contains("0 0",                "Ошибка");
    test_contains("-5 10",              "Ошибка");
}
