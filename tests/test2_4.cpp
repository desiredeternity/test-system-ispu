#include "iotest.hpp"

int main() {
    test_num_array("10",   "1 и 3");
    test_exact("14",       "Нельзя представить");
    test_num_array("34",   "3 и 5");
    test_num_array("32",   "4 и 4");
    test_num_array("2",    "1 и 1");
    test_exact("1",        "Нельзя представить");
    test_exact("30",       "Нельзя представить");
    test_num_array("8900", {"8 и 94", "34 и 88", "50 и 80"});
    test_contains("-1",    "Ошибка");
}
