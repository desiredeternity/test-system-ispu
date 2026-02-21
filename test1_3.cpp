#include "iotest.hpp"

int main() {
    test_num_array("1 -5 4",  "-2 -1 1 2");
    test_exact("1 0 1",       "Корней нет");
    test_exact("1 0 0",       "0");
    test_num_array("1 -3 2",  "-1.41421 -1 1 1.41421");
    test_exact("1 2 1",       "Корней нет");
    test_num_array("-1 5 -6", "-1.73205 -1.41421 1.41421 1.73205");
    test_contains("0 1 2",    "Ошибка");

    return 0;
}
