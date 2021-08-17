#ifndef __T__	//전처리기로 헤더파일 중복 방지
#define __T__

#include <stdio.h>	//전처리기로 여러 헤더 파일 포함시킴
#include <stdlib.h>
#include <stdbool.h>

typedef struct _TreeNode {	//_TreeNode 구조체를 선언합니다.
	char value;			//데이터, 값
	struct _TreeNode * left;	//왼쪽 자식 노드
	struct _TreeNode * right;	//오른쪽 자식 노드
} TreeNode;	//TreeNode로 부를 수 있음

TreeNode * newnode(char data);	//newnode 함수 원형 선언

void treeInOrder(TreeNode *root); //treeInOrder 함수 원형 선언
bool searchNode(TreeNode* node, char key);	//searchNode 함수 원형 선언
void func(TreeNode* copy, char a, char b, char c);	//func 함수 원형 선언


#endif