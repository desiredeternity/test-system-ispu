#include "iotest.hpp"

int main() {
    test_num_array("1", "3 = 2^2 - 1");
    test_num_array("2", "3 = 2^2 - 1, 7 = 2^3 - 1");
    test_num_array("6", "3 = 2^2 - 1, 7 = 2^3 - 1, 31 = 2^5 - 1, 127 = 2^7 - 1, 8191 = 2^13 - 1, 131071 = 2^17 - 1");
    test_contains("-1", "Ошибка");
}
