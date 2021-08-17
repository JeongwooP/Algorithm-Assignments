#include <stdio.h>	//��ó����� �ʿ� ����� �߰�
#include <stdlib.h>
#include <time.h>
#define SWAP(a, b, tmp) ( (tmp)=(a), (a)=(b), (b)=(tmp) )	//SWAP�̶�� ��ũ�θ� ����, ��ȯ�� ���� �� ������ �ϱ�����
#pragma warning (disable : 4996)


void selectionSort(double A[], int n)  // ���� ���� �Լ� ����
{
	int maxIdx;	//�ִ밪 ������ ����
	double tmp;	//�ӽ÷� ���� ������ ����

	for (int i = n-1; i > 0; i--)   // n-1��ŭ �ݺ�, �������� ���� ����
	{
		maxIdx = i;	//ó���� ���� ū �迭�� �ε������ ħ

		for (int j = i-1; j >= 0; j--)  // �ִ��� Ž��
		{
			if (A[j] > A[maxIdx])	//�ִ��� ã����
				maxIdx = j;	//�ִ��� �ε����� maxIdx�� ����
		}

		SWAP(A[i], A[maxIdx], tmp);	//A[i]�� �ִ��� SWAP, ��ȯ
		
	}
}

int main() 
{
	double *A, reslt;	//A�迭�� �����迭�� ����, reslt������ �ð� ���� ����
	double max = 32767 / 2.0;	//rand()�Լ��� -1~1���� ������ ���̷��� ����
	srand(1);	//seed�� 1�� �����ϰ� ����

	clock_t start, end;	//�ð� ���� ���� ����

	for (int i = 1; i < 21; i++)	//i�� for������ 1���� 20���� ����
	{
		A = malloc(sizeof(double) * (i * 1000));	//1000���� 20000���� �� �迭�� for������ �������� ����

		for (int j = 0; j < i * 1000; j++) //0���� i*1000���� �迭 �ε����� ����
		{
			A[j] = rand() / max - 1;	//-1~1������ ���� ����
		}

		start = clock();	//ó�� �ð��� ��

		selectionSort(A, i * 1000); // ���� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭�� ����
	}
	return 0;
}
