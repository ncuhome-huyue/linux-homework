#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#define UNUMBER 100

typedef struct {
	double average;
	int sum;
	int max;
	int min;
}Results;

void urand(void);

int usum(int * myArr);
double uave(int * myArr);
Results uoperator(int * myArr);

void readFile(int rawArray[UNUMBER]);
void stoiArray(char * str, int length, int rawArray[UNUMBER]);
void QuickSort(int *arr, int low, int high);
int compar(const void *a, const void *b);
