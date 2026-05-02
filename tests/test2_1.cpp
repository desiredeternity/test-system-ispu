#include "iotest.hpp"

int main() {
    test_num_array("3",  "0 0 1 1 5 25");
    test_num_array("5",  "0 0 1 1 5 25 6 36 25 625");
    test_num_array("10", "0 0 1 1 5 25 6 36 25 625 76 5776 376 141376 625 390625 9376 87909376 90625 8212890625");
    test_contains("-1",  "Ошибка");
}
