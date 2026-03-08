#include "msvc_compat.hpp"
#include <cstring>
#include <cstdarg>
#include <cerrno>

static size_t safe_strlen(const char* str, rsize_t max_len) {
    if (!str) return 0;
    size_t len = 0;
    while (len < max_len && str[len] != '\0') {
        len++;
    }
    return len;
}

errno_t strcpy_s(char* dest, rsize_t dest_size, const char* src) {
    if (!dest || !src || dest_size == 0 || dest_size > RSIZE_MAX) {
        if (dest && dest_size > 0) dest[0] = '\0';
        return EINVAL;
    }
    
    size_t src_len = safe_strlen(src, dest_size);
    if (src_len >= dest_size) {
        dest[0] = '\0';
        return ERANGE;
    }
    
    memcpy(dest, src, src_len + 1);
    return 0;
}

errno_t strcat_s(char* dest, rsize_t dest_size, const char* src) {
    if (!dest || !src || dest_size == 0 || dest_size > RSIZE_MAX) {
        return EINVAL;
    }

    size_t dest_len = safe_strlen(dest, dest_size);
    if (dest_len >= dest_size) {
        return EINVAL;
    }
    
    size_t available = dest_size - dest_len;
    size_t src_len = safe_strlen(src, available);
    
    if (src_len >= available) {
        return ERANGE;
    }
    
    memcpy(dest + dest_len, src, src_len + 1);
    return 0;
}

errno_t strncpy_s(char* dest, rsize_t dest_size, const char* src, rsize_t count) {
    if (!dest || !src || dest_size == 0 || dest_size > RSIZE_MAX || count > RSIZE_MAX) {
        if (dest && dest_size > 0) dest[0] = '\0';
        return EINVAL;
    }
    
    size_t src_len = safe_strlen(src, count);
    size_t copy_len = (src_len < count) ? src_len : count;
    
    if (copy_len >= dest_size) {
        dest[0] = '\0';
        return ERANGE;
    }
    
    memcpy(dest, src, copy_len);
    
    if (src_len < count) {
        memset(dest + copy_len, 0, dest_size - copy_len);
    } else {
        dest[copy_len] = '\0';
    }
    
    return 0;
}

errno_t strncat_s(char* dest, rsize_t dest_size, const char* src, rsize_t count) {
    if (!dest || !src || dest_size == 0 || dest_size > RSIZE_MAX || count > RSIZE_MAX) {
        return EINVAL;
    }
    
    size_t dest_len = safe_strlen(dest, dest_size);
    if (dest_len >= dest_size) {
        return EINVAL;
    }
    
    size_t available = dest_size - dest_len;
    size_t src_len = safe_strlen(src, count);
    size_t copy_len = (src_len < count) ? src_len : count;
    
    if (copy_len >= available) {
        return ERANGE;
    }
    
    memcpy(dest + dest_len, src, copy_len);
    dest[dest_len + copy_len] = '\0';
    return 0;
}

int scanf_s(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int result = vscanf(format, args);
    
    va_end(args);
    return result;
}

int printf_s(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);
    return result;
}

int sprintf_s(char* buffer, rsize_t buffer_size, const char* format, ...) {
    if (!buffer || buffer_size == 0 || buffer_size > RSIZE_MAX || !format) {
        if (buffer && buffer_size > 0) buffer[0] = '\0';
        return -1;
    }
    
    va_list args;
    va_start(args, format);

    int result = vsnprintf(buffer, buffer_size, format, args);
    
    va_end(args);
    
    if (result < 0 || (size_t)result >= buffer_size) {
        buffer[buffer_size - 1] = '\0';
        return -1;
    }
    
    return result;
}

int sscanf_s(const char* buffer, const char* format, ...) {
    if (!buffer || !format) return -1;
    
    va_list args;
    va_start(args, format);
    
    int result = vsscanf(buffer, format, args);
    
    va_end(args);
    return result;
}

int fprintf_s(FILE* stream, const char* format, ...) {
    if (!stream || !format) return -1;
    
    va_list args;
    va_start(args, format);
    int result = vfprintf(stream, format, args);
    va_end(args);
    return result;
}

int fscanf_s(FILE* stream, const char* format, ...) {
    if (!stream || !format) return -1;
    
    va_list args;
    va_start(args, format);
    int result = vfscanf(stream, format, args);
    va_end(args);
    return result;
}

errno_t fopen_s(FILE** stream, const char* filename, const char* mode) {
    if (!stream || !filename || !mode) {
        return EINVAL;
    }
    
    *stream = fopen(filename, mode);
    if (!*stream) {
        return errno;
    }
    
    return 0;
}

errno_t freopen_s(FILE** newStream, const char* filename, const char* mode, FILE* stream) {
    if (!newStream || !mode || !stream) {
        return EINVAL;
    }
    
    *newStream = freopen(filename, mode, stream);
    if (!*newStream) {
        return errno;
    }
    
    return 0;
}

char* gets_s(char* buffer, rsize_t buffer_size) {
    if (!buffer || buffer_size == 0 || buffer_size > RSIZE_MAX) {
        return NULL;
    }
    
    if (fgets(buffer, (int)buffer_size, stdin) == NULL) {
        buffer[0] = '\0';
        return NULL;
    }
    
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    
    return buffer;
}

errno_t memcpy_s(void* dest, rsize_t dest_size, const void* src, rsize_t count) {
    if (!dest || !src || dest_size > RSIZE_MAX || count > RSIZE_MAX) {
        return EINVAL;
    }
    
    if (count > dest_size) {
        return ERANGE;
    }

    if (dest < src) {
        char* d = (char*)dest;
        const char* s = (const char*)src;
        if (d + count > s) {
            return EINVAL;
        }
    } else if (dest > src) {
        char* d = (char*)dest;
        const char* s = (const char*)src;
        if (s + count > d) {
            return EINVAL;
        }
    }
    
    memcpy(dest, src, count);
    return 0;
}

errno_t memmove_s(void* dest, rsize_t dest_size, const void* src, rsize_t count) {
    if (!dest || !src || dest_size > RSIZE_MAX || count > RSIZE_MAX) {
        return EINVAL;
    }
    
    if (count > dest_size) {
        return ERANGE;
    }
    
    memmove(dest, src, count);
    return 0;
}
