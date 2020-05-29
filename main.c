#include <stdio.h>
#include <stdbool.h>
#include "q.h"

#define MAX_NODE 5

int adj_mat[MAX_NODE][MAX_NODE] = {
	0,1,1,0,1,
	1,0,1,0,0,
	1,1,0,1,1,
	0,0,1,0,1,
	1,0,1,1,0
};
bool visited[MAX_NODE];

void init(void) {

	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
	}
}

// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(int v) {

	visited[v] = true;		// 정점 v의 방문 표시 
	printf("정점 %d 방문\n", v);		// 방문한 정점 출력
	for (int w = 0; w < MAX_NODE; w++) { 		// 인접 정점 탐색
		if (adj_mat[v][w] && !visited[w]) {
			dfs_mat(w);	//정점 w에서 DFS 새로 시작
			continue;
		}
		if (adj_mat[v][w] && visited[w])
			printf("\t정점 %d에서 탐색: 정점 %d는 이미 방문했음\n", v, w);
	}
}

void bfs_mat(int v) {

	ListLinQueue q;
	init_queue(&q);     			// 큐 초기화 
	visited[v] = true;        		// 정점 v 방문 표시 
	printf("정점 %d 방문\n", v);
	enqueue(&q, v);			// 시작 정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);	// 큐에 정점 추출 
		for (int w = 0; w < MAX_NODE; w++) { // 인접 정점 탐색 
			if (adj_mat[v][w] && !visited[w]) {
				visited[w] = true;	// 방문 표시
				printf("정점 %d 방문\n", w);
				enqueue(&q, w); 	// 방문한 정점을 큐에 저장
				continue;
			}
			if (adj_mat[v][w] && visited[w]) {
				printf("정점 %d에서 탐색: 정점 %d은 이미 방문했음\n", v, w);
			}
		}
	}
}


int main(void) {
	//init();
	//printf("깊이 우선 탐색\n");
	//dfs_mat(0);
	init();
	printf("\n너비 우선 탐색\n");
	bfs_mat(0);
	printf("\n");
	return 0;
}
