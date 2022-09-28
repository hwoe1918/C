#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 출력함수
void printMatrix(float m[][3]) {
	printf("----- 출력 -----\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%.2f ", m[i][j]);
		}
		printf("\n");
	}
}
// 입력함수
void setMatrix(float m[][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("[%d][%d] : 입력\n", i, j);
			scanf("%f", &m[i][j]);
		}
		if (j != 3)
			printf("mA[%d][%d] : 입력\n", i, j);
	}
}
//계산 함수 
void calcMatrix(float a[][3], float b[][3], float c[][3]) {
	int k, temp;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp = 0;
			for (k = 0; k < 3; k++) {
				temp += (a[i][k] * b[k][j]);
			}
			c[i][j] = temp;
		}
	}
}
int main(void) {
	float mA[3][3] = { 0, };
	float mB[3][3] = { 0, };
	float mC[3][3] = { 0, };

	while (1) {
		int s = NULL;
		printf("프로그램을 계속 진행시키고 싶으시면 1을 입력해주세요\n");
		printf("<<프로그램 종료는 0을 입력해주세요>>");
		scanf("%d", &s);
		if (s == 0) break;

		printf("mA 입력\n");
		setMatrix(mA);
		printf("mB 입력\n");
		setMatrix(mB);

		printf("mA 출력\n");
		printMatrix(mA);
		printf("mB 출력\n");
		printMatrix(mB);
		printf("mC 계산\n");
		calcMatrix(mA, mB, mC);

		printf("mC 출력\n");
		printMatrix(mC);
	}
	return 0;
}