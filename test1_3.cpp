#include "iotest.hpp"

using namespace std;

void test1(string input, string expected) {
    test_num_array(input, expected);
}

void test2(string input, string expected) {
    test_exact(input, expected);
}

void test3(string input, string expected) {
    test_exact(input, expected);
}

void test4(string input, string expected) {
    test_num_array(input, expected);
}

void test5(string input, string expected) {
    test_exact(input, expected);
}

void test6(string input, string expected) {
    test_num_array(input, expected);
}

void test7(string input, string expected) {
    test_contains(input, expected);
}

int main() {
    test1("1 -5 4",  "-2 -1 1 2");
    test2("1 0 1",   "Корней нет");
    test3("1 0 0",   "0");
    test4("1 -3 2",  "-1.41421 -1 1 1.41421");
    test5("1 2 1",   "Корней нет");
    test6("-1 5 -6", "-1.73205 -1.41421 1.41421 1.73205");
    test7("0 1 2",   "Ошибка");

    return 0;
}
