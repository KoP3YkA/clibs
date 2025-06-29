#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool cstr_start_with(const char *str, const char *prefix) {
    size_t len_prefix = strlen(prefix);
    return strncmp(str, prefix, len_prefix) == 0;
}

bool cstr_end_with(char* str, char* suffix) {
    size_t len_str = strlen(str);
    size_t len_suffix = strlen(suffix);

    if (len_suffix > len_str) {
        return false;
    }

    return strcmp(str + (len_str - len_suffix), suffix) == 0;
}

char* cstr_replace(const char* str, const char* old_sub, const char* new_sub) {
    if (!str || !old_sub || !new_sub) return NULL;

    size_t len_old = strlen(old_sub);
    size_t len_new = strlen(new_sub);

    int count = 0;
    const char* tmp = str;
    while ((tmp = strstr(tmp, old_sub))) {
        count++;
        tmp += len_old;
    }

    size_t new_len = strlen(str) + count * (len_new - len_old) + 1;
    char* result = malloc(new_len);
    if (!result) return NULL;

    char* dst = result;
    const char* current = str;

    while ((tmp = strstr(current, old_sub))) {
        size_t len = tmp - current;
        memcpy(dst, current, len);
        dst += len;

        memcpy(dst, new_sub, len_new);
        dst += len_new;

        current = tmp + len_old;
    }

    strcpy(dst, current);

    return result;
}

void cstr_trim(char* str) {
    if (!str || !*str) return;

    char* start = str;
    while (isspace((unsigned char)*start)) {
        start++;
    }

    if (*start == '\0') {
        str[0] = '\0';
        return;
    }

    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    *(end + 1) = '\0';

    if (start != str) {
        memmove(str, start, end - start + 2);
    }
}

char **cstr_split(const char *str, const char *delim, int *count) {
    char *copy = strdup(str);
    int capacity = 10;
    char **result = malloc(capacity * sizeof(char *));
    int i = 0;

    char *token = strtok(copy, delim);
    while (token) {
        if (i >= capacity) {
            capacity *= 2;
            result = realloc(result, capacity * sizeof(char *));
        }
        result[i++] = strdup(token);
        token = strtok(NULL, delim);
    }

    *count = i;
    free(copy);
    return result;
}

char *cstr_join(char **strings, int count, const char *delim) {
    if (count == 0) return strdup("");

    size_t len = 0;
    size_t delim_len = strlen(delim);
    for (int i = 0; i < count; i++) {
        len += strlen(strings[i]);
        if (i < count - 1) len += delim_len;
    }

    char *result = malloc(len + 1);
    result[0] = '\0';

    for (int i = 0; i < count; i++) {
        strcat(result, strings[i]);
        if (i < count - 1) strcat(result, delim);
    }

    return result;
}

void cstr_to_lower_case(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void cstr_to_upper_case(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

bool cstr_equals_ignore_case(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return false;
        }
        a++;
        b++;
    }
    return *a == *b;
}