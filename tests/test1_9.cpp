#include "iotest.hpp"

int main() {
    test_exact("0 0 2 0 1 0 -1",                "Верно");
    test_exact("0 0 0 2 0 1 -3",                "Не верно");
    test_exact("0 1 1 0 1 -1 0",                "Верно");
    test_exact("-5 10 3 7 2 0 6",               "Верно");
    test_exact("-1 8 2 10 0 1 -5",              "Не верно");
    test_exact("-2 -1 4 3 0 3 -6",              "Верно");
    test_exact("1.5 2.3 -0.7 1.8 0.5 -1.2 2.7", "Не верно");
    test_contains("0 3 2 4 1 0 -2",             "Ошибка");
    test_contains("0 0 1 1 0 0 5",              "Ошибка");
}
