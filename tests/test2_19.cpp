#include "iotest.hpp"

int main() {
    test_num_array("1 10 1",     "1 10");
    test_num_array("1 20 6",     "6 15");
    test_num_array("100 200 13", "139 148 157 166 175 184 193");
    test_num_array("1 1000 1",   "1 10 100 1000");
    test_num_array("1 1000 50",  "");
    test_contains("10 1 1",      {"Ошибка", "1 10"});
    test_contains("-5 10",       "Ошибка");
    test_contains("1 10 -5",     "Ошибка");
}
