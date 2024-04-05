// LOGGING SYSTEM CREATED BY A0ZHAR
#pragma once
#ifndef _LOGGING_HH
#define _LOGGING_HH

#include "../../libPS4/include/ps4.h"

// Global variable for the log file
extern FILE *fd_log_file;


// Opens the log file
int open_log_file(const char *filename);

// Closes the log file
int close_log_file();

// Writes a (or non) formatted string to log file
void log_printf(const char *format, ...);

#endif

