#include "iotest.hpp"

int main() {
    test_num_array("XIV",       "14");
    test_contains("IIII",       "Число некорректно");
    test_num_array("MCMXCIV",   "1994");
    test_num_array("MMXXVI",    "2026");
    test_num_array("IX",        "9");
    test_num_array("MMMCMXCIX", "3999");
    test_num_array("I",         "1");
    test_num_array("III",       "3");
    test_num_array("IV",        "4");
    test_num_array("V",         "5");
    test_num_array("VIII",      "8");
    test_num_array("X",         "10");
    test_num_array("XL",        "40");
    test_num_array("XC",        "90");
    test_num_array("CD",        "400");
    test_num_array("CM",        "900");
    test_contains("VX",         "Число некорректно");
    test_contains("IC",         "Число некорректно");
    test_contains("IIV",        "Число некорректно");
    test_contains("XXXX",       "Число некорректно");
    test_contains("CCCC",       "Число некорректно");
    test_contains("VV",         "Число некорректно");
    test_contains("LL",         "Число некорректно");
    test_contains("DD",         "Число некорректно");
    test_contains("IC",         "Число некорректно");
    test_contains("IXC",        "Число некорректно");
    test_contains("MMMM",       "Ошибка");
    test_contains("A",          "Ошибка");
    test_contains("1",          "Ошибка");
}

/*
Ввод:
XIV
Вывод:
14

Ввод:
IIII
Вывод:
Число некорректно

В случае ввода некорректного римского числа необходимо сообщить о его некорректности, а в случае ввода данных, нарушающих условия задачи, программа должна выводить слово "Ошибка" и пояснить, что пошло не так.
*/
