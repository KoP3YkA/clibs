#ifndef CLIBS_LIB_TESTS_MANAGER_H
#define CLIBS_LIB_TESTS_MANAGER_H

#include <corecrt.h>
#include <stdio.h>

/**
 * Count of tests
 */
extern int total_tests;

/**
 * Count of failed test
 */
extern int failed_tests;

/**
 * How many spaces will be outputted in printf in DESCRIBE blocks?
 */
extern int indent_level;

#define INDENT "  "

/**
 * Allows you to divide tests into groups
 */
#define DESCRIBE(name) \
    printf("\033[1;37;106m DESCRIBE \033[0m %s \033[0m \n", name); \
    indent_level++;                            \
    for (int _once = 1; _once; _once = 0)     \
        for (int _inner_once = 1; _inner_once; _inner_once = 0)


/**
 * Equals int
 */
#define CTEST_EQ_INT(a, b) ctest_eq_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_eq_int(int actual, int expected, char* actual_str, char* expected_str, char* file, int line, int indent);

/**
 * Not equals int
 */
#define CTEST_NE_INT(a, b) ctest_ne_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_ne_int(int actual, int expected, char* actual_str, char* expected_str, char* file, int line, int indent);

/**
 * Equals strings
 */
#define CTEST_EQ_STR(a, b) ctest_eq_str((a), (b), __FILE__, __LINE__, indent_level)
int ctest_eq_str(char* actual, char* expected, char* file, int line, int indent);

/**
 * Not equals strings
 */
#define CTEST_NE_STR(a, b) ctest_ne_str((a), (b), __FILE__, __LINE__, indent_level)
int ctest_ne_str(char* actual, char* expected, char* file, int line, int indent);

/**
 * To be NULL
 */
#define CTEST_NULL(a) ctest_null((a), __FILE__, __LINE__, indent_level)
int ctest_null(void* obj, char* file, int line, int indent);

/**
 * Not to be NULL
 */
#define CTEST_NOT_NULL(a) ctest_not_null((a), __FILE__, __LINE__, indent_level)
int ctest_not_null(void* obj, char* file, int line, int indent);

/**
 * Print total tests and tests results
 */
#define CTEST_PRINT_TOTAL() ctest_total()
void ctest_total();

/**
 * Equals ptrs
 */
#define CTEST_EQ_PTR(a, b) ctest_eq_ptr((a), (b), __FILE__, __LINE__, indent_level)
int ctest_eq_ptr(void* actual, void* expected, char* file, int line, int indent);

/**
 * Not equals ptrs
 */
#define CTEST_NE_PTR(a, b) ctest_ne_ptr((a), (b), __FILE__, __LINE__, indent_level)
int ctest_ne_ptr(void* actual, void* expected, char* file, int line, int indent);

/**
 * Equals int array values
 */
#define CTEST_EQ_INT_ARRAY(a, b, c) ctest_eq_int_array((a), (b), (c), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_eq_int_array(const int* actual, const int* expected, size_t len, const char* actual_str, const char* expected_str, const char* file, int line, int indent);

/**
 * `a` must be < `b`
 */
#define CTEST_LT_INT(a, b) ctest_lt_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_lt_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent);

/**
 * `a` must be <= `b`
 */
#define CTEST_LE_INT(a, b) ctest_le_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_le_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent);

/**
 * `a` must be > `b`
 */
#define CTEST_GT_INT(a, b) ctest_gt_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_gt_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent);

/**
 * `a` must be >= `b`
 */
#define CTEST_GE_INT(a, b) ctest_ge_int((a), (b), #a, #b, __FILE__, __LINE__, indent_level)
int ctest_ge_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent);

/**
 * `a` must be true
 */
#define CTEST_IS_TRUE(a) ctest_is_true((a), __FILE__, __LINE__, indent_level)
int ctest_is_true(bool a, char* file, int line, int indent);

/**
 * `a` must be false
 */
#define CTEST_IS_FALSE(a) ctest_is_false((a), __FILE__, __LINE__, indent_level)
int ctest_is_false(bool a, char* file, int line, int indent);

/**
 * Enables virtual terminal for output with colors
 */
void enable_virtual_terminal();

#endif //CLIBS_LIB_TESTS_MANAGER_H
