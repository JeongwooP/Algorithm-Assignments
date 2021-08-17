#include <stdio.h>	//���� ������ϵ��� ��ó����� �߰�
#include <math.h>
#include <time.h>
#pragma warning (disable : 4996)

double *margin; // �߰����� ������ �ʿ������� margin�̶�� �����迭 �����ϱ� ���� ����

void merge(double list[], int left, int mid, int right);	//merge �Լ� ���� ����

void mergeSort(double A[], int p, int r)	//���չ迭 �Լ�
{
	int q;

	if (p < r) 
	{
		q = (int)floor((p + r) / 2);	//�߰� ������ ���, floor �Լ� ���

		mergeSort(A, p, q);	//�迭�� ���ݺ�, �Ĺݺ� �ѷ� ���� ���� ����
		mergeSort(A, q + 1, r);

		merge(A, p, q, r);	//���ĵ� �� �迭�� ������

	}
}

void merge(double list[], int left, int center, int right) //2���� �迭�� �����ϴ� �Լ�
{
   
	int sortedL = left;	//���ĵ� ��������� sortedL
	int sortedR = center + 1;	//���ĵ� �߰��� �������� sortedR
	int sortedIndx = left;	//���ĵ� �迭�� �ε����� sortedIndx

	int i;

	while (sortedL <= center && sortedR <= right) //���� �迭�� �պ��� while������ �ۼ�
	{
		if (list[sortedL] <= list[sortedR])	//���� �� �� ������ �����͵��� ��, ���� ������� margin�� �ϳ��� �Ű� ����
			margin[sortedIndx] = list[sortedL++];
		else
			margin[sortedIndx] = list[sortedR++];

		sortedIndx++;
	}

	if (sortedL>center)		//�迭 ������ �����ϴ� ����(�� �κ�)
	{
		for (i = sortedR; i <= right; i++, sortedIndx++)
			margin[sortedIndx] = list[i];
	}
	else	//�迭 ������ �����ϴ� ����(�� �κ�)
	{
		for (i = sortedL; i <= center; i++, sortedIndx++)
			margin[sortedIndx] = list[i];
	}

	for (i = left; i <= right; i++) 
	{
		list[i] = margin[i];	//�ӽù迭�� �ʱ� �迭�� �ϳ��ϳ� �����Ŵ
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
		margin = malloc(sizeof(double) * (i * 1000));	//1000���� 20000���� �� �迭�� for������ �������� ����

		for (int j = 0; j < i * 1000; j++) //0���� i*1000���� �迭 �ε����� ����
		{
			A[j] = rand() / max - 1;	//-1~1������ ���� ����
		}

		start = clock();	//ó�� �ð��� ��

		mergeSort(A,0, i * 1000-1); // ���� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭 A�� ����
		free(margin); //�����迭 margin�� ����
	}
	return 0;
}