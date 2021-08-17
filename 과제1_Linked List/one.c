#pragma warning(disable: 4996)	//C4996 ������ ó���ϱ� ���� ��ó���� ����

#include <stdio.h>	//��ó����� ������ϵ� ����
#include "Tree.h"

TreeNode * root;	//root��� ���� ����ü ����

int main(void)	//main �Լ�
{
	int n;	//������ ���� n ����
	scanf("%d", &n);	//���� �Է� ����
	getchar();			//getchar()�� ���ڸ� �Է¹���
	if (n < 1 || n > 26) {	//���� n�� 1 �̻�, 26���ϰ� �ƴϸ� ��� ��� �� ����
		printf("1 �̻�, 26������ ���� �Է��Ͻÿ�.\n");
		exit(0);
	}
		

	for (int i = 0; i < n; i++)	//n��ŭ �ݺ�
	{
		char parent, leftChild, rightChild;	//������ ���� 3�� ����
		scanf("%c %c %c", &parent, &leftChild, &rightChild);	//3���� ������ ���� �Է¹���
		getchar();	//���ڸ� �ϳ� �Է� ����

		func(root, parent, leftChild, rightChild);	//func�Լ��� ��Ʈ ���, 3���� ������ ������ ������
	}
	treeInOrder(root);	//root����� ������ȸ�� �����Ŵ, �����
	printf("\n");	//�ٹٲ� ���
}