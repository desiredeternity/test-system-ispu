#include "iotest.hpp"

int main() {
    test_num_array("2 3 8 4 1 6",               "1 2");
    test_exact("2 4 6 1 2 3",                   "Бесконечно много решений");
    test_exact("2 4 6 1 2 4",                   "Нет решений");
    test_num_array("5 -3 7 -2 4 2",             "2.42857 1.71429");
    test_exact("0 0 0 0 0 0",                   "Бесконечно много решений");
    test_exact("0 1 2 0 2 5",                   "Нет решений");
    test_num_array("0.5 0.25 2.0 0.75 0.5 3.5", "2 4");
}
