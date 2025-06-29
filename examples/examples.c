#include "../libs/files/lib_file_manager.h"
#include "../libs/logs/lib_logs_manager.h"
#include "../libs/strings/lib_strings_manager.h"

void example_main() {
    // --- Files ---

    // Read file
    CManagerFile file = { "./example.txt" };
    char* text = cfile_read(file); // "Hello!"

    // Overwrite file
    cfile_overwrite(file, "Hi"); // "Hi"

    // Add text to file
    cfile_add_text(file, "!"); // "Hi!"


    // --- Logger ---

    // Info log
    clogs_info("Hi!", 1); // [INFO] Hi!


    // --- Strings ---

    char* str = "  Hello!  ";

    // Trim
    cstr_trim(str); // "Hello!"

    // Start with
    bool res = cstr_start_with(str, "He"); // true
}