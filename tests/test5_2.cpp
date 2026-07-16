#include "iotest.hpp"
#include <iostream>
#include <cstring>

int has_adjacent_duplicate(std::string seq) {
    int len = seq.length();
    for (int sublen = 1; sublen <= len / 2; sublen++) {
        for (int pos = 0; pos <= len - 2 * sublen; pos++) {
            int match = 1;
            for (int i = 0; i < sublen; i++) {
                if (seq[pos + i] != seq[pos + sublen + i]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                return 1;
            }
        }
    }
    return 0;
}

void test(std::string input) {
    std::string result = run_with_input(input);
    if (!has_adjacent_duplicate(result)) {
        std::cout << "Тест: " << PASSED << "\n";
    }
    else {
        std::cout << "Тест: " << ERROR << ":\n";
        std::cout << "получено: '" << result << "'\n";
        std::cout << "введено: '" << input << "'\n";
    }
}

int main() {
    test("11 0 1 2");
    test("7 a b c");
    test("20 0 1 2");
    test("30 a b c");
    test("50 0 1 2");
    test("30 3 4 5");
    test("30 x y z");
    test("2 0 1 2");
    test_contains("-1", "Ошибка");
}

/*
Ввод:
11
0 1 2
Вывод:
01020120210

Ввод:
7
abc
Вывод:
abacaba

В случае ввода некорректного числа программа должна выводить слово "Ошибка" и пояснить, что пошло не так.
*/
