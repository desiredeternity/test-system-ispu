#include "iotest.hpp"

int main() {
    test_num_array("101",  "1 6 8 2 4 9 4 6 7");
    test_contains("7",     "Нельзя представить");
    test_num_array("14",   "1 2 3");
    test_num_array("3",    "1 1 1");
    test_contains("2",     "Нельзя представить");
    test_num_array("27",   "3 3 3 1 1 5");
    test_num_array("18",   "1 1 4");
    test_contains("100",   "Нельзя представить");
    test_num_array("5345", "2 21 70 4 48 55 6 50 53 8 41 60 10 22 69 10 42 59 11 18 70 15 32 64 27 46 50 28 31 60 32 36 55");
    test_contains("-1",    "Ошибка");
}
