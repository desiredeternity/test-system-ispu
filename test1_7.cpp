#include "iotest.hpp"

int main() {
    test_exact("5",     "5 5 0 0 1.00");
    test_exact("19",    "20 0 1 0 3.70");
    test_exact("39",    "40 0 2 0 7.40");
    test_exact("300",   "300 0 15 0 55.50");
    test_exact("419",   "420 0 1 1 73.70");
    test_exact("435",   "435 15 1 1 76.70");
    test_exact("0",     "0 0 0 0 0.00");
    test_contains("-1", "Ошибка");

    return 0;
}
