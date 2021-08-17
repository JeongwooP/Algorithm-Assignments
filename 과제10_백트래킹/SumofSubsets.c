#include <stdio.h>
#include <conio.h>

int W = 52;	//sum value
int w[6] = { 2, 10, 13, 17, 22, 42 }; //�־��� weights
int include[6]; //�� ���� ����
int count = 0;	//step ��� ���� count

int promising(int i, int weight, int total);

void sumOfSubsets(int i, int weight, int total) { //�κ����� �� �Լ�
	count++;
	if (promising(i, weight, total)) {	//������ ����
		if (weight == W) {				//�� weight�� ��ǥ�� ���ٸ�
			printf("\n���� subsets: [ ");
			for (int n = 0; n <= i; n++)
				if (include[n])			//Sum-of-Subset�� �´� ���� ���
					printf("%d ", w[n]);
			printf("]\n");
		}
		else {
			include[i + 1] = 1;	//yes
			if (count < 5) {
				printf("\step%d: ( ", count);	//3~4�ܰ� ���
				for (int n = 0; n <= i; n++)
					if (include[n])
						printf("%d ", w[n]);
				printf(")\n");
			}
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
	sumOfSubsets(-1, 0, 106);	//sumOfSubsets�Լ� ����
	return 0;
}