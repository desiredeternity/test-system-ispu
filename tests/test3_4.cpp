#include "iotest.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Проверка, является ли решётка правильной
bool isCorrectLattice(const std::vector<std::vector<int>>& lattice) {
    const int N = 10;
    
    if (lattice.size() != N) return false;
    for (int i = 0; i < N; ++i) {
        if (lattice[i].size() != N) return false;
    }
    
    // Для каждой клетки проверяем группу из 4 симметричных
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            // Вычисляем 4 симметричные позиции
            int i1 = i, j1 = j;
            int i2 = j, j2 = N - 1 - i;
            int i3 = N - 1 - i, j3 = N - 1 - j;
            int i4 = N - 1 - j, j4 = i;
            
            // Собираем значения из этих 4 позиций
            std::vector<int> group = {
                lattice[i1][j1],
                lattice[i2][j2],
                lattice[i3][j3],
                lattice[i4][j4]
            };
            
            // Считаем количество нулей (прорезей)
            int zeroCount = std::count(group.begin(), group.end(), 0);
            
            // Должен быть ровно один ноль
            if (zeroCount != 1) {
                return false;
            }
        }
    }
    
    return true;
}

// Преобразование строки в матрицу 10x10
std::vector<std::vector<int>> parseLatticeFromString(const std::string& str) {
    const int N = 10;
    std::vector<std::vector<int>> lattice(N, std::vector<int>(N, 0));
    
    std::vector<double> numbers = dfromstr(str);
    
    // Заполняем матрицу (ожидаем ровно 100 чисел)
    for (size_t i = 0; i < numbers.size() && i < N * N; ++i) {
        int row = i / N;
        int col = i % N;
        lattice[row][col] = static_cast<int>(numbers[i]);
    }
    
    return lattice;
}

void test(std::string input) {
    std::string result = run_with_input(input);
    std::vector<std::vector<int>> userLattice = parseLatticeFromString(result);
    
    if (isCorrectLattice(userLattice)) {
        std::cout << "Тест: " << "ПРОЙДЕН\n";
    }
    else {
        std::cout << "Тест: " << "ОШИБКА: ";
        std::cout << "Решётка не соответствует условию\n";
    }
}

int main() {
    test("");
}
