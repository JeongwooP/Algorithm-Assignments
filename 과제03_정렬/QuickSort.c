#include <stdio.h>	//��ó����� ��� ���ϵ� �߰�
#include <time.h>
#define SWAP(a, b, tmp) ( (tmp)=(a), (a)=(b), (b)=(tmp) )	//SWAP�̶�� ��ũ�θ� ����
#pragma warning (disable : 4996)

int partition(double arr[], int left, int right) 
{
	double tmp;	//������ double ���� ����

	int low = left;	//�� ������ low������ ����
	int high = right - 1;	//�� �������� ��ĭ ������ high�� ����
	double pivot = arr[right]; // ���� �������� ��ġ�� �ǹ��� ��ġ(��� ���̵��� �ǹ��� ������ �� ����)
				
	do {
		do {
			low++; // �ǹ��� �迭�� arr[low]���� �� ũ�� ��� ����
		} while (low <= right && arr[low] < pivot);

		do {
			high--; // �ǹ��� �迭�� arr[high]���� �� ������ ��� ����
		} while (high >= left && arr[high] > pivot);

		if (low < high)  // low�� high���� ������ arr[low]�� arr[high] ���� �ٲ�
			SWAP(arr[low], arr[high], tmp);
	} while (low < high);	//low�� high���� Ŀ���� ���� �ݺ���

	SWAP(arr[right], arr[low], tmp);	// low�� high���� Ŀ���� while�� Ż�� �� arr[right]�� arr[low]�� swap��
	
	return low; // �ǹ��� ��ġ�� low�� ��ȯ
}


void quickSort(double A[], int p, int r) {	
	int q;
	if (p < r) {
		q = partition(A, p, r);	//�ѷ� ������
		
		quickSort(A, p, q - 1);	//���� ������ ����
		
		quickSort(A, q + 1, r);	//������ ������ ����
	}
}

int main() {
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

		quickSort(A, 0, i * 1000 - 1); // �� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭�� ����
	}
	return 0;
}