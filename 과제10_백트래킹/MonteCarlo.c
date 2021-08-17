#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define NUM 1000	//subset �Լ��� NUM�� �ݺ� (Monte Carlo) 

int W = 52;	//sum value
int w[6];	//weights
int include[6];	//���� ����
int point = 0;	//promising�� �Ϸ� Ʈ�� ���� ����
int whole = 0;	//�� subset�� ���� ��� ����

int promising(int i, int weight, int total);

void sumOfSubsets(int i, int weight, int total) {	//�κ����� �� �Լ�
	whole++;

	if (promising(i, weight, total)) {	//������ ����
		if (weight == W) {	//�� weight�� ��ǥ�� ���ٸ�
			for (int n = 0; n <= i; n++)
				if (include[n])		//point�� +1�� �Ϸ�� Ʈ�� 1�� �߰�
					point++;
				
		}
		else {
			include[i + 1] = 1;	//yes
			sumOfSubsets(i + 1, weight + w[i + 1], total - w[i + 1]);	//����� ȣ��
			include[i + 1] = 0;	//no
			sumOfSubsets(i + 1, weight, total - w[i + 1]);	//����� ȣ��
		}
	}
}

int promising(int i, int weight, int total) {	//�������� �˻�
	return (weight + total >= W) && ((weight == W) || (weight + w[i + 1] <= W));
}


int main() {

	float res;
	int sum = 0;
	int temp = 0;

	srand(time(NULL));	//�Ź� ���� ������ ������ �ٸ���

	clock_t start = clock();	//�ð� ����

	for (int i = 0; i < NUM; i++) {	//Monte Carlo Method NUM��ŭ ����
		sum = 0;
		for (int j = 0; j < 6; j++) {
			w[j] = rand() % 53;
			sum += w[j];
		}
		
		for (int m = 0; m <= 6; m++)
			for (int k = 0; k < 5; k++)
				if (w[k] > w[k + 1]) {	//�������� ����
					temp = w[k];
					w[k] = w[k + 1];
					w[k + 1] = temp;
				}
		
		sumOfSubsets(-1, 0, sum);
	}

	clock_t end = clock();

	res = (float)(end - start) / CLOCKS_PER_SEC;	//�ð� ���
													//��� ���
	printf("ȿ���� = %d/%d (������ ���� �� / ��ü ���� ��) \n\n�ð� : %fsec\n\n", point, whole, res);

	return 0;
}