#include <stdio.h>
#include "tests/files.test.h"
#include "tests/strings.test.h"

/**
 * Tests
 */
int main() {
    int files_test_result = files_test();
    int strings_test_result = strings_test();

    if (
            files_test_result == 1 ||
            strings_test_result == 1
       ) return 1;

    return 0;
}
