#include "iotest.hpp"

int main() {
    test_num_array("1 -5 1 1 4 1",              "c2 = 1 c1 = -1 c0 = -20");
    test_num_array("0 5 0 3",                   "c0 = 15");
    test_num_array("2 1 -3 2 1 2 3",            "c3 = 6 c2 = -5 c1 = -3 c0 = 2");
    test_num_array("3 1 0 -2 1 0 1",            "c3 = 1 c2 = -2 c1 = 0 c0 = 1");
    test_num_array("3 4 3 2 1 3 1 1 1 1",       "c6 = 1 c5 = 3 c4 = 6 c3 = 10 c2 = 9 c1 = 7 c0 = 4");
    test_num_array("2 -4 3 1 0 0",              "c2 = 0 c1 = 0 c0 = 0");
    test_num_array("2 -2 1.5 0.5 1 -0.75 0.25", "c3 = 0.125 c2 = 0 c1 = -1.625 c0 = 1.5");
    test_num_array("5 6 5 4 3 2 1 3 4 3 2 1",   "c8 = 1 c7 = 4 c6 = 10 c5 = 20 c4 = 30 c3 = 40 c2 = 43 c1 = 38 c0 = 24");
    test_contains("-1",                         "Ошибка");
    test_contains("1 1 2 -1",                   "Ошибка");
}
