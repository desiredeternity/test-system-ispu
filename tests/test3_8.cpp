#include "iotest.hpp"

int main() {
    test_num_array("1 5",                  "c1 = 1 c0 = -5", KEEP_ORDER);
    test_num_array("2 1 4",                "c2 = 1 c1 = -5 c0 = 4", KEEP_ORDER);
    test_num_array("3 -2 -3 -4",           "c3 = 1 c2 = 9 c1 = 26 c0 = 24", KEEP_ORDER);
    test_num_array("4 0 1 -1 2",           "c4 = 1 c3 = -2 c2 = -1 c1 = 2 c0 = 0", KEEP_ORDER);
    test_num_array("5 0.5 -1.5 2.5 4 6.5", "c5 = 1 c4 = -12 c3 = 38.5 c2 = -3 c1 = -104.188 c0 = 48.75", KEEP_ORDER);
    test_num_array("6 2 2 2 2 2 2",        "c6 = 1 c5 = -12 c4 = 60 c3 = -160 c2 = 240 c1 = -192 c0 = 64", KEEP_ORDER);
    test_num_array("0 1",                  "Ошибка");
    test_contains("-1",                    "Ошибка");
}
