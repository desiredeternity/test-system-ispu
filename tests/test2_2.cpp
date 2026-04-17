#include "iotest.hpp"

int main() {
    test_num_array("1 7",            "2 3 5 7");
    test_exact("8 10",               "В интервале нет простых чисел");
    test_num_array("50 100",         "53 59 61 67 71 73 79 83 89 97");
    test_num_array("2 2",            "2");
    test_num_array("999980 1000000", "999983");
    test_exact("6 6",                "В интервале нет простых чисел");
    test_num_array("-10 10",         "2 3 5 7");
    test_contains("10 1",            {"Ошибка", "2 3 5 7"});
}
