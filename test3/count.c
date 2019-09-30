#include "func.h"

int sum = 0;

int usum(int * myArr) {
	int i;
	for (i = 0; i < UNUMBER; i++) {
		sum += myArr[i];
	} 
	return sum;
}

double uave(int * myArr) {
	return (double)sum / (double)UNUMBER;
}

Results uoperator(int * myArr) {
	Results myResult;
	myResult.sum = usum(myArr);
	myResult.average = uave(myArr);
	QuickSort(myArr, 0, UNUMBER - 1);
	myResult.max = myArr[UNUMBER - 1];
	myResult.min = myArr[0];
	return myResult;
}
