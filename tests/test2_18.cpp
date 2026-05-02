#include "iotest.hpp"

int main() {
    test_num_array("5 3",   "3x3 2x2 1x1 1x1 4");
    test_num_array("13 5",  "5x5 5x5 3x3 2x2 1x1 1x1 6");
    test_num_array("8 8",   "8x8");
    test_num_array("12 4",  "4x4 4x4 4x4 3");
    test_num_array("11 40", "11x11 11x11 11x11 7x7 4x4 3x3 1x1 1x1 1x1 9");
    test_contains("-5 4",   "Ошибка");
    test_contains("5 -4",   "Ошибка");
}
