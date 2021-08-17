#include <stdio.h>	//��ó���⸦ ���� ���� ������� �߰�
#include <time.h>
#define SWAP(a, b, tmp) ( (tmp)=(a), (a)=(b), (b)=(tmp) )	//SWAP�̶�� ��ũ�θ� ����
#pragma warning (disable : 4996)	//scanf�� ���� ����

void bubbleSort(double A[], int n)	//���������� �Լ� ����
{
	double tmp;	//�ӽ÷� ���� double ����

	for (int i = n - 1; i > 0; i--)	//n-1�ε������� 1���� -1�� ����
	{
		for (int j = 0; j < i; j++) //0���� i���� ����
		{
			if (A[j] > A[j + 1])	//���� �տ��� �� �۴ٸ� ������ ��ȯ
				SWAP(A[j], A[j + 1], tmp);	//A[j]�� A[j+1]�� ��ȯ
		}
	}
}

int main() 
{
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

		bubbleSort(A, i * 1000); // ���� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭�� ����
	}
	return 0;
}