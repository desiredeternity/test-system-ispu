#ifndef MSVC_COMPAT_HPP
#define MSVC_COMPAT_HPP

#include <cstdio>

typedef int errno_t;
typedef size_t rsize_t;

#ifdef __cplusplus
extern "C" {
#endif

errno_t strcpy_s(char* dest, rsize_t dest_size, const char* src);
errno_t strcat_s(char* dest, rsize_t dest_size, const char* src);
errno_t strncpy_s(char* dest, rsize_t dest_size, const char* src, rsize_t count);
errno_t strncat_s(char* dest, rsize_t dest_size, const char* src, rsize_t count);

int scanf_s(const char* format, ...);
int printf_s(const char* format, ...);
int sprintf_s(char* buffer, rsize_t buffer_size, const char* format, ...);
int sscanf_s(const char* buffer, const char* format, ...);
int fprintf_s(FILE* stream, const char* format, ...);
int fscanf_s(FILE* stream, const char* format, ...);

errno_t fopen_s(FILE** stream, const char* filename, const char* mode);
errno_t freopen_s(FILE** newStream, const char* filename, const char* mode, FILE* stream);

char* gets_s(char* buffer, rsize_t buffer_size);

errno_t memcpy_s(void* dest, rsize_t dest_size, const void* src, rsize_t count);
errno_t memmove_s(void* dest, rsize_t dest_size, const void* src, rsize_t count);

#ifdef __cplusplus
}
#endif

#endif
