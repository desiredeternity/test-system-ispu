#include "iotest.hpp"

int main() {
    test_num_array("2 5",        "32");
    test_num_array("-2 5",       "-32");
    test_num_array("-4.5 8",     "168151");
    test_num_array("50 20",      "9.53674e+33");
    test_num_array("-45.324 15", "-6.99719e+24");
    test_contains("2 -1",        "Ошибка");
    test_contains("0 0",         "Ошибка");
}
