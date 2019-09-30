#include "func.h"

int main(void) {
	struct timeval tv1, tv2;
	struct timezone tz;
	int i, j;
	int mySort[UNUMBER] = {0};
	long mySortTime = 0L;
	int sysSort[UNUMBER] = {0};
	long sysSortTime = 0L;
	
	urand();
	
	readFile(mySort);
	readFile(sysSort);
	
	gettimeofday(&tv1, &tz);
	QuickSort(mySort, 0, UNUMBER - 1);
	gettimeofday(&tv2, &tz);
	mySortTime = tv2.tv_usec - tv1.tv_usec;
	
	gettimeofday(&tv1, &tz);
	qsort(sysSort, UNUMBER, sizeof(int), compar);
	gettimeofday(&tv2, &tz);
	sysSortTime = tv2.tv_usec - tv1.tv_usec;
	
	for (i = 0; i < UNUMBER / 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d\t", mySort[i * 10 + j]);
		}
		printf("\n");
	}
	printf("sort time: %ld\n", mySortTime);
	
	for (i = 0; i < UNUMBER / 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d\t", sysSort[i * 10 + j]);
		}
		printf("\n");
	}
	printf("sort time: %ld\n", sysSortTime);
	return 0;
}
