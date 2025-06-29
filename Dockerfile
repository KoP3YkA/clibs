FROM gcc:latest

WORKDIR /app

COPY . .

RUN gcc main.c libs/files/lib_file_manager.c libs/logs/lib_logs_manager.c libs/strings/lib_strings_manager.c libs/tests/lib_tests_manager.c tests/files.test.c tests/strings.test.c -o main

CMD ["./main"]