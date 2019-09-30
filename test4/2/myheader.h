#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

void err_sys(const char * str);
