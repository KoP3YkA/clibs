#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BOLD "\033[1m"

#define PASS_BADGE "\033[1;30;42m PASS \033[0m"
#define FAIL_BADGE "\033[1;37;41m FAIL \033[0m"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int total_tests = 0;
int failed_tests = 0;
int indent_level = 0;

#define PRINT_PASS(file, line, indent) \
    do {                       \
        total_tests++;         \
        for (int i = 0; i < indent; i++) printf("  ");                       \
        printf("%s %s:%d%s\n", PASS_BADGE, file, line, RESET); \
    } while (0)

#define PRINT_FAILED(file, line, name, actual, expected, indent) \
    do {                                                 \
        total_tests++;                                                 \
        failed_tests++;                                                 \
        for (int i = 0; i < indent; i++) printf("  ");                                                 \
        printf("%s %s:%d %s\n", FAIL_BADGE, file, line, RESET); \
        for (int i = 0; i < indent; i++) printf("  ");                                                 \
        printf("  %s%s failed%s\n", RED, name, BOLD, RESET); \
        for (int i = 0; i < indent; i++) printf("  ");                                                 \
        printf("  %sActual:   %s%s\n", RED, actual, RESET); \
        for (int i = 0; i < indent; i++) printf("  ");                                                 \
        printf("  %sExpected: %s%s\n\n", GREEN, expected, RESET); \
    } while(0)

int ctest_eq_int(int actual, int expected, const char* actual_str, const char* expected_str, const char* file, int line, int indent) {
    if (actual != expected) {
        PRINT_FAILED(file, line, "CTEST_EQ_INT", actual_str, expected_str, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_ne_int(int actual, int expected, char* actual_str, char* expected_str, char* file, int line, int indent) {
    if (actual == expected) {
        PRINT_FAILED(file, line, "CTEST_NE_INT", actual_str, expected_str, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_eq_str(char* actual, char* expected, char* file, int line, int indent) {
    if (strcmp(actual, expected) != 0) {
        PRINT_FAILED(file, line, "CTEST_EQ_STR", actual, expected, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_ne_str(char* actual, char* expected, char* file, int line, int indent) {
    if (strcmp(actual, expected) == 0) {
        PRINT_FAILED(file, line, "CTEST_NE_STR", actual, expected, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_null(void* obj, char* file, int line, int indent) {
    if (obj != NULL) {
        PRINT_FAILED(file, line, "CTEST_NULL", obj, NULL, indent);
        return 1;
    }
    else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_not_null(void* obj, char* file, int line, int indent) {
    if (obj == NULL) {
        PRINT_FAILED(file, line, "CTEST_NOT_NULL", obj, "!NULL", indent);
        return 1;
    }
    else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_eq_ptr(void* actual, void* expected, char* file, int line, int indent) {
    if (actual != expected) {
        PRINT_FAILED(file, line, "CTEST_EQ_PTR", actual, expected, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_ne_ptr(void* actual, void* expected, char* file, int line, int indent) {
    if (actual == expected) {
        PRINT_FAILED(file, line, "CTEST_NE_PTR", actual, expected, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_true(bool actual, char* file, int line, int indent) {
    if (actual != true) {
        PRINT_FAILED(file, line, "CTEST_TRUE", actual, true, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_false(bool actual, char* file, int line, int indent) {
    if (actual != false) {
        PRINT_FAILED(file, line, "CTEST_FALSE", actual, false, indent);
        return 1;
    } else {
        PRINT_PASS(file, line, indent);
        return 0;
    }
}

int ctest_eq_int_array(const int* actual, const int* expected, size_t len, const char* actual_str, const char* expected_str, const char* file, int line, int indent) {
    for (size_t i = 0; i < len; i++) {
        if (actual[i] != expected[i]) {
            PRINT_FAILED(file, line, "CTEST_EQ_INT_ARRAY", actual_str, expected_str, indent);
            return 1;
        }
    }
    PRINT_PASS(file, line, indent);
    return 0;
}

int ctest_lt_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent) {
    if (a < b) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_LT_INT", a_str, b_str, indent);
        return 1;
    }
}

int ctest_le_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent) {
    if (a <= b) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_LE_INT", a_str, b_str, indent);
        return 1;
    }
}

int ctest_gt_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent) {
    if (a > b) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_GT_INT", a_str, b_str, indent);
        return 1;
    }
}

int ctest_ge_int(int a, int b, const char* a_str, const char* b_str, const char* file, int line, int indent) {
    if (a >= b) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_GE_INT", a_str, b_str, indent);
        return 1;
    }
}

int ctest_is_true(bool a, char* file, int line, int indent) {
    if (a == true) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_IS_TRUE", a, "true", indent);
        return 1;
    }
}

int ctest_is_false(bool a, char* file, int line, int indent) {
    if (a == false) {
        PRINT_PASS(file, line, indent);
        return 0;
    } else {
        PRINT_FAILED(file, line, "CTEST_IS_TRUE", a, "false", indent);
        return 1;
    }
}

#ifdef _WIN32
#include <windows.h>
void enable_virtual_terminal() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}
#endif

void ctest_total() {
    printf("\n%s %s%d%s\n", "\033[1;30;42m TOTAL \033[0m", RESET, total_tests, RESET);
    printf("%s %s%d%s\n", "\033[1;37;41m FAILED \033[0m", RESET, failed_tests, RESET);
}