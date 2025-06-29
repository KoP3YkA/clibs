cmake_minimum_required(VERSION 3.27)
project(cLIBS C)

set(CMAKE_C_STANDARD 11)

add_executable(cLIBS main.c
        libs/files/lib_file_manager.c
        libs/files/lib_file_manager.h
        tests/files.test.c
        tests/files.test.h
        libs/tests/lib_tests_manager.c
        libs/tests/lib_tests_manager.h
        libs/strings/lib_strings_manager.c
        libs/strings/lib_strings_manager.h
        tests/strings.test.c
        tests/strings.test.h
        libs/logs/lib_logs_manager.c
        libs/logs/lib_logs_manager.h
        examples/examples.c
        examples/examples.h)
