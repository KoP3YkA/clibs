#include <stdbool.h>
#include "../libs/tests/lib_tests_manager.h"
#include "../libs/strings/lib_strings_manager.h"

int strings_test() {
    bool is_error = false;

    DESCRIBE("Strings test") {
        char* str = "Hi all";
        char* res = cstr_replace(str, "Hi", "Hello");

        if (CTEST_EQ_STR(res, "Hello all") == 1) is_error = true;
        if (CTEST_IS_TRUE(cstr_start_with("Hello, World!", "Hell")) == 1) is_error = true;
        if (CTEST_IS_TRUE(cstr_end_with("Hello, World!", "World!")) == 1) is_error = true;

        str = " Some text  ";
        cstr_trim(str);

        if (CTEST_EQ_STR(str, "Some text") == 1) is_error = true;
    }

    return is_error;
}