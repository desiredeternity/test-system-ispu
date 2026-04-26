#include "iotest.hpp"

int main() {
    test_num_array("3 2  1 3 5 2 4",               "1 2 3 4 5", KEEP_ORDER);
    test_num_array("4 4  2 2 3 3 1 2 3 4",         "1 2 2 2 3 3 3 4", KEEP_ORDER);
    test_num_array("0 5  1 2 3 4 5",               "1 2 3 4 5", KEEP_ORDER);
    test_num_array("4 0  10 20 30 40",             "10 20 30 40", KEEP_ORDER);
    test_num_array("1 1  5 3",                     "3 5", KEEP_ORDER);
    test_num_array("3 4  -5 -2 1 -3 0 2 4",        "-5 -3 -2 0 1 2 4", KEEP_ORDER);
    test_num_array("4 4  1 1 2 2 3 3 4 5",         "1 1 2 2 3 3 4 5", KEEP_ORDER);
    test_num_array("5 1  -1.9 2.1 4.95 5 6.888 3", "-1.9 2.1 3 4.95 5 6.888", KEEP_ORDER);
    test_contains("-1 2  1 2",                     "Ошибка");
}
