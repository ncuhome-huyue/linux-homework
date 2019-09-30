#include "func.h"

void readFile(int rawArray[UNUMBER]) {
	char buffer[50] = {0};
	char rand[500] = {0};
	int i, j, rowCharCount;
	
	rowCharCount = 0;
	FILE * readFile = fopen("rawdata.dat", "r");
	
	if (readFile) {
		for (i = 0; i < 10; i++ ) {
			fgets(buffer, 255, (FILE*) readFile);
			printf("%s", buffer);
			for (j = 0; buffer[j] != '\0'; j++, rowCharCount++) {
				rand[rowCharCount] = buffer[j];
			}
		}
		fclose(readFile);
		if (*rand) {
			printf("\n%s\n", rand);
			stoiArray(rand, rowCharCount, rawArray);
		} else
			exit(1);
	} else {
		printf("rawdata.dat open error!\n");
		exit(1);
	}
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
                j--;
 
            if(i < j)
                arr[i++] = arr[j];
 
            while(i < j && arr[i] < k)      // 从左向右找第一个大于等于k的数
                i++;
 
            if(i < j)
                arr[j--] = arr[i];
        }
        arr[i] = k;
        // 递归调用
        QuickSort(arr, low, i - 1);     // 排序k左边
        QuickSort(arr, i + 1, high);    // 排序k右边
    }
}


void stoiArray(char * str, int length, int rawArray[UNUMBER]) {
	char temp[3];
	int singleNum;
	int i, j, tempLength;
	tempLength = 0;
	j = 0;
	for (i = 0; i < length; i++) {
		// 处理字符串
		if (str[i] == ' ') {
			// 判断长度
			if (tempLength == 3)
				singleNum = (((int)temp[0]) - 48) * 100 + (((int)temp[1]) - 48) * 10 + (((int)temp[2]) - 48);
			else if (tempLength == 2)
				singleNum = (((int)temp[0]) - 48) * 10 + (((int)temp[1]) - 48);
			else if (tempLength == 1)
				singleNum = (((int)temp[0]) - 48);
			else
				singleNum = -1;
			// 长度置0
			tempLength = 0;
			// 除错与存入数组
			if (singleNum == -1) {
				printf("tempLength error!\n");
				exit(1);
			} else {
				// 存入数组
				rawArray[j] = singleNum;
				j++;
			}
		} else if (str[i] == '\0') {
			break;
		} else if (str[i] >= 48 && str[i] <= 57) {
			// 进栈
			if (tempLength == 0 || tempLength == 1 || tempLength == 2) {
				temp[tempLength] = str[i];
				tempLength++;
			} else {
				printf("temp overflowed!\n");
				exit(1);
			}
		} else if (str[i] == '\n') {
			continue;
		} else {
			printf("%d char error!\n", str[i]);
			exit(1);
		}
	}
}

int compar(const void *a, const void *b) {
	int *aa = (int *) a, *bb = (int *)b;
	if (*aa > *bb) 			return 1;
	else if (*aa == *bb)	return 0;
	else					return -1;
}

