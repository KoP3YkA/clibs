#ifndef CLIBS_LIB_STRINGS_MANAGER_H
#define CLIBS_LIB_STRINGS_MANAGER_H

#include <stdbool.h>

/**
 * Checks if `str` starts with `prefix`
 * @param str current string
 * @param prefix prefix
 * @return bool
 */
bool cstr_start_with(const char *str, const char *prefix);

/**
 * Checks if `str` ends with `suffix`
 * @param str current string
 * @param suffix suffix
 * @return bool
 */
bool cstr_end_with(char* str, char* suffix);

/**
 * Replace `old_sub` to `new_sub` in `str`
 * @param str current string
 * @param old_sub old string
 * @param new_sub new string
 * @return char* - replaced string
 */
char* cstr_replace(const char* str, const char* old_sub, const char* new_sub);

/**
 * Replace spaces in start and end of string
 * @param str current string
 * @return void
 */
void cstr_trim(char* str);

/**
 * Split string to parts
 * @param str current string
 * @param delim delim
 * @param count returns count of parts
 * @return char**
 */
char **cstr_split(const char *str, const char *delim, int *count);

/**
 * Join string by parts
 * @param strings
 * @param count
 * @param delim
 * @return
 */
char *cstr_join(char **strings, int count, const char *delim);

/**
 * Make string in lower case
 * @param str current string
 */
void cstr_to_lower_case(char *str);

/**
 * Make string in upper case
 * @param str current string
 */
void cstr_to_upper_case(char *str);

/**
 * Equals strings ignore case
 * @param a str one
 * @param b str two
 * @return bool
 */
bool cstr_equals_ignore_case(const char *a, const char *b);

#endif //CLIBS_LIB_STRINGS_MANAGER_H
