#include "iotest.hpp"

int main() {
    test_exact("0 0 4 0 0 3",             "4 3");
    test_exact("2 3 7 3 2 8",             "7 8");
    test_exact("0 0 0 5 5 0",             "5 5");
    test_exact("-2 -2 -2 3 4 -2",         "4 3");
    test_exact("1.5 2.5 1.5 5.5 4.5 2.5", "4.5 5.5");
    test_contains("0 0 1 1 2 2",          "Ошибка");
}
