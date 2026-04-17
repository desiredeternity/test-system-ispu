#include "iotest.hpp"

int main() {
    test_contains("10",   {"1 и 3", "3 и 1"});
    test_exact("14",      "Нельзя представить");
    test_contains("34",   {"3 и 5", "5 и 3"});
    test_num_array("32",  "4 4");
    test_num_array("2",   "1 1");
    test_exact("1",       "Нельзя представить");
    test_exact("30",      "Нельзя представить");
    test_contains("8900", {"8 и 94", "34 и 88", "50 и 80", "80 и 50", "88 и 34", "94 и 8"});
    test_contains("-1",   "Ошибка");
}
