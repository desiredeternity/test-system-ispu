#include "iotest.hpp"

int main() {
    test_num_array("3 3 5 6 7 4 5 6 3 8 9",                            "1 1 2 3", KEEP_ORDER);
    test_num_array("3 3 1 2 3 4 1 2 3 10 8",                           "", KEEP_ORDER);
    test_num_array("4 4 5 8 91 24 4 22 43 8 -1 4 -23 0 113 23 44 -14", "3 2", KEEP_ORDER);
    test_num_array("2 4 1 2 3 4 5 6 7 8",                              "1 4 2 1", KEEP_ORDER);
    test_num_array("3 3 5 5 5 5 5 5 5 5 5",                            "1 1 1 2 1 3 2 1 2 2 2 3 3 1 3 2 3 3", KEEP_ORDER);
    test_num_array("1 1 42",                                           "1 1", KEEP_ORDER);
    test_num_array("2 4 1 2 3 4 -5 6 7 8",                             "1 1 1 4", KEEP_ORDER);
    test_contains("-1",                                                "Ошибка");
    test_contains("2 -1",                                              "Ошибка");
}
