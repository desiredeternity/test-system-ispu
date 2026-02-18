#include "iotest.hpp"

using namespace std;

int main() {
    test_exact("5 10 1582",    "15 10 1582");
    test_exact("1 3 1900",     "14 3 1900");
    test_exact("29 2 2000",    "13 3 2000");
    test_exact("1 1 2024",     "14 1 2024");
    test_exact("30 12 2023",   "12 1 2024");
    test_exact("1 3 2100",     "15 3 2100");
    test_exact("1 3 100",      "28 2 100");
    test_exact("1 1 1",        "-1 1 1");
    test_contains("1 13 1600", "Ошибка");
    test_contains("40 2 1500", "Ошибка");

    return 0;
}
