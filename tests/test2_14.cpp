#include "iotest.hpp"

int main() {
    test_exact("5 10",      "1/2");
    test_exact("12 4",      "3/1");
    test_exact("7 13",      "7/13");
    test_exact("100 25",    "4/1");
    test_exact("1 1",       "1/1");
    test_exact("210 315",   "2/3");
    test_exact("81 16",     "81/16");
    test_exact("1 1000000", "1/1000000");
    test_contains("5 0",    "Ошибка");
    test_contains("0 0",    "Ошибка");
    test_contains("0 5",    "Ошибка");
    test_contains("-5 10",  "Ошибка");
}
