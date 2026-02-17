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
    test_contains(input, expected);
}

int main() {
    test1("3 0 4 90 5 180",   "Нельзя построить треугольник");
    test2("5 0 5 120 5 240",  "Можно построить треугольник");
    test3("1 0 2 90 10 180",  "Нельзя построить треугольник");
    test4("3 30 4 30 5 30",   "Нельзя построить треугольник");
    test5("-5 0 5 120 5 240", "Ошибка");

    return 0;
}
