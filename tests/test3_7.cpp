#include "iotest.hpp"

int main() {
    test_num_array("3 1 2 3 4 5 6 7 8 9",                      "3 6 9 2 5 8 1 4 7", KEEP_ORDER);
    test_num_array("2 1 2 3 4",                                "2 4 1 3", KEEP_ORDER);
    test_num_array("4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16", "4 8 12 16 3 7 11 15 2 6 10 14 1 5 9 13", KEEP_ORDER);
    test_num_array("1 42",                                     "42", KEEP_ORDER);
    test_num_array("3 76 763473 -213 23774 222 -42 33 33 0",   "-213 -42 0 763473 222 33 76 23774 33", KEEP_ORDER);
    test_contains("-1",                                        "Ошибка", OPTIONAL);
}
