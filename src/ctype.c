//
// Created by root on 5/10/18.
//

#include "ctype.h"

int isalnum(int c) {
    return (isalpha(c) || isdigit(c));
}

int isalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int islower(int c) {
    return (c >= 'a' && c <= 'z');
}

int isblank(int c) {
    return (c == ' ' || c == '\t');
}

int iscntrl(int c) {
    return (c == 127 || (c >= 0 && c <= 31));
}

int isdigit(int c) {
    return (c >= '0' && c <= '9');
}

int isgraph(int c) {
    return (isprint(c) && c != ' ');
}

int isprint(int c) {
    return (c >= 0x20 && c <= 0x7E);
}

int ispunct(int c) {
    return (isprint(c) && !isspace(c) && !isalnum(c));
}

int isspace(int c) {
    return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}

int isupper(int c) {
    return (c >= 'A' && c <= 'Z');
}

int isxdigit(int c) {
    return (isdigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'));
}

int toupper(int c) {

    if (islower(c))
        return 'A' - 'a' + c;
    return c;
}

int tolower(int c) {

    if (isupper(c))
        return 'a' - 'A' + c;
    return c;
}
