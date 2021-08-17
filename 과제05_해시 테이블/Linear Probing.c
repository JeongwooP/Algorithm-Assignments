#include <stdio.h>
#define SIZE 13	//�ؽ� ���̺� �ִ� ��
#define EMPTY -1	//�� ���̺��� -1�� ����
int arr[SIZE];
int origin;

void init() {	//�迭�� -1 ������ �ʱ�ȭ
	for (int i = 0; i < SIZE; i++)
		arr[i] = EMPTY;
}

void linear(int n) {	//���� ���� ����� �߰� �Լ�
	int rs;

	rs = n % SIZE;	//x mod 13

	if (arr[rs] == EMPTY)	//���̺��� ��� ���� ����
		arr[rs] = origin;
	else {
		n++;	// x + i
		linear(n);
	}
}

int main() {
	int ins;
	init();	//�迭 �ʱ�ȭ

	while (1) {
		printf("�� �Է�: ");
		scanf("%d", &ins);
		origin = ins;
		linear(ins);

		printf("\nindex | value \n");
		for (int i = 0; i < SIZE; i++)
			if(arr[i] != EMPTY)		//���� EMPTY�� �ƴ� ��� �� ���
				printf("    %d | %d \n", i, arr[i]);
			else
				printf("    %d | Empty \n", i);		//���� -1 �̸� EMPTY��� ����ϱ�

		printf("\n");
	}
}