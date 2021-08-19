# Algorithm-Assignments

## 과제1
Linked list를 이용한 트리 구조 현 및 트리 순회

첫째 줄에는 이진트리의 노드의 개수 N(1≤N≤26)이 주어진다. 둘째 줄부터 N개의
줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의
이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가
없는 경우에는 . 으로 표현된다.

<img width="303" alt="20200903_222928_1" src="https://user-images.githubusercontent.com/20348923/129744402-a597193a-28d8-4399-b2dc-46fa7ad8c4f7.png">

<img width="268" alt="20200909_002655" src="https://user-images.githubusercontent.com/20348923/129744405-a7e257af-a5e9-4049-8c29-137cb6a07124.png">

## 과제3
    12 70 30 20 55 25 40 
을 입력으로 주면 이 숫자들이 선택정렬, 버블정렬, 삽입정렬, 병합정렬, 퀵정렬, 힙정렬로 정렬되게 했다. 정렬 알고리즘별로 처음 5개 step과 결과를 출력했다.

선택정렬

<img width="261" alt="20200918_232040_1" src="https://user-images.githubusercontent.com/20348923/129745395-d5568eb6-0e7e-41c3-a539-a7f01acc913b.png">

버블정렬

<img width="246" alt="20200918_232040_2" src="https://user-images.githubusercontent.com/20348923/129745396-34627c48-f6cc-4068-a007-eed62fa836c1.png">

삽입정렬

<img width="237" alt="20200918_232040_3" src="https://user-images.githubusercontent.com/20348923/129745401-6c16bba4-3ba8-4621-89f2-b56bafe71239.png">

병합정렬

<img width="233" alt="20200918_232040_4" src="https://user-images.githubusercontent.com/20348923/129745404-8ab8a97a-00b9-43e9-82cd-443f4e27ae7f.png">

퀵정렬

<img width="249" alt="20200918_232040_5" src="https://user-images.githubusercontent.com/20348923/129745408-e3ee953f-4c0d-4ae0-aedd-138bdefdaf28.png">

힙정렬

<img width="251" alt="heap new -1" src="https://user-images.githubusercontent.com/20348923/129746490-03370361-2108-4d52-809e-98ab22edcf85.png">

## 과제5
크기가 13인 해시 테이블이 해시 함수로 h(x) = x mod 13을 사용한다. 충돌 해결은 개방 주소 방법의 선형 조사를 택한다. 원소 

    10, 20, 30, 40, 33, 46, 50, 60 
을 차례로 저장 후 해시 테이블의 모양

<img width="187" alt="20201003_142640_1" src="https://user-images.githubusercontent.com/20348923/129747282-51068f14-34a6-4ca0-822c-4410273698cb.png">

<img width="139" alt="20201003_142640_2" src="https://user-images.githubusercontent.com/20348923/129747284-14c6a645-9308-47e8-87a5-05e1734d32fc.png">

체이닝을 이용하여 원소들이 저장되는 해시 테이블을 구현했다.

<img width="280" alt="20201003_143039_3" src="https://user-images.githubusercontent.com/20348923/129747285-a4118cb3-cd7c-43b4-b5e6-16b4d9145efa.png">

<img width="280" alt="20201003_143039_4" src="https://user-images.githubusercontent.com/20348923/129747286-70ae30e9-ec2e-40dc-baad-e2223155db9b.png">

## 과제6
트리 표현을 이요한 두 집합이 있다. (a)의 두 집합을 합친 다음 (b)의 두 집합을 합치고, 마지막으로 이들의 결과로 만들어진 두 집합을 합친다. 랭크를 이용한 Union을 사용했다.

![20210817_235035](https://user-images.githubusercontent.com/20348923/129748674-709c987e-25ae-42cb-bef9-68bc3ea1429e.png)

<img width="295" alt="20201009_152101_4" src="https://user-images.githubusercontent.com/20348923/129747969-d52f273e-2c8c-4cbd-8437-6cf63fc25542.png">

## 과제7
다음과 같이 행렬 W로 표현되어 있는 가중치 포함 방향 그래프에서 최적 회로(최적 일주 경로)를 수행되는 절차, 단계별로 보였다.

![20210817_235447](https://user-images.githubusercontent.com/20348923/129749422-9475e733-aaa0-4773-81b9-c2d25282ad9a.png)

<img width="459" alt="20201026_113312_1" src="https://user-images.githubusercontent.com/20348923/129749059-ea046497-2280-41b7-b3c9-c8e1d2b52dcc.png">

## 과제8

![20210817_235614](https://user-images.githubusercontent.com/20348923/129749791-2f21eae4-6fa3-451c-9104-06f26ce31a55.png)

주어진 그림에서 모든 쌍 최단 경로를 구했다.
D: 최단거리의 길이가 포함된 배열
P: 정점 중에서 가장 큰 인덱스

<img width="366" alt="20201031_141707_4" src="https://user-images.githubusercontent.com/20348923/129749912-1fbfbe7e-849a-4565-bc88-c88e760d96cf.png">

Floyd 알고리즘을 사용하여 모든 쌍의 최단 경로를 구했다.

<img width="264" alt="20201031_141707_5" src="https://user-images.githubusercontent.com/20348923/129749916-4df6b043-feea-4da2-9b9c-1710fa6aa8cc.png">

그래프에서 v1,v2...v7을 a7 ,a6...a1로 바꾸어서 모든 쌍의 최단 경로를 다시 해결 한 후 a5에서 a2로 가는 최단거리 경로를 구했다.

<img width="264" alt="20201031_141707_6" src="https://user-images.githubusercontent.com/20348923/129749920-4bde9a3d-522b-401d-9d82-d46233964d1a.png">

## 과제 9

![image](https://user-images.githubusercontent.com/20348923/130087251-d228b561-2ff0-442f-b17c-8c659df9afdd.png)

위의 그래프를 이용해 최소 신장 트리를 구한다. 프림 알고리즘과 크루스칼 알고리즘으로 구현했다.

Prim's algorithm

<img width="374" alt="20201106_155338_2" src="https://user-images.githubusercontent.com/20348923/130086864-b67b3ce4-980e-4556-976a-fac1e5771228.png">

Kruskal's algorithm

<img width="306" alt="20201106_155338_1" src="https://user-images.githubusercontent.com/20348923/130086869-2b5ef8c8-4892-4789-b3c8-e3647d1c11f7.png">

## 과제 10

Backtracking 알고리즘을 사용하여 아래의 Sum-of-Subset 문제를 해결한다. W=52의 합을 구하는 모든 숫자의 조합을 구한다.

![image](https://user-images.githubusercontent.com/20348923/130088176-8e1b0a62-cd1c-442e-832c-958d5e948a36.png)

구하는 과정을 스텝별로 나타냈다.

<img width="394" alt="20201114_213755_1" src="https://user-images.githubusercontent.com/20348923/130088030-52559489-7317-40c0-9ef2-0c4f50f25e6e.png">

Monte Carlo 알고리즘을 사용하여 위의 Backtracking 알고리즘의 효율성을 추정해보았다. 하지만 아직 완벽히 Monte Carlo 알고리즘을 구현하지는 못했다.

<img width="444" alt="20201114_214020_1" src="https://user-images.githubusercontent.com/20348923/130088041-0ad2efd6-63a6-4e4e-873d-5c91a75a5c7b.png">

<img width="400" alt="20201114_214020_2" src="https://user-images.githubusercontent.com/20348923/130088043-d781e6b7-7f05-4456-a43b-81ef5ceb2213.png">

## 과제 11

아래의 Knapsack problem를 해결한다.

![image](https://user-images.githubusercontent.com/20348923/130089058-de5abf91-dc0f-40d5-9620-8e98b0dcaebc.png)

1. Depth-First 알고리즘으로 구현

<img width="348" alt="20201123_204116_1" src="https://user-images.githubusercontent.com/20348923/130088955-6dbdcbfa-6574-414b-8901-924349bf8beb.png">

2. Breadth-First 알고리즘으로 구현

<img width="406" alt="20201123_204116_2" src="https://user-images.githubusercontent.com/20348923/130088958-0190fdae-04a3-46ab-b464-c3cfcc668d3f.png">

3. Best-First 알고리즘으로 구현

<img width="454" alt="20201123_204116_3" src="https://user-images.githubusercontent.com/20348923/130088960-f509c916-ce17-4a77-be1a-b893f64b9b4a.png">
