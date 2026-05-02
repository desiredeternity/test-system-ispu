#include "iotest.hpp"

int main() {
    test_num_array("1 3",       "1 2 3");
    test_num_array("150 160",   "153");
    test_num_array("1 200",     "1 2 3 4 5 6 7 8 9 153");
    test_num_array("100 500",   "153 370 371 407");
    test_num_array("100 120",   "");
    test_num_array("1 1000000", "1 2 3 4 5 6 7 8 9 153 370 371 407 1634 8208 9474 54748 92727 93084 548834");
    test_contains("3 1",        {"Ошибка", "1 2 3"});
}
