#include "iotest.hpp"

int main() {
    test_num_array("0 0 4 0 4 4 0 4",                "2 2", KEEP_ORDER);
    test_num_array("0 0 6 0 6 3 0 3",                "3 1.5", KEEP_ORDER);
    test_num_array("0 1 2 0 4 1 2 2",                "2 1", KEEP_ORDER);
    test_num_array("1 1 5 2 6 6 2 5",                "3.5 3.5", KEEP_ORDER);
    test_num_array("0 0 5 0 4 3 1 3",                "2.5 1.875", KEEP_ORDER);
    test_num_array("-32.1 -2 0 0.5 15.32 -3 4 -4.9", "2.390625 -2.727343", KEEP_ORDER);
}

/*
Ввод:
0 0 4 0 4 4 0 4
Вывод:
2 2

Ввод:
0 0 6 0 6 3 0 3
Вывод:
3 1.5

Необходимо использовать вещественный тип данных с двойной точностью.
*/
