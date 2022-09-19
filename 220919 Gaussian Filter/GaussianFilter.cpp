#define _CRT_SECURE_NO_WARNINGS
#define MAX 1501

#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <Math.h>

float kernel[5] = { 0, };

void GausFilt1D(int sigma);

int main(void)
{
	FILE* fp = NULL;
	float data[MAX] = { 0, };
	char buffer[100];
	int i = 0;

	fp = fopen("mat.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "파일 file.txt를 열 수 없습니다.\n");
		return 1;
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		buffer[strlen(buffer) - 1] = '\0';
		data[i] = atof(buffer);
		i++;
		//printf("%d, %s", i, buffer);
	}

	/*
	for (i = 0; i < MAX; i++)
	{
		printf("%f\n", data[i]);
	}
	*/



	fclose(fp);

	GausFilt1D(3);

	for (i = 0; i < 5; i++)
		printf("%f ", kernel[i]);

	for (i = 0; i < MAX; i++)
	{
		if(i-2 >= 0)
			data[i - 2] *= kernel[0];
		if(i-1 >= 0)
			data[i - 1] *= kernel[1];

		data[i] *= kernel[2];

		if(i+1 < MAX)
			data[i + 1] *= kernel[3];
		if(i+2 < MAX)
			data[i + 2] *= kernel[4];
	}

	fp = fopen("mat_Gaussian.txt", "w");

	if (fp == NULL) {
		fprintf(stderr, "파일 file.txt를 열 수 없습니다.\n");
		return 1;
	}

	for (i = 0; i < MAX; i++)
	{
		fprintf(fp, "%f\n", data[i]);
	}

	fclose(fp);

	return 0;
}


// 5 * sigma 1D GaussianFilter
void GausFilt1D(int sigma) 
{
	int i = 0;
	float arr[5] = { 0, };
	float sum = 0.0;

	for(i = (-1) * 5 / 2; i < 5 / 2 + 1; i++)
	{
		arr[i + (5 / 2)] = i;
	}

	for (i = 0; i < 5; i++)
	{
		kernel[i] = exp((-1)*pow(arr[i], 2)/(2 * pow(sigma, 2)));

		sum += kernel[i];
	}

	for (i = 0; i < 5; i++)
	{
		kernel[i] /= sum;
	}
}