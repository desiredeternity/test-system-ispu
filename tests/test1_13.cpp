#include "iotest.hpp"

int main() {
    test_exact("0 0 2 0 2 2 0 2",             "Выпуклый");
    test_exact("0 0 3 0 1 2 3 3",             "Невыпуклый");
    test_exact("0 0 3.5 0.2 3.3 3.3 0.1 3.1", "Выпуклый");
    test_exact("0 0 4 0 1 1 0 4",             "Невыпуклый");
    test_exact("0 0 1 0 2 0 1 1",             "Выпуклый");
    test_exact("0 0 2 1 1 0 2 -1",            "Невыпуклый");
}
