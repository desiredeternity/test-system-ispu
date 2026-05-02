#include "iotest.hpp"

int main() {
    test_num_array("1",  "3 5");
    test_num_array("2",  "3 5 5 7");
    test_num_array("10", "3 5 5 7 11 13 17 19 29 31 41 43 59 61 71 73 101 103 107 109");
    test_contains("-1",  "Ошибка");
}
