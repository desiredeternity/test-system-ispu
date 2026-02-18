#include "iotest.hpp"

using namespace std;

int main() {
    test_exact("3 0 4 90 5 180",      "Нельзя построить треугольник");
    test_exact("5 0 5 120 5 240",     "Можно построить треугольник");
    test_exact("1 0 2 90 10 180",     "Нельзя построить треугольник");
    test_exact("3 30 4 30 5 30",      "Нельзя построить треугольник");
    test_contains("-5 0 5 120 5 240", "Ошибка");

    return 0;
}
