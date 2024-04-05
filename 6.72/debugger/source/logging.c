#include "../include/logging.h"
#include <stdarg.h>

#define LOG_FILE_PATH "/user/ps4debug-logs.txt"
FILE *fd_log_file = NULL; // Initialize it

// Attempt's to open the log file, and if it's already
// open the code of 1 is returned, otherwise upon the
// log file being opened without errors the code 1 is
// returned
int open_log_file(const char *filename) {
    // if the log file has already been opened
    if (fd_log_file != NULL) return 0;

    // otherwise attempt to initialize it, and check 
    // if the call to fopen failed, and if so return
    // error code
    fd_log_file = fopen(filename, "a");
    if (fd_log_file == NULL)
        return -1;

    return 1;
}

// Function to try and close the log file using it's file
// descriptor
int close_log_file() {
    // Check if the log file (file descriptor) is equal
    // to NULL, meaining it has not been opened yet.
    if (fd_log_file == NULL) 
        return 0;
    
    // Otherwise, we close the log file, and then we set
    // the globaly used file descriptor variable to NULL 
    fclose(fd_log_file);
    fd_log_file = NULL;
    return 1; 
}

// Function that can be used as replacement for printf. This
// function will write a formatted/non formatted string to
// the log file
void log_printf(const char *format, ...) {
    // Make sure that the log file has been opened first, and
    // if it has not, we return early
    if (fd_log_file==NULL)
    return;
    
    // Build a formatted string to be printed to the log
    va_list args;
    va_start(args, format);
    vfprintf(fd_log_file, format, args);
    fprintf(fd_log_file, '\n');
    va_end(args);
}
