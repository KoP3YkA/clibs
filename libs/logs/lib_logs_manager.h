#ifndef CLIBS_LIB_LOGS_MANAGER_H
#define CLIBS_LIB_LOGS_MANAGER_H

extern int log_level;

/**
 * Send info log
 * @param text log
 * @param level level
 */
void clogs_info(char* text, int level);

/**
 * Send warn log
 * @param text log
 * @param level level
 */
void clogs_warn(char* text, int level);

/**
 * Send error
 * @param text error
 * @param level level
 */
void clogs_error(char* text, int level);

#endif //CLIBS_LIB_LOGS_MANAGER_H
