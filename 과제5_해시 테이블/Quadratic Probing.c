#include <stdio.h>
#define SIZE 13	//�ؽ� ���̺� �ִ� ����
#define EMPTY -1

int arr[SIZE];
int origin, i = 0;	//origin - ó�� �Է��� ��,
int index;	//�־��� ������ mod 13�� ó�� ������

void init() {	//��� ���̺� ���� EMPTY�� ����
	for (int i = 0; i < SIZE; i++)
		arr[i] = EMPTY;
}

void quadratic(int n) {		//������ ���� �Լ�
	int rs;

	rs = n % SIZE;

	if (arr[rs] == EMPTY) {	//�ؽ� ���̺��� ��� ����
		arr[rs] = origin;
		i = 0;
	}
	else {	//�ƴϸ� x + i^2 ���� �Ѿ
		i++;
		n = index + i * i;
		quadratic(n);
	}
}

int main() {
	int ins;
	init();

	while (1) {
		printf("�� �Է�: ");
		scanf("%d", &ins);
		origin = ins;
		index = ins % SIZE;
		quadratic(ins);

		printf("\nindex | value \n");
		for (int i = 0; i < SIZE; i++)
			if (arr[i] != EMPTY)		//���� EMPTY�� �ƴ� ��� �� ���
				printf("    %d | %d \n", i, arr[i]);
			else
				printf("    %d | Empty \n", i);		//���� -1 �̸� EMPTY��� ����ϱ�

		printf("\n");
	}
}