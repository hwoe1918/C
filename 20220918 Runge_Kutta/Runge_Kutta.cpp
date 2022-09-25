#define _CRT_SECURE_NO_WARNINGS
#define MAX 100


#include <stdio.h>

float dX, dV;

float x[MAX] = { 0.0, };
float v[MAX] = { 0.0, };
float Kx[4] = { 0, }; 
float Kv[4] = { 0, };

float F(float B, float K, float M, float v, float x)
{
	return -((B * v) / M) - ((K * x) / M);
}

void dF(float B, float M, float K, int cnt, float h)
{
	for (int n = 0; n < cnt; n++)
	{
		float X = x[n];
		float V = v[n];

		Kx[0] = V * h;
		Kv[0] = F(B, K, M, V, X) * h;

		Kx[1] = (V + (Kv[0] / 2)) * h;
		Kv[1] = F(B, K, M, V + Kv[0] / 2, X + Kx[0] / 2) * h;

		Kx[2] = (V + (Kv[1] / 2)) * h;
		Kv[2] = F(B, K, M, V + Kv[1] / 2, X + Kx[1] / 2) * h;

		Kx[3] = (V + Kv[2]) * h;
		Kv[3] = F(B, K, M, V + Kv[2], X + Kx[2]) * h;

		dX = h * (Kx[0] + 2 * Kx[1] + 2 * Kx[2] + Kx[3]) / 6.0;
		dV = h * (Kv[0] + 2 * Kx[1] + 2 * Kx[2] + Kx[3]) / 6.0;

		v[n + 1] = V + dV;
		x[n + 1] = X + dX;
	}
}

int main(void)
{
	float K, M, B, h, T1, T0, V0, X0;
	int cnt = 0;

	printf("M : ");
	scanf("%f", &M);

	printf("B : ");
	scanf("\n%f", &B);
	
	printf("K : ");
	scanf("\n%f", &K);

	printf("h : ");
	scanf("\n%f", &h);

	printf("T0 : ");
	scanf("\n%f", &T0);

	printf("T1 : ");
	scanf("\n%f", &T1);

	printf("V0 : ");
	scanf("\n%f", &V0);

	printf("X0 : ");
	scanf("\n%f", &X0);

	cnt = T1 - T0;
	v[0] = V0;
	x[0] = X0;

	dF(B, M, K, cnt, h);

	for (int i = 0; i < sizeof(x)/sizeof(x[0]); i++)
	{
		if (x[i] == 0.0)
			break;
		printf("변위 : %f\t", x[i]);
		printf("속도 : %f\n", v[i]);
	}
	return 0;
}

