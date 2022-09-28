#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ����Լ�
void printMatrix(float m[][3]) {
	printf("----- ��� -----\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%.2f ", m[i][j]);
		}
		printf("\n");
	}
}
// �Է��Լ�
void setMatrix(float m[][3]) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("[%d][%d] : �Է�\n", i, j);
			scanf("%f", &m[i][j]);
		}
		if (j != 3)
			printf("mA[%d][%d] : �Է�\n", i, j);
	}
}
//��� �Լ� 
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
		printf("���α׷��� ��� �����Ű�� �����ø� 1�� �Է����ּ���\n");
		printf("<<���α׷� ����� 0�� �Է����ּ���>>");
		scanf("%d", &s);
		if (s == 0) break;

		printf("mA �Է�\n");
		setMatrix(mA);
		printf("mB �Է�\n");
		setMatrix(mB);

		printf("mA ���\n");
		printMatrix(mA);
		printf("mB ���\n");
		printMatrix(mB);
		printf("mC ���\n");
		calcMatrix(mA, mB, mC);

		printf("mC ���\n");
		printMatrix(mC);
	}
	return 0;
}