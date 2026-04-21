#include "iotest.hpp"

int main() {
    test_exact("20",    "172");
    test_exact("1",     "172");
    test_exact("6",     "173");
    test_exact("15",    "171");
    test_exact("990",   "173");
    test_contains("-1", "Ошибка");
}
