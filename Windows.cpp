#include "Windows.h"
#include <cstring>
#include <cstdlib>

BOOL SetConsoleOutputCP(UINT wCodePageID) {
    return 1;
}

BOOL SetConsoleCP(UINT wCodePageID) {
    return 1;
}

int win_system(const char* command) {
    if (strcmp(command, "cls") == 0) {
        (system)("clear");
    }
    return 0;
}
