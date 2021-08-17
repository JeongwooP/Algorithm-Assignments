#ifndef __T__	//��ó����� ������� �ߺ� ����
#define __T__

#include <stdio.h>	//��ó����� ���� ��� ���� ���Խ�Ŵ
#include <stdlib.h>
#include <stdbool.h>

typedef struct _TreeNode {	//_TreeNode ����ü�� �����մϴ�.
	char value;			//������, ��
	struct _TreeNode * left;	//���� �ڽ� ���
	struct _TreeNode * right;	//������ �ڽ� ���
} TreeNode;	//TreeNode�� �θ� �� ����

TreeNode * newnode(char data);	//newnode �Լ� ���� ����

void treeInOrder(TreeNode *root); //treeInOrder �Լ� ���� ����
bool searchNode(TreeNode* node, char key);	//searchNode �Լ� ���� ����
void func(TreeNode* copy, char a, char b, char c);	//func �Լ� ���� ����


#endif