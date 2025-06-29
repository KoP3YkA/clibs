#include <stdio.h>
#include "lib_logs_manager.h"

int log_level = 0;

void send_log(char* text, int level) {
    if (level >= log_level) printf("%s", text);
}

void clogs_info(char* text, int level) {
    sprintf(text, "[INFO] %s", text);
    send_log(text, level);
}

void clogs_warn(char* text, int level) {
    sprintf(text, "[WARN] %s", text);
    send_log(text, level);
}

void clogs_error(char* text, int level) {
    sprintf(text, "[ERROR] %s", text);
    send_log(text, level);
}