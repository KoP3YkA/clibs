#include <stdbool.h>
#include "../libs/files/lib_file_manager.h"
#include "../libs/tests/lib_tests_manager.h"

int files_test() {
    bool is_error = false;

    CManagerFile file = { "./for_test.txt" };
    int test_res;

    DESCRIBE("Files test") {
        char* text = cfile_read(file);

        test_res = CTEST_EQ_STR(text, "Hello, World!");
        if (test_res == 1) is_error = true;

        cfile_overwrite(file, "Halo!");
        text = cfile_read(file);

        test_res = CTEST_EQ_STR(text, "Halo!");
        if (test_res == 1) is_error = true;

        cfile_add_text(file, "!");
        text = cfile_read(file);

        test_res = CTEST_EQ_STR(text, "Halo!!");
        if (test_res == 1) is_error = true;
    }

    return is_error;
}