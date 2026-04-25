#include "iotest.hpp"

int main() {
    test_contains("1000 1.5 55",   "1. 195.62");
    test_contains("1000 1.5 55",   "1443.22");
    test_contains("1000 1.5 55",   "42. 296962.75");
    test_contains("1000 1.5 55",   "10938501.25");
    test_contains("1000 1.5 55",   "1856735.84");
    test_contains("256.56 2 8",    "1460.58");
    test_contains("256.56 2 8",    "7. 286.37");
    test_contains("56000 2.75 20", "1. 21547.89");
    test_contains("56000 2.75 20", "1166971.26");
    test_contains("56000 2.75 20", "37599408.08");
    test_contains("-10 1 1",       "Ошибка");
    test_contains("1 -10 1",       "Ошибка");
    test_contains("1 1 -10",       "Ошибка");
}
