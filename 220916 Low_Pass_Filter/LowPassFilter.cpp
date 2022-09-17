#include <stdio.h>

#define a 0.5

/*
* 이동평균필터를 재귀형태로 표현
* 입력값 : 이전의 평균 pre_avg, 새로 삽입할 데이터 sample_data
* 출력값 : 신규 데이터를 포함한 n개 데이터의 평균 avg
*/
float Low_pass_fil(float ppre_estire_X, float X);

int main(void)
{
	float pre_esti = 0.0; // 이전 예측값 저장
	float data = 0.0; // 신규 데이터 저장

	while (true)
	{
		printf("\n신규 데이터 : ");
		scanf_s("%f", &data);

		pre_esti = Low_pass_fil(pre_esti, data);

		printf("신규 예측값 : %.4f\n", pre_esti);
	}

	return 0;
}

float Low_pass_fil(float pre_esti, float X)
{
	float new_esti = 0.0;

	//재귀식 avg_x(k) = avg_x(k-1) + x(k)/n - x(k-n)/n
	new_esti = a * pre_esti + (1 - a) * X;

	return new_esti;
}