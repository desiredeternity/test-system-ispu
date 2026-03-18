#pragma once

#ifndef WINDOWS_H
#define WINDOWS_H

typedef int BOOL;
typedef unsigned int UINT;

BOOL SetConsoleOutputCP(UINT wCodePageID);
BOOL SetConsoleCP(UINT wCodePageID);
int win_system(const char* command);

#endif
