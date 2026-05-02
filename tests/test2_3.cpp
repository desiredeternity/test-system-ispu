#include "iotest.hpp"

int main() {
    test_num_array("4",      "2 2");
    test_num_array("84",     "2 2 3 7");
    test_num_array("48",     "2 2 2 2 3");
    test_num_array("510510", "2 3 5 7 11 13 17");
    test_num_array("169",    "13 13");
    test_num_array("101",    "101");
    test_contains("0",       "Ошибка");
}
