#include <stdio.h>	//������ϵ��� �߰��Ϸ� ��ó���⸦ ��
#pragma warning (disable : 4996)
#include <time.h>
#define FULL 25000	//���� �ִ� ������ 2�� 5õ���� �˳��� ����

typedef struct
{
	double value;	//���� ���� ������ ��
} unit;

typedef struct
{
	unit heap[FULL];	//���� �ִ� ������ �迭�� ��Ÿ��
	int heapSize;	//����� ������ heapSize�� ����
} heap;

void set(heap *h)
{
	h->heapSize = 0;	//ó������ ����� ������ 0
}

unit deleteSort(heap *h);	//deleteSort�� insert �Լ��� ������ ����
void insert(heap *h, unit node);

void heapSort(unit p[], int n) //���� ����ؼ� �����ϴ� heapSort�Լ�
{	
	int i;
	heap h;

	set(&h);	//heap h�� �ʱ�ȭ

	for (i = 0; i<n; i++)
		insert(&h, p[i]);	//�� h�� ��带 �߰�
	
	for (i = (n - 1); i >= 0; i--) 
		p[i] = deleteSort(&h);	//���� ���� �� p�迭�� ����
}

unit deleteSort(heap *h)	//deleteSort�� ���� �����ϸ� ������ �ϰ� ��
{
	int parent, child;
	unit node, tmp;

	node = h->heap[1]; // ��Ʈ ����� ���� node�� ����
	tmp = h->heap[(h->heapSize)--]; // �������� ���� tmp�� �����ϰ�, heapSize�� �ѹ� ���ҽ�Ŵ
	parent = 1;
	child = 2;

	while (child <= h->heapSize)
	{
		if ((child < h->heapSize) && ((h->heap[child].value) > h->heap[child + 1].value))
			child++;	//��Ʈ�� ���ʺ��� �ڽ� �� ���� ���� ã��
	

		if (tmp.value <= h->heap[child].value)	//���� �ڽ� ���� �������� �� ������
			break;	//while���� ����
		

		h->heap[parent] = h->heap[child];	//���� �ڽĺ��� �������� �� Ŭ�� �θ� ���� ���� �ڽ� ��带 �ٲ�

		parent = child;	//�� �� �Ʒ��� �̵�
		child *= 2;
	}

	h->heap[parent] = tmp;	//tmp�� �������� ��带 heap[parent]�� ����
	return node;	//���� ���� ��带 ��ȯ
}

void insert(heap *h, unit node)
{
	int i;
	i = ++(h->heapSize);	//�� ũ�⸦ �ϳ� ����

		//������ �θ�� ���ϴ� ����
	while ((i != 1) && (node.value < h->heap[i / 2].value))
	{	//i�� 1�� �ƴϸ鼭 ����� ���� �θ� ��庸�� ������ while�� ��
		h->heap[i] = h->heap[i / 2];	//i�� ���� �θ� ��� ��ȯ
		i /= 2;	//���� �ö�
	}
	h->heap[i] = node; // ���ο� ��尪�� ������
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

		heapSort(A, i * 1000); // �� ���� ������

		end = clock();	//���� �ð��� ��

		reslt = (double)(end - start);	//ó���� ���� ��� �Ǽ��� ����
		printf("n = %d �϶� ����ð�: %f msec \n", i * 1000, reslt);	//n�� ����� ���� �ð� ���

		free(A);	//�����迭�� ����
	}
	return 0;
}