#include "func.h"

void urand(void) {
	int i, j;
	char * fileName = "rawdata.dat";
	srand((int)time(0));
	FILE *writeFile = fopen(fileName, "w+");
	for (i = 0; i < UNUMBER / 10; i++) {
		for (j = 0; j < 10; j++) {
			if (writeFile) {
				fprintf(writeFile, "%d ", (int)(1.0 + ((float)UNUMBER * rand()/(RAND_MAX + 1.0))));
			} else
				printf("%s open failed!\n", fileName);
		}
		fprintf(writeFile, "\n");
	}
	fclose(writeFile);
}
