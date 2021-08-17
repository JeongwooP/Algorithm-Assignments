#include<stdio.h>
#define SIZE 5	//���� ����

int bag[12], sum = 0;

int w[5][5] = {	//��� W
	{ 0, 8, 13, 18, 20 },
	{ 3, 0, 7, 8, 10 },
	{ 4, 11, 0, 10, 7 },
	{ 6, 6, 7, 0, 11 },
	{ 10, 6, 2, 1, 0 }
};

int optimal(int c);

void minimum(int vertex)	//���� ��� ���
{
	int m;
	bag[vertex] = 1;	//bag[����] = 1

	printf("%d -> ", vertex + 1);

	m = optimal(vertex);	//����ġ�� �ּ��� ���� ��ȯ

	if (m == 999)	//���ǹ�
	{
		m = 0;
		printf("%d", m + 1);
		sum += w[vertex][m];
		return;
	}

	minimum(m);
}

int optimal(int c)	//���� ��� Ž��
{
	int i;
	int opN = 999;
	int min = 999;
	int minL;

	for (i = 0; i < SIZE; i++)
	{
		if ((w[c][i] != 0) && (bag[i] == 0))	//���[c][0-4] 0�� �ƴϰ� bag ���� 0�϶�
			if (w[c][i] + w[i][c] < min)	//���� 2���� �ֹ��� ����ġ < �ּҰ��̸�
			{
				min = w[i][0] + w[c][i];	//min�� �ּҰ� ����
				minL = w[c][i];
				opN = i;
			}
	}

	if (min != 999)	//����ġ�� ����
		sum += minL;

	return opN;
}

int main()
{
	printf("\n���� ȸ��:\n");
	minimum(0); //������ �������� 0�� ����

	printf("\n\n���� ȸ���� �� ��: %d\n\n", sum);

	return 0;
}
