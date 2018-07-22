#include "string.h"

int strncasecmp(const char *s1, const char *s2, size_t len) {
    /* Yes, Virginia, it had better be unsigned */
    unsigned char c1, c2;

    if (!len)
        return 0;

    do {
        c1 = *s1++;
        c2 = *s2++;
        if (!c1 || !c2)
            break;
        if (c1 == c2)
            continue;
        c1 = tolower(c1);
        c2 = tolower(c2);
        if (c1 != c2)
            break;
    } while (--len);
    return (int)c1 - (int)c2;
}

int strcasecmp(const char *s1, const char *s2) {
    int c1, c2;

    do {
        c1 = tolower(*s1++);
        c2 = tolower(*s2++);
    } while (c1 == c2 && c1 != 0);
    return c1 - c2;
}

char *strcpy(char *dest, const char *src) {
    char *tmp = dest;

    while ((*dest++ = *src++) != '\0')
        /* nothing */;
    return tmp;
}

char *strncpy(char *dest, const char *src, size_t count) {
    char *tmp = dest;

    while (count) {
        if ((*tmp = *src) != 0)
            src++;
        tmp++;
        count--;
    }
    return dest;
}

size_t strlcpy(char *dest, const char *src, size_t size) {
    size_t ret = strlen(src);

    if (size) {
        size_t len = (ret >= size) ? size - 1 : ret;
        memcpy(dest, src, len);
        dest[len] = '\0';
    }
    return ret;
}

char *strcat(char *dest, const char *src) {
    char *tmp = dest;

    while (*dest)
        dest++;
    while ((*dest++ = *src++) != '\0')
        ;
    return tmp;
}

char *strncat(char *dest, const char *src, size_t count) {
    char *tmp = dest;

    if (count) {
        while (*dest)
            dest++;
        while ((*dest++ = *src++) != 0) {
            if (--count == 0) {
                *dest = '\0';
                break;
            }
        }
    }
    return tmp;
}

size_t strlcat(char *dest, const char *src, size_t count) {
    size_t dsize = strlen(dest);
    size_t len = strlen(src);
    size_t res = dsize + len;

    dest += dsize;
    count -= dsize;
    if (len >= count)
        len = count-1;
    memcpy(dest, src, len);
    dest[len] = 0;
    return res;
}

int strcmp(const char *cs, const char *ct) {
    unsigned char c1, c2;

    while (1) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (!c1)
            break;
    }
    return 0;
}

int strncmp(const char *cs, const char *ct, size_t count) {
    unsigned char c1, c2;

    while (count) {
        c1 = *cs++;
        c2 = *ct++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (!c1)
            break;
        count--;
    }
    return 0;
}

char *strchr(const char *s, int c) {
    for (; *s != (char)c; ++s)
        if (*s == '\0')
            return NULL;
    return (char *)s;
}

char *strchrnul(const char *s, int c) {
    while (*s && *s != (char)c)
        s++;
    return (char *)s;
}

char *strrchr(const char *s, int c) {
    const char *last = NULL;
    do {
        if (*s == (char)c)
            last = s;
    } while (*s++);
    return (char *)last;
}

char *strnchr(const char *s, size_t count, int c) {
    for (; count-- && *s != '\0'; ++s)
        if (*s == (char)c)
            return (char *)s;
    return NULL;
}

char *skip_spaces(const char *str) {
    while (isspace(*str))
        ++str;
    return (char *)str;
}

char *strim(char *s) {
    size_t size;
    char *end;

    size = strlen(s);
    if (!size)
        return s;

    end = s + size - 1;
    while (end >= s && isspace(*end))
        end--;
    *(end + 1) = '\0';

    return skip_spaces(s);
}

size_t strlen(const char *s) {
    const char *sc;

    for (sc = s; *sc != '\0'; ++sc)
        /* nothing */;
    return sc - s;
}

size_t strnlen(const char *s, size_t count) {
    const char *sc;

    for (sc = s; count-- && *sc != '\0'; ++sc)
        /* nothing */;
    return sc - s;
}

size_t strspn(const char *s, const char *accept) {
    const char *p;
    const char *a;
    size_t count = 0;

    for (p = s; *p != '\0'; ++p) {
        for (a = accept; *a != '\0'; ++a) {
            if (*p == *a)
                break;
        }
        if (*a == '\0')
            return count;
        ++count;
    }
    return count;
}

size_t strcspn(const char *s, const char *reject) {
    const char *p;
    const char *r;
    size_t count = 0;

    for (p = s; *p != '\0'; ++p) {
        for (r = reject; *r != '\0'; ++r) {
            if (*p == *r)
                return count;
        }
        ++count;
    }
    return count;
}

char *strpbrk(const char *cs, const char *ct) {
    const char *sc1, *sc2;

    for (sc1 = cs; *sc1 != '\0'; ++sc1) {
        for (sc2 = ct; *sc2 != '\0'; ++sc2) {
            if (*sc1 == *sc2)
                return (char *)sc1;
        }
    }
    return NULL;
}

char *strsep(char **s, const char *ct) {
    char *sbegin = *s;
    char *end;

    if (sbegin == NULL)
        return NULL;

    end = strpbrk(sbegin, ct);
    if (end)
        *end++ = '\0';
    *s = end;
    return sbegin;
}

bool sysfs_streq(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }

    if (*s1 == *s2)
        return true;
    if (!*s1 && *s2 == '\n' && !s2[1])
        return true;
    if (*s1 == '\n' && !s1[1] && !*s2)
        return true;
    return false;
}

int match_string(const char *const *array, size_t n, const char *string) {
    int index;
    const char *item;

    for (index = 0; index < n; index++) {
        item = array[index];
        if (!item)
            break;
        if (!strcmp(item, string))
            return index;
    }

    return -EINVAL;
}

int __sysfs_match_string(const char *const *array, size_t n, const char *str) {
    const char *item;
    int index;

    for (index = 0; index < n; index++) {
        item = array[index];
        if (!item)
            break;
        if (sysfs_streq(item, str))
            return index;
    }

    return -EINVAL;
}

void *memset(void *s, int c, size_t count) {
    char *xs = s;

    while (count--)
        *xs++ = c;
    return s;
}

void memzero_explicit(void *s, size_t count) {
    memset(s, 0, count);
}

void *memset16(uint16_t *s, uint16_t v, size_t count) {
    uint16_t *xs = s;

    while (count--)
        *xs++ = v;
    return s;
}

void *memset32(uint32_t *s, uint32_t v, size_t count) {
    uint32_t *xs = s;

    while (count--)
        *xs++ = v;
    return s;
}

void *memset64(uint64_t *s, uint64_t v, size_t count) {
    uint64_t *xs = s;

    while (count--)
        *xs++ = v;
    return s;
}

void *memcpy(void *dest, const void *src, size_t count) {
    char *tmp = dest;
    const char *s = src;

    while (count--)
        *tmp++ = *s++;
    return dest;
}

void *memmove(void *dest, const void *src, size_t count) {
    char *tmp;
    const char *s;

    if (dest <= src) {
        tmp = dest;
        s = src;
        while (count--)
            *tmp++ = *s++;
    } else {
        tmp = dest;
        tmp += count;
        s = src;
        s += count;
        while (count--)
            *--tmp = *--s;
    }
    return dest;
}

int memcmp(const void *cs, const void *ct, size_t count) {
    const unsigned char *su1, *su2;
    int res = 0;

    for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
        if ((res = *su1 - *su2) != 0)
            break;
    return res;
}

void *memscan(void *addr, int c, size_t size) {
    unsigned char *p = addr;

    while (size) {
        if (*p == c)
            return (void *)p;
        p++;
        size--;
    }
    return (void *)p;
}

char *strstr(const char *s1, const char *s2) {
    size_t l1, l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;
    l1 = strlen(s1);
    while (l1 >= l2) {
        l1--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }
    return NULL;
}

char *strnstr(const char *s1, const char *s2, size_t len) {
    size_t l2;

    l2 = strlen(s2);
    if (!l2)
        return (char *)s1;
    while (len >= l2) {
        len--;
        if (!memcmp(s1, s2, l2))
            return (char *)s1;
        s1++;
    }
    return NULL;
}

void *memchr(const void *s, int c, size_t n) {
    const unsigned char *p = s;
    while (n-- != 0) {
        if ((unsigned char)c == *p++) {
            return (void *)(p - 1);
        }
    }
    return NULL;
}

void *memchr_inv(const void *start, int c, size_t bytes) {
    uint8_t value = c;
    uint64_t value64;
    unsigned int words, prefix;

    if (bytes <= 16)
        return check_bytes8(start, value, bytes);

    value64 = value;
#if defined(CONFIG_ARCH_HAS_FAST_MULTIPLIER) && BITS_PER_LONG == 64
    value64 *= 0x0101010101010101ULL;
#elif defined(CONFIG_ARCH_HAS_FAST_MULTIPLIER)
    value64 *= 0x01010101;
	value64 |= value64 << 32;
#else
    value64 |= value64 << 8;
    value64 |= value64 << 16;
    value64 |= value64 << 32;
#endif

    prefix = (unsigned long)start % 8;
    if (prefix) {
        uint8_t *r;

        prefix = 8 - prefix;
        r = check_bytes8(start, value, prefix);
        if (r)
            return r;
        start += prefix;
        bytes -= prefix;
    }

    words = bytes / 8;

    while (words) {
        if (*(uint64_t *)start != value64)
            return check_bytes8(start, value, 8);
        start += 8;
        words--;
    }

    return check_bytes8(start, value, bytes % 8);
}

void *check_bytes8(const uint8_t *start, uint8_t value, unsigned int bytes) {
    while (bytes) {
        if (*start != value)
            return (void *)start;
        start++;
        bytes--;
    }
    return NULL;
}

char *strreplace(char *s, char old, char new) {
    for (; *s; ++s)
        if (*s == old)
            *s = new;
    return s;
}
