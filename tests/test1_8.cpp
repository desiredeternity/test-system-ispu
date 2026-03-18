#include "iotest.hpp"
#include <iostream>
#include <set>

int check_solution(std::string solution) {
    std::string digits_only;
    for (size_t i = 0; i < solution.length(); i++) {
        char c = solution[i];
        if (isdigit(c)) digits_only += c;
    }
    
    if (digits_only.length() != 5) return -1;
    
    std::vector<int> cells;
    for (size_t i = 0; i < digits_only.length(); i++) {
        char c = digits_only[i];
        int digit = c - '0';
        if (digit < 1 || digit > 8) return -1;
        cells.push_back(digit);
    }
    
    // Проверка уникальности
    std::set<int> unique_digits;
    for (size_t i = 0; i < cells.size(); i++) {
        unique_digits.insert(cells[i]);
    }
    if(unique_digits.size() != 5) return 1;
    
    // Проверка смежных пар
    int pairs[5][2] = {{0,1}, {0,2}, {1,2}, {2,3}, {2,4}};
    for (int i = 0; i < 5; i++) {
        if(std::abs(cells[pairs[i][0]] - cells[pairs[i][1]]) == 1) return 2;
    }
    
    return 0;
}



void test(std::string input) {
    std::string result = run_with_input(input);

    int c = check_solution(result);

    if (c == 0) std::cout << "Тест: " << "ПРОЙДЕН\n";
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        switch (c) {
            case -1:
                std::cout << "строка должна иметь 5 чисел 1-8, ";
                break;
            case 1:
                std::cout << "нарушена уникальность, ";
                break;
            case 2:
                std::cout << "найдены последовательные цифры, ";
                break;
        }
        std::cout << "получено \'" << result << "\', ";
        std::cout << "введено \'" << input << "\'\n";
    }
}

int main() {
    test("1");
    test("2");
    test("3");
    test("4");
    test("5");
    test("6");
    test("7");
    test("8");
    test_contains("9",  "Ошибка");
    test_contains("-1", "Ошибка");
}
