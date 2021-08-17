#include <stdio.h>	//��ó����� ��� ���ϵ� �߰�
#include <time.h>
#pragma warning (disable : 4996)

void insertionSort(double A[], int n) 
{
	double c;	//���� �����ϴ� double���� c ����
	int j;

	for (int i = 1; i < n; i++) 
	{
		c = A[i]; // �迭 A�� i��° ���� ���� c�� ����

		for (j = i - 1; j >= 0; j--) // i-1���� ������ �پ��鼭 j=0���� Ž��
		{
			if (A[j] > c)	//A[j]�� c���� ũ��
				A[j + 1] = A[j]; // �񱳴�� �� ĭ �ڷ� �̵�
			else
				break;	//������ġ ã������ Ż��
		}

		A[j + 1] = c;	//ã�� ��ġ�� ���Ĵ�� ����
	}
}

int main() {
	double *A, reslt;	//A�迭�� �����迭�� ����, reslt������ �ð� ���� ����
	double max = 32767 / 2.0;	//rand()�Լ��� -1~1���� ������ ���̷��� ����
	srand(1);	//seed�� 1�� �����ϰ� ����

	clock_t start, end;	//�ð� ���� ���� ����

	for (int i = 1; i < 21; i++) //i�� for������ 1���� 20���� ����
	{
		A = malloc(sizeof(double) * (i * 1000));	//1000���� 20000���� �� �迭�� for������ �������� ����

		for (int j = 0; j < i * 1000; j++) //0���� i*1000���� �迭 �ε����� ����
		{
			A[j] = rand() / max - 1;	//-1~1������ ���� ����
		}

		start = clock();	//ó�� �ð��� ��

		insertionSort(A, i * 1000); // ���� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭�� ����
	}
	return 0;
}