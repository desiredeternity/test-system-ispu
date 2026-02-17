#include "iotest.hpp"

using namespace std;

void test1(string input, string expected) {
    test_exact(input, expected);
}

void test2(string input, string expected) {
    test_exact(input, expected);
}

void test3(string input, string expected) {
    test_exact(input, expected);
}

void test4(string input, string expected) {
    test_exact(input, expected);
}

void test5(string input, string expected) {
    test_exact(input, expected);
}

void test6(string input, string expected) {
    test_exact(input, expected);
}

void test7(string input, string expected) {
    test_exact(input, expected);
}

void test8(string input, string expected) {
    test_exact(input, expected);
}

void test9(string input, string expected) {
    test_contains(input, expected);
}

void test10(string input, string expected) {
    test_contains(input, expected);
}

int main() {
    test1("5 10 1582",  "15 10 1582");
    test2("1 3 1900",   "14 3 1900");
    test3("29 2 2000",   "13 3 2000");
    test4("1 1 2024",  "14 1 2024");
    test5("30 12 2023",   "12 1 2024");
    test6("1 3 2100", "15 3 2100");
    test7("1 3 100",   "28 2 100");
    test8("1 1 1", "-1 1 1");
    test9("1 13 1600", "Ошибка");
    test10("40 2 1500", "Ошибка");

    return 0;
}
