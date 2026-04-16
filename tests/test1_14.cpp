#include "iotest.hpp"

int main() {
    test_exact("4 4 6 5",      "Один ход");
    test_exact("4 4 5 5",  {"6 3", "3 6"});
    test_exact("1 1 1 2",      "Нельзя попасть");
    test_exact("1 1 2 3",      "Один ход");
    test_exact("5 3 2 6",  {"3 4", "4 5"});
    test_contains("1 9 2 4",   "Ошибка");
}
