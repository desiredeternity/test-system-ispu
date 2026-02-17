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
    test_exact(input, expected);
}

void test10(string input, string expected) {
    test_exact(input, expected);
}

void test11(string input, string expected) {
    test_exact(input, expected);
}

void test12(string input, string expected) {
    test_exact(input, expected);
}

void test13(string input, string expected) {
    test_exact(input, expected);
}

void test14(string input, string expected) {
    test_exact(input, expected);
}

void test15(string input, string expected) {
    test_exact(input, expected);
}

void test16(string input, string expected) {
    test_exact(input, expected);
}

void test17(string input, string expected) {
    test_exact(input, expected);
}

void test18(string input, string expected) {
    test_exact(input, expected);
}

int main() {
    test1("1 0 5 0 1 3",     "5 3");
    test2("1 2 3 1 0 0",     "0 1.5");
    test3("2 -1 1 1 1 4",    "1.66667 2.33333");
    test4("0 1 4 1 0 -2",    "-2 4");
    test5("1 2 3 1 2 5",     "Прямые не пересекаются");
    test6("2 4 6 1 2 4",     "Прямые не пересекаются");
    test7("0 1 3 0 1 7",     "Прямые не пересекаются");
    test8("1 0 2 1 0 5",     "Прямые не пересекаются");
    test9("1 2 3 2 4 6",     "Прямые совпадают");
    test10("0 1 3 0 2 5",    "Прямые совпадают");
    test11("1 0 5 3 0 15",   "Прямые совпадают");
    test12("0 0 0 0 0 0",    "Прямые совпадают");
    test13("0 0 5 1 2 3",    "Прямые не существуют");
    test14("1 2 3 0 0 7",    "Прямые не существуют");
    test15("0 0 5 0 0 7",    "Прямые не существуют");
    test16("-1 2 -3 2 -4 6", "Прямые совпадают");
    test17("0 2 4 0 -1 2",   "Прямые совпадают");
    test18("0 0 0 1 2 3",    "1x + 2y = 3");

    return 0;
}
