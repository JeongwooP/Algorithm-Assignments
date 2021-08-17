#pragma warning(disable: 4996)	//C4996 에러를 처리하기 위한 전처리기 포함

#include <stdio.h>	//전처리기로 헤더파일들 포함
#include "Tree.h"

TreeNode * root;	//root라는 전역 구조체 선언

int main(void)	//main 함수
{
	int n;	//정수형 변수 n 선언
	scanf("%d", &n);	//정수 입력 받음
	getchar();			//getchar()로 문자를 입력받음
	if (n < 1 || n > 26) {	//만약 n이 1 이상, 26이하가 아니면 경고 출력 후 종료
		printf("1 이상, 26이하의 값을 입력하시오.\n");
		exit(0);
	}
		

	for (int i = 0; i < n; i++)	//n만큼 반복
	{
		char parent, leftChild, rightChild;	//문자형 변수 3개 선언
		scanf("%c %c %c", &parent, &leftChild, &rightChild);	//3개의 문자형 변수 입력받음
		getchar();	//문자를 하나 입력 받음

		func(root, parent, leftChild, rightChild);	//func함수로 루트 노드, 3개의 문자형 변수를 전달함
	}
	treeInOrder(root);	//root노드의 중위순회를 실행시킴, 출력함
	printf("\n");	//줄바꿈 출력
}