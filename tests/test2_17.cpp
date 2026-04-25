#include "iotest.hpp"

int main() {
    test_num_array("6",        "2 3");
    test_num_array("8",        "2");
    test_num_array("3",        "3");
    test_num_array("1",        "");
    test_num_array("34",       "2 17");
    test_num_array("84",       "2 3 7");
    test_num_array("6764",     "2 19 89");
    test_num_array("68768758", "2 23 1494973");
    test_contains("0",         "Ошибка");
}
