#include "iotest.hpp"
#include <iostream>

void test1(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if (result.find("зел") != std::string::npos && result.find("крыс") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test2(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if (result.find("бел") != std::string::npos && result.find("зме") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test3(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if ((result.find("жел") != std::string::npos || result.find("жёл") != std::string::npos)
      && result.find("крыс") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test4(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if (result.find("зел") != std::string::npos && result.find("свин") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test5(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if ((result.find("чер") != std::string::npos || result.find("чёр") != std::string::npos)
      && result.find("обез") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

void test6(std::string input, std::string expected) {
    std::string result = run_with_input(input);

    if (result.find("зел") != std::string::npos && result.find("крыс") != std::string::npos) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "ожидалось \'" << expected << "\', ";
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
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
