#include "iotest.hpp"
#include <iostream>

using namespace std;

void test1(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("зел") != string::npos && result.find("крыс") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test2(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("бел") != string::npos && result.find("зме") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test3(string input, string expected) {
    string result = run_with_input(input);

    if ((result.find("жел") != string::npos || result.find("жёл") != string::npos)
      && result.find("крыс") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test4(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("зел") != string::npos && result.find("свин") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test5(string input, string expected) {
    string result = run_with_input(input);

    if ((result.find("чер") != string::npos || result.find("чёр") != string::npos)
      && result.find("обез") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

void test6(string input, string expected) {
    string result = run_with_input(input);

    if (result.find("зел") != string::npos && result.find("крыс") != string::npos) {
        cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        cout << "Тест: " << "ОШИБКА: ";
        cout << "ожидалось \'" << expected << "\', ";
        cout << "получено \'" << result << "\', ";
        cout << "введено \'" << input << "\'\n";
    }
}

int main() {
    test1("1984", "Год зеленой крысы");
    test2("1785", "Год белой змеи");
    test3("1996", "Год желтой крысы");
    test4("1995", "Год зеленой свиньи");
    test5("0",    "Год черной обезьяны");
    test6("2044", "Год зеленой крысы");
    test_contains("-1",   "Ошибка");

    return 0;
}
