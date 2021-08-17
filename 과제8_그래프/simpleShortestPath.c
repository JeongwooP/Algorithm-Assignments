#include <stdio.h>
#define N 7	//�׷����� ���� ����
#define INF 999	//���� �ȵ� ���� ǥ��

int arr[7][7] = {
 {0, 4, INF, INF, INF, 10, INF},
 {3, 0, INF, 18, INF, INF, INF},
 {INF, 6, 0, INF, INF, INF, INF},
 {INF, 5, 15, 0, 2, 19, 5},
 {INF, INF, 12, 1, 0, INF, INF},
 {INF, INF, INF, INF, INF, 0, 10},
 {INF, INF, INF, 8, INF, INF, 0}
};
int d[7][7];	//d�� �ִ� ��� ���� ���

void simpleShortestPath() {	//�ִ� ��� �Լ�

	/*ó�� �׷���, �� ���� ����� �Ÿ��� ���d�� ����*/
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			d[i][j] = arr[i][j];	//��� d�� arr�� ������

	/*��� �������� �ϳ��� �߰� ������ ����*/
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (d[i][k] + d[k][j] < d[i][j])   //���� k�� i -> j�� ���� ���� ª�� path�� 
					d[i][j] = d[i][k] + d[k][j];	//d[i][j]�� ������

	printf("�ִܰ�� ����ġ ���\n D=\n");
	for (int i = 0; i < N; i++) {			//��� D ��� ���
		for (int j = 0; j < N; j++)
			if (d[i][j] == INF)
				printf("������� ����\n");
			else
				printf(" %2d ", d[i][j]);

		printf("\n");
	}
}


int main() {
	simpleShortestPath();	//�ִ� ��� �Լ� ȣ��

	return 0;
}