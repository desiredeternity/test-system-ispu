#include "iotest.hpp"

using namespace std;

void test1(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test2(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test3(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test4(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test5(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test6(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test7(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test8(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test9(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test10(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test11(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test12(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test13(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test14(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test15(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test16(string input, string expected_output) {
    test_exact(input, expected_output);
}

void test17(string input, string expected_output) {
    test_exact(input, expected_output);
}

int main() {
    test1("5 5 7",       "равнобедренный, остроугольный");
    test2("6 6 4",       "равнобедренный, остроугольный");
    test3("1 1 1.41421", "равнобедренный, прямоугольный");
    test4("2 2 3",       "равнобедренный, тупоугольный");
    test5("5 5 5",       "равносторонний, остроугольный");
    test6("0.7 0.7 0.7", "равносторонний, остроугольный");
    test7("3 4 6",       "разносторонний, тупоугольный");
    test8("4 5 6",       "разносторонний, остроугольный");
    test9("2.5 3.1 3.7", "разносторонний, остроугольный");
    test10("3 4 5",      "разносторонний, прямоугольный");
    test11("0 0 0",      "Нельзя построить");
    test12("0 4 5",      "Нельзя построить");
    test13("1 2 3",      "Нельзя построить");
    test14("5 1 2",      "Нельзя построить");
    test15("1 2 4",      "Нельзя построить");
    test16("-3 -4 -5",   "Нельзя построить");
    test17("-1 2 3",     "Нельзя построить");

    return 0;
}
