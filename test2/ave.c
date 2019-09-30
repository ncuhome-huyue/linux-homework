#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void QuickSort(int *arr, int low, int high);
int compar(const void *a, const void *b);

int main() {
	const int SIZE = 1000000;
	struct timeval tv1, tv2;
	struct timezone tz;
	int i, j;
	int grade[SIZE];
	int anotherGrade[SIZE];

	srand((int)time(0));
	for (i = 0; i < SIZE / 20; i++) {
		for (j = 0; j < 20; j++) {
			grade[i * 20 + j] = (int)(1.0 + ((float)SIZE * rand()/(RAND_MAX + 1.0)));
			printf("%d\t", grade[i * 20 + j]);
		}
		printf("\n");
	}
	memcpy(anotherGrade, grade, sizeof(grade)); // 拷贝
	printf("---------------排序前---------------\n");

	gettimeofday(&tv1, &tz);
	QuickSort(grade, 0, SIZE - 1);
	gettimeofday(&tv2, &tz);

	for (i = 0; i < SIZE / 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d\t", grade[i * 20 + j]);
		}
		printf("\n");
	}
	printf("---------------排序后---------------\n");
	printf("排序时间：%ldms\n\n", tv2.tv_usec - tv1.tv_usec);

	printf("---------------另一个---------------\n");
	for (i = 0; i < SIZE / 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d\t", anotherGrade[i * 20 + j]);
		}
		printf("\n");
	}
	printf("---------------排序前---------------\n");

	gettimeofday(&tv1, &tz);
	qsort(anotherGrade, SIZE, sizeof(int), compar);
	gettimeofday(&tv2, &tz);

	for (i = 0; i < SIZE / 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d\t", anotherGrade[i * 20 + j]);
		}
		printf("\n");
	}
	printf("---------------排序后---------------\n");
	printf("排序时间：%ldms\n\n", tv2.tv_usec - tv1.tv_usec);
	return 0;
}

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int i = low;
        int j = high;
        int k = arr[low];
        while (i < j)
        {
            while(i < j && arr[j] >= k)     // 从右向左找第一个小于k的数
            {
                j--;
            }
 
            if(i < j)
            {
                arr[i++] = arr[j];
            }
 
            while(i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
            {
                i++;
            }
 
            if(i < j)
            {
                arr[j--] = arr[i];
            }
        }
 
        arr[i] = k;
 
        // 递归调用
        QuickSort(arr, low, i - 1);     // 排序k左边
        QuickSort(arr, i + 1, high);    // 排序k右边
    }
}

int compar(const void *a, const void *b) {
	int *aa = (int *) a, *bb = (int *)b;
	if (*aa > *bb) 			return 1;
	else if (*aa == *bb)	return 0;
	else					return -1;
}
