#include <stdio.h>
#define N 7	//�׷����� ���� ����
#define INF 999	//���� �ȵ� ���� ǥ��

void printPath(int p[][N], int start, int end) {	//start���� end������ �̾����� ��� ���
	if (p[start - 1][end - 1] != 0)		//0���� �ƴ�, �ٸ� ��� ������ if�� ����
	{
		printPath(p, start, p[start - 1][end - 1]);	//�����, start��忡�� �����ϴ� ������ ��� �˻�
		printf("%2d->", p[start - 1][end - 1]);
		printPath(p, p[start - 1][end - 1], end);  // �����, �����ϴ� ��忡�� end������ ��� �˻�
	}
}

void floyd2(int n, const W[][N], int D[][N], int P[][N]) {	//Floyd's �ִܰ�� �˰���
	int i, j, k;
	for (i = 0; i < n; i++)	//0���� �ʱ�ȭ
		for (j = 0; j < n; j++)
			P[i][j] = 0;

	for (i = 0; i < n; i++)	//D = W
		for (j = 0; j < n; j++)
			D[i][j] = W[i][j];

	for(k = 0; k < n ; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) 
				if (D[i][k] + D[k][j] < D[i][j]) {	//k�� ���İ��� ���� �� ������
					P[i][j] = k + 1;				//k�� ������ �Ÿ��� D�� ������Ʈ
					D[i][j] = D[i][k] + D[k][j];
				}	
		
}

int main() {
	int i, j;

	int W[N][N] = {	//W��� �ʱ�ȭ
		{ 0, 4, INF, INF, INF, 10, INF },
		{ 3, 0, INF, 18, INF, INF, INF },
		{ INF, 6, 0, INF, INF, INF, INF },
		{ INF, 5, 15, 0, 2, 19, 5 },
		{ INF, INF, 12, 1, 0, INF, INF },
		{ INF, INF, INF, INF, INF, 0, 10 },
		{ INF, INF, INF, 8, INF, INF, 0 }
	};

	int P[N][N];	//��� P
	int D[N][N];	//��� D

	floyd2(N, W, D, P);

	printf("2��)\nP = \n");
	for (i = 0; i < N; i++) {	//P��� ���
		for (j = 0; j < N; j++)
			printf("%2d ", P[i][j]);

		printf("\n");
	}

	printf("\nD = \n");
	for (i = 0; i < N; i++) {	//D��� ���
		for (j = 0; j < N; j++)
			printf("%2d ", D[i][j]);

		printf("\n");
	}

	printf("\n");
	printf("V3 -> V6:\n");
	printf("�ִܰ��: 3->");
	printPath(P, 3, 6);	//V3���� ������ V6������ �ִ� ��� ���
	printf(" 6\n");
	printf("�ִܰŸ�: %2d\n\n", D[2][5]);

	int A[N][N] = {	//�ٲ� ���� 3�� A��� �ʱ�ȭ
		{ 0, INF, INF, 8, INF, INF, INF },
		{ 10, 0, INF, INF, INF, INF, INF },
		{ INF, INF, 0, 1, 12, INF, INF },
		{ 5, 19, 2, 0, 15, 5, INF },
		{ INF, INF, INF, INF, 0, 6, INF },
		{ INF, INF, INF, 18, INF, 0, 3 },
		{ INF, 10, INF, INF, INF, 4, 0 }
	};

	floyd2(N, A, D, P);

	printf("3��)\nP = \n");
	for (i = 0; i < N; i++) {	//P ���
		for (j = 0; j < N; j++)
			printf("%2d ", P[i][j]);

		printf("\n");
	}

	printf("\nD = \n");
	for (i = 0; i < N; i++) {	//D���
		for (j = 0; j < N; j++)
			printf("%2d ", D[i][j]);

		printf("\n");
	}

	printf("\n");
	printf("a5 -> a2:\n");
	printf("�ִܰ��: 5->");
	printPath(P, 5, 2);	//A5���� ������ A2������ �ִ� ��� ��� 
	printf(" 2\n");
	printf("�ִܰŸ�: %2d\n\n", D[4][1]);

	return 0;
}