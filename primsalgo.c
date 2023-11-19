#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 10
int n,v,i,count;
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int graph[n][n])
{
    printf("Edge \tWeight\n");
    for (i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i,
               graph[i][parent[i]]);
}
 
void primMST(int graph[n][n])
{
    int parent[n];
    int key[n];
    bool mstSet[n];
	for (i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1; 
    for (count = 0; count < n - 1; count++) 
	
	{
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (v = 0; v < n; v++)
        {
        	if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
		}      
    }
    printMST(parent, graph);
}
int main()

{
    int e, i, j, m, l, w;
	printf("Enter no of vertices and edges: ");
	scanf("%d%d",&n, &e);
	int graph[n][n];
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			graph[i][j] = 0;
		}
	}
	for(i=0; i<e; i++){
	 	printf("Enter two vertices and edge cost: ");	
	 	scanf("%d%d%d", &m, &l, &w);
	 	 graph[m-1][l-1] = w;
	 	 graph[l-1][m-1] = w;
  }
    primMST(graph);
    return 0;
}
