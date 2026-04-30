#include "iotest.hpp"

int main() {
    test_num_array("5 5 3 3 8 6",                     "3 5 6 8", KEEP_ORDER);
    test_num_array("10 5 3 8 3 9 1 5 7 8 2",          "1 2 3 5 7 8 9", KEEP_ORDER);
    test_num_array("6 4 4 4 4 4 4",                   "4", KEEP_ORDER);
    test_num_array("7 10 20 30 40 50 60 70",          "10 20 30 40 50 60 70", KEEP_ORDER);
    test_num_array("10 -5 3 -2 0 -5 7 -2 1.7 3 -5.2", "-5.2 -5 -2 0 1.7 3 7", KEEP_ORDER);
    test_num_array("8 1 1 2 2 3 3 4 4",               "1 2 3 4", KEEP_ORDER);
    test_num_array("9 9 9 8 7 7 6 5 5 4",             "4 5 6 7 8 9", KEEP_ORDER);
    test_contains("-1",                               "Ошибка", OPTIONAL);
}
