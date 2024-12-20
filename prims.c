#include<stdio.h> 
#include<conio.h>
int n, cost[10][10];
void prim() {
	int i, j, startVertex, endVertex;
	int k, nr[10], temp, minimumCost = 0, tree[10][3];
	temp = cost[0][0];
	for (i = 0; i < n; i++) { 
		for (j = 0; j < n; j++) {
		if (temp > cost[i][j]) {
			temp = cost[i][j]; 
			startVertex = i; 
			endVertex = j;
			}
		}
	}
	tree[0][0] = startVertex;
	tree[0][1] = endVertex; 	
	tree[0][2] = temp; 
	minimumCost = temp;

	for (i = 0; i < n; i++) {
	if (cost[i][startVertex] < cost[i][endVertex]) 
		nr[i] = startVertex;
	else
		nr[i] = endVertex;
	}
	nr[startVertex] = 100;
	nr[endVertex] = 100;
	temp = 99;
	for (i = 1; i < n - 1; i++) {
		for (j = 0; j < n; j++) {
			if (nr[j] != 100 && cost[j][nr[j]] < temp) { 
				temp = cost[j][nr[j]];
				k = j;
			}
		}
	tree[i][0] = k;
	tree[i][1] = nr[k]; 
	tree[i][2] = cost[k][nr[k]];
	minimumCost = minimumCost + cost[k][nr[k]]; 
	nr[k] = 100;

	for (j = 0; j < n; j++) {
		if (nr[j] != 100 && cost[j][nr[j]] > cost[j][k]) nr[j] = k;
	}
	temp = 99;
	}
	printf("\nThe min spanning tree is:- ");
	for (i = 0; i < n - 1; i++) { 
		for (j = 0; j < 3; j++)
			printf("%d", tree[i][j]); 
		printf("\n");
	}
	printf("\nMin cost : %d", minimumCost);
}
void main() { 
	int i, j; 
	printf("\nEnter the no. of vertices :"); 
	scanf("%d", &n);
	printf("\nEnter the costs of edges in matrix form :");
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) {
			scanf("%d", &cost[i][j]);
		}
	printf("\nThe matrix is : "); 
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) { 
			printf("%d\t", cost[i][j]);
		}
		printf("\n");
	}
	prim();
	//getch();
}
