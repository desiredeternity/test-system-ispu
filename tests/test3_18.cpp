#include "iotest.hpp"

int main() {
    test_num_array("4 0 0 5 10 0 5 0 0 3 0 10 5",                      "1 2, 1 4", KEEP_ORDER);
    test_num_array("5 0 0 5 8 0 5 0 5 5 -3 0 4 10 10 3",               "1 2, 1 3, 1 4, 2 3, 3 4", KEEP_ORDER);
    test_num_array("3 0 0 10 0 0 5 12 0 1",                            "", KEEP_ORDER);
    test_num_array("3 0 0 10 5 0 5 0 15 5",                            "1 2, 1 3", KEEP_ORDER);
    test_num_array("3 0 0 5 0 0 5 2 2 5",                              "1 2, 1 3, 2 3", KEEP_ORDER);
    test_num_array("4 0 0 1 100 0 1 0 100 1 100 100 1",                "", KEEP_ORDER);
    test_num_array("6 0 0 10 15 0 8 -10 5 6 20 20 5 5 5 20 -15 -10 7", "1 2, 1 3, 3 5, 4 5, 5 6", KEEP_ORDER);
    test_contains("-1",                                                "Ошибка");
}

/*
Ввод:
4
0 0 5
10 0 5
0 0 3
0 10 5
Вывод:
1 2
1 4

В случае ввода некорректного числа программа должна выводить слово "Ошибка" и пояснить, что пошло не так.
*/
