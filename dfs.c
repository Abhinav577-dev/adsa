#include<stdio.h>
void DFS(int [20][20],int,int [20],int);
void main()
{
	int n,a[20][20],i,j,visited[20],source;
	// clrscr();
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("\nEnter the source node:");
	scanf("%d",&source);
	DFS(a,source,visited,n);
	for(i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			printf("\nGraph is not connected");
			// getch();
			//exit(0);
		}
	else {
		printf("\nGraph is connectd\n");
		
	}
		
	}
	
	printf("\nGraph is connectd\n");
	
}
void DFS(int a[20][20],int u,int visited[20],int n)
{
	int v;
	visited[u]=1;
	for(v=1;v<=n;v++)
	{
		if(a[u][v]==1 && visited[v]==0)
			DFS(a,v,visited,n);
	}
}
