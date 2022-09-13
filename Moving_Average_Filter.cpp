#include <stdio.h>

#define n 10

float n_sample[n+1] = { 0, };

/*
* 이동평균필터를 재귀형태로 표현
* 입력값 : 이전의 평균 pre_avg, 새로 삽입할 데이터 sample_data
* 출력값 : 신규 데이터를 포함한 n개 데이터의 평균 avg
*/
float mov_avg_filter(float pre_av, float sample);

int main(void)
{
	float pre_avg = 0.0; // 이전 평균 저장
	float sample_data = 0.0; // 신규 데이터 저장

	while(true)
	{
		printf("\n신규 데이터 : ");
		scanf_s("%f", &sample_data);

		pre_avg = mov_avg_filter(pre_avg, sample_data);
		
		printf("Average : %.4f\n", pre_avg);
	}

	return 0;
}

float mov_avg_filter(float pre_avg, float sample)
{
	float avg = 0.0;

	n_sample[n] = sample;

	//재귀식 avg_x(k) = avg_x(k-1) + x(k)/n - x(k-n)/n
	avg = pre_avg + n_sample[n] / n - n_sample[0] / n;

	for (int i = 1; i < n+1; i++) 
	{
		n_sample[i - 1] = n_sample[i];
	}
	n_sample[n] = 0.0;

	printf("배열 : ");
	for (int i = 0; i < n; i++)
	{
		printf("%.1f ", n_sample[i]);
	}

	return avg;
}