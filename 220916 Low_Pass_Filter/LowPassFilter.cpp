#include <stdio.h>

#define a 0.5

/*
* �̵�������͸� ������·� ǥ��
* �Է°� : ������ ��� pre_avg, ���� ������ ������ sample_data
* ��°� : �ű� �����͸� ������ n�� �������� ��� avg
*/
float Low_pass_fil(float ppre_estire_X, float X);

int main(void)
{
	float pre_esti = 0.0; // ���� ������ ����
	float data = 0.0; // �ű� ������ ����

	while (true)
	{
		printf("\n�ű� ������ : ");
		scanf_s("%f", &data);

		pre_esti = Low_pass_fil(pre_esti, data);

		printf("�ű� ������ : %.4f\n", pre_esti);
	}

	return 0;
}

float Low_pass_fil(float pre_esti, float X)
{
	float new_esti = 0.0;

	//��ͽ� avg_x(k) = avg_x(k-1) + x(k)/n - x(k-n)/n
	new_esti = a * pre_esti + (1 - a) * X;

	return new_esti;
}