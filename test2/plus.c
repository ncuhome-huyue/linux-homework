#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	int n;
	int count = 0;
	double sum = 1.0;
	double exchange = 0.0;
	if (argc > 1) {
		n = atof(argv[argc-1]) - 1; // 用户确定运算长度
		double bottom = 2.0, top = 1.0; // 分母初始为2，分子初始为1
		for (; count < n; count++) {
			if ((count % 2) == 0) {
				sum -= top / bottom;
			} else {
				sum += top / bottom;
			}
			exchange = top + bottom;
			top = bottom;
			bottom = exchange;
		}
		printf("%f\n", sum);
	} else {
		printf("error!");
	}
	return 0;
}
