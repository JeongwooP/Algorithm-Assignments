#include <stdio.h>	//여러 헤더파일들을 전처리기로 포함시킴
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"

extern TreeNode * root = NULL;	//root라는 노드를 전역변수로 extern해서 one.c에서 가져옵니다.
TreeNode * tempRoot = NULL;		//임시 노드 root를 만들어서 노드를 탐색할때 임시 저장소 처럼 사용합니다.

TreeNode * newnode(char data)	//newNode라는 새로운 노드를 추가하는 함수를 작성했습니다.
{
	TreeNode *p; // p라는 노드를 하나 선언합니다.
	p = (TreeNode*)malloc(sizeof(TreeNode)); // 노드 p 에다 공간을 할당할 수 있게 했습니다.
	p->value = data; //노드 p 에다 data값을 대입하는 연산입니다.
	p->left = NULL; //p노드의 왼쪽 자식에 NULL을 대입했습니다.
	p->right = NULL;	//p노드의 오른쪽 자식에 NULL을 대입했습니다.

	return(p); // 새롭게 만들어진 노드를 반환하게 만들었습니다.
}

void func(TreeNode* copyRoot, char a, char b, char c) {	//func함수로 트리를 만들도록 했습니다. 

	if (copyRoot == NULL) {	//copyRoot가 NULL즉 아무것도 만들어지지 않았을때 if문을 들어갑니다.
		copyRoot = newnode(a);	//새로운 노드를 생성합니다. 이를 copyRoot에 저장합니다.
		copyRoot->left = newnode(b);	//노드의 왼쪽 자식을 생성합니다.
		copyRoot->right = newnode(c);	//노드의 오른쪽 자식을 생성합니다.
		root = copyRoot;	//root에는 copyRoot가 자리잡게 합니다.
	}
	else if (b == '.') {	//만약 점이 들어간 자리라면 else if문을 들어갑니다.
		searchNode(copyRoot, a);	//copyRoot를 기준으로 첫번째 들어온 문자로 부모 노드를 찾습니다.
		tempRoot->right = newnode(c);	//tempRoot의 오른쪽 자식에만 새로운 노드를 생성합니다.
	}
	else if (c == '.') {  //만약 점이 들어간 자리라면 else if문을 들어갑니다.
		searchNode(copyRoot, a);	//copyRoot를 기준으로 첫번째 들어온 문자로 부모 노드를 찾습니다.
		tempRoot->left = newnode(b); //tempRoot의 왼쪽 자식에만 새로운 노드를 생성합니다.
	}
	else {
		searchNode(copyRoot, a);	//만약 점이 하나도 없는 문자 3개라면 else 문을 들어갑니다.
		tempRoot->left = newnode(b);	//일반적이게 왼쪽 자식 노드를 생성합니다.
		tempRoot->right = newnode(c);	//오른쪽 자식 노드를 생성합니다.
	}
}

void treeInOrder(TreeNode *root)	//트리를 중위 순회 방식으로 출력하는 treeInOrder 함수를 만들었습니다.
{
	if (root != NULL) // root노드가 NULL이 아닌지 확인합니다. NULL이 아니면 if문을 수행합니다.
	{
		treeInOrder(root->left); // root노드의 왼쪽 자식을 방문합니다.
		if (root->value == '.')	//만약 root의 값이 (.)점이라면 아무것도 출력하지 않게 했습니다.
			printf("");
		else
			printf("%c", root->value); // root노드의 값을 출력하게 했습니다.
		treeInOrder(root->right);// root노드의 오른쪽 자식을 방문합니다.
	}
}

// 트리에서의 탐색 기능을 할 수 있는 search함수를 만들었습니다. 원래 있으면 true, 없으면 false 값을 반환해서 순환적이게 만들었습니다.
bool searchNode(TreeNode* node,char key)	//search함수로 첫번째 알파벳이 넘어와 해당 노드를 찾고 왼쪽,오른쪽 자식을 만들 수 있게 tempRoot에 node를 대입합니다.
{
	if (node == NULL)	//만약 노드가 없어서 NULL을 가진다면 false를 반환합니다.
		return false;

	if (node->value == key) { //만약 노드의 값이 key값과 같으면 임시노드인 tempRoot에 노드를 넣고, true를 반환합니다.
		tempRoot = node;
		return true;	
	}


	bool b1 = searchNode(node->left, key); //왼편의 서브트리에 계속 반복해서 탐색합니다.

	if (b1) return true; // 노드가 찾아지면 더 이상 볼 필요가 없게 true를 반환합니다.

						
	bool b2 = searchNode(node->right, key); //만약 왼편에서 찾지 못했으니 오른편 서브트리를 탐색합니다.

	return b2;	//b2를 반환합니다.
}