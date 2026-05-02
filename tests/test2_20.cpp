#include "iotest.hpp"
#include "iostream"

void test(std::string input) {
    std::string result = run_with_input(input);
    int num_input = std::stoi(input);
    std::vector<double> num_result = dfromstr(result);

    int sum = 0;
    for (size_t i = 0; i < num_result.size(); i++) {
        sum = sum + num_result[i] * num_result[i];
    }

    if (sum == num_input && num_result.size() == 4) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        for (size_t i = 0; i < num_result.size(); i++) {
            std::cout << num_result[i] << " * " << num_result[i];
            if (i + 1 != num_result.size()) std::cout << " + ";
        }
        std::cout << " != " << num_input << std::endl;
    }
}

int main() {
    test("1");
    test("15");
    test("2");
    test("3");
    test("23");
    test("79");
    test("1000");
    test_contains("-5", "Ошибка");
}
