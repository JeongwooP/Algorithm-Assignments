#include <stdio.h>	//���� ������ϵ��� ��ó����� ���Խ�Ŵ
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"

extern TreeNode * root = NULL;	//root��� ��带 ���������� extern�ؼ� one.c���� �����ɴϴ�.
TreeNode * tempRoot = NULL;		//�ӽ� ��� root�� ���� ��带 Ž���Ҷ� �ӽ� ����� ó�� ����մϴ�.

TreeNode * newnode(char data)	//newNode��� ���ο� ��带 �߰��ϴ� �Լ��� �ۼ��߽��ϴ�.
{
	TreeNode *p; // p��� ��带 �ϳ� �����մϴ�.
	p = (TreeNode*)malloc(sizeof(TreeNode)); // ��� p ���� ������ �Ҵ��� �� �ְ� �߽��ϴ�.
	p->value = data; //��� p ���� data���� �����ϴ� �����Դϴ�.
	p->left = NULL; //p����� ���� �ڽĿ� NULL�� �����߽��ϴ�.
	p->right = NULL;	//p����� ������ �ڽĿ� NULL�� �����߽��ϴ�.

	return(p); // ���Ӱ� ������� ��带 ��ȯ�ϰ� ��������ϴ�.
}

void func(TreeNode* copyRoot, char a, char b, char c) {	//func�Լ��� Ʈ���� ���鵵�� �߽��ϴ�. 

	if (copyRoot == NULL) {	//copyRoot�� NULL�� �ƹ��͵� ��������� �ʾ����� if���� ���ϴ�.
		copyRoot = newnode(a);	//���ο� ��带 �����մϴ�. �̸� copyRoot�� �����մϴ�.
		copyRoot->left = newnode(b);	//����� ���� �ڽ��� �����մϴ�.
		copyRoot->right = newnode(c);	//����� ������ �ڽ��� �����մϴ�.
		root = copyRoot;	//root���� copyRoot�� �ڸ���� �մϴ�.
	}
	else if (b == '.') {	//���� ���� �� �ڸ���� else if���� ���ϴ�.
		searchNode(copyRoot, a);	//copyRoot�� �������� ù��° ���� ���ڷ� �θ� ��带 ã���ϴ�.
		tempRoot->right = newnode(c);	//tempRoot�� ������ �ڽĿ��� ���ο� ��带 �����մϴ�.
	}
	else if (c == '.') {  //���� ���� �� �ڸ���� else if���� ���ϴ�.
		searchNode(copyRoot, a);	//copyRoot�� �������� ù��° ���� ���ڷ� �θ� ��带 ã���ϴ�.
		tempRoot->left = newnode(b); //tempRoot�� ���� �ڽĿ��� ���ο� ��带 �����մϴ�.
	}
	else {
		searchNode(copyRoot, a);	//���� ���� �ϳ��� ���� ���� 3����� else ���� ���ϴ�.
		tempRoot->left = newnode(b);	//�Ϲ����̰� ���� �ڽ� ��带 �����մϴ�.
		tempRoot->right = newnode(c);	//������ �ڽ� ��带 �����մϴ�.
	}
}

void treeInOrder(TreeNode *root)	//Ʈ���� ���� ��ȸ ������� ����ϴ� treeInOrder �Լ��� ��������ϴ�.
{
	if (root != NULL) // root��尡 NULL�� �ƴ��� Ȯ���մϴ�. NULL�� �ƴϸ� if���� �����մϴ�.
	{
		treeInOrder(root->left); // root����� ���� �ڽ��� �湮�մϴ�.
		if (root->value == '.')	//���� root�� ���� (.)���̶�� �ƹ��͵� ������� �ʰ� �߽��ϴ�.
			printf("");
		else
			printf("%c", root->value); // root����� ���� ����ϰ� �߽��ϴ�.
		treeInOrder(root->right);// root����� ������ �ڽ��� �湮�մϴ�.
	}
}

// Ʈ�������� Ž�� ����� �� �� �ִ� search�Լ��� ��������ϴ�. ���� ������ true, ������ false ���� ��ȯ�ؼ� ��ȯ���̰� ��������ϴ�.
bool searchNode(TreeNode* node,char key)	//search�Լ��� ù��° ���ĺ��� �Ѿ�� �ش� ��带 ã�� ����,������ �ڽ��� ���� �� �ְ� tempRoot�� node�� �����մϴ�.
{
	if (node == NULL)	//���� ��尡 ��� NULL�� �����ٸ� false�� ��ȯ�մϴ�.
		return false;

	if (node->value == key) { //���� ����� ���� key���� ������ �ӽó���� tempRoot�� ��带 �ְ�, true�� ��ȯ�մϴ�.
		tempRoot = node;
		return true;	
	}


	bool b1 = searchNode(node->left, key); //������ ����Ʈ���� ��� �ݺ��ؼ� Ž���մϴ�.

	if (b1) return true; // ��尡 ã������ �� �̻� �� �ʿ䰡 ���� true�� ��ȯ�մϴ�.

						
	bool b2 = searchNode(node->right, key); //���� ������ ã�� �������� ������ ����Ʈ���� Ž���մϴ�.

	return b2;	//b2�� ��ȯ�մϴ�.
}