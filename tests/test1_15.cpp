#include "iotest.hpp"

int main() {
    test_exact("1",   "1");
    test_exact("180", "9");
    test_exact("18",  "8");
    test_exact("114", "6");
    test_exact("176", "7");
    test_contains("0", "Ошибка");
}
