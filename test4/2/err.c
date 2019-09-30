#include "myheader.h"

void err_sys(const char * str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}
