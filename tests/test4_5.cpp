#include "iotest.hpp"
#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void test(std::string input) {
    std::string result = run_with_input(input);
    std::vector<double> num_result = dfromstr(result);
    int num_input = std::stoi(input);

    if (num_result.size() == 2) {
        if (num_result[0] + num_result[1] == num_input && is_prime(num_result[0]) && is_prime(num_result[1])) {
            std::cout << "Тест: ПРОЙДЕН" << "\n";
        }
        else {
            std::cout << "Тест: ОШИБКА: " << result << " != " << input << " или числа не простые" << "\n"; 
        }
    }
    else {
        std::cout << "Тест: ОШИБКА: " << "получено не 2 числа. Число " << input << " удовлевторяет гипотезе. ";
        std::cout << "Получено '" << result << "'\n"; 
    }
}

int main() {
    test("4");
    test("10");
    test("28");
    test("100");
    test("512");
    test("12456");
    test("1000000");
    test("1232231212");
    test_contains("-1", "Ошибка");
    test_contains("15", "Ошибка");
}

/*
Ввод:
4
Вывод:
2 + 2

Ввод:
...
Вывод:
Число не удовлетворяет гипотезе Гольдбаха!

В случае ввода некорректного числа программа должна выводить слово "Ошибка" и пояснить, что пошло не так.
*/
