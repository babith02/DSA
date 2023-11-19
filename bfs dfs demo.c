#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Queue{
	int data;
	struct Queue* next;
}*front,*rear,*temp;
void Enqueue(int);
int Dequeue();
void Display();
struct stack{
	int data;
	struct stack* link;
}*top;
void push(int);
int pop();
struct mygraph{
    int numnodes;
    bool **edges;
};
typedef struct mygraph graph;
graph* create_graph(int numnodes);
void destroy_graph(graph* g);
void print_graph(graph* g);
bool add_edge(graph *g,int from_node,int to_node);
bool remove_edge(graph *g,int from_node,int to_node);
bool has_edge(graph *g,int from_node,int to_node);
void Depth_First_Traversal(graph* g,int visited[],int vertex);
void Breadth_First_Traversal(graph* g,int visited[],int vertex,int arr[],int* index,int* count);
graph* create_graph(int numnodes)
{
    graph* g=malloc(sizeof(*g));
    g->numnodes=numnodes;
    g->edges=calloc(sizeof(bool*),g->numnodes);
    for(int i=0;i<g->numnodes;i++)
    {
        g->edges[i]=calloc(sizeof(bool),g->numnodes);
    }
    return g;
}
void destroy_graph(graph* g)
{
    for(int i=0;i<g->numnodes;i++)
    {
        if(g->edges[i]!=NULL)
        {
            free(g->edges[i]);
        }
    }
    free(g->edges);
    free(g);
}
bool add_edge(graph* g,int from_node,int to_node)
{
    if(has_edge(g,from_node,to_node))
        return false;
    g->edges[from_node][to_node]=true;
    return true;
}
bool remove_edge(graph* g,int from_node,int to_node)
{
    if(has_edge(g,from_node,to_node)){
        g->edges[from_node][to_node]=false;
        return true;
    }
    return false;
}
bool has_edge(graph* g,int from_node,int to_node)
{
    return g->edges[from_node][to_node];
}
void print_graph(graph *g)
{
    printf("\nDIGRAPH:\n");
    for(int from=0;from<g->numnodes;from++)
    {
        for(int to=0;to<g->numnodes;to++)
        {
                if(g->edges[from][to])
                {
                    printf("%d->%d\n",from,to);
                }
        }
    }
    printf("\n");
}
void Depth_First_Traversal(graph* g,int visited[],int vertex)
{
    //----------------using stack--------------------
    push(vertex);
    while(!isempty1())
    {
        int node=pop();
        if(!visited[node]){
     printf("%d\t",node);
    visited[node]=1;
    for(int j=0;j<g->numnodes;j++)
    {
        if(!visited[j] && g->edges[node][j])
        {
            push(j);
        }
    }
        }
    }


}
bool Linear_search(int arr[],int key,int size)
{
    for(int i=0;i<=size;i++)
        if(arr[i]==key)
            return true;
    return false;

}
void Breadth_First_Traversal(graph* g,int visited[],int vertex,int arr[],int* index,int* count)
{
    printf("%d\t",vertex);
    visited[vertex]=1;
    Enqueue(vertex);
    while(!isempty())
    {
        int node=Dequeue();
        for(int j=0;j<g->numnodes;j++)
        {
            if(!visited[j] && g->edges[node][j]){
                    printf("%d\t",j);
                    visited[j]=1;
                    Enqueue(j);
            }
        }
    }
}
int main()
{
    front=NULL;
	rear=NULL;
    int numnodes,ch,from,to,index=-1,count=0;
    bool ret_val;
    printf("Enter the max values of nodes:");
    scanf("%d",&numnodes);
    graph *g1=create_graph(numnodes);
    //printf("%d\t",g1->numnodes);
     int visited[numnodes];
    int arr[g1->numnodes];
    printf("\n1.Add edge\n2.Remove edge\n3.Display\n4.Breadth First Traversal\n5.Depth_First_Traversal\n5.Exit\n");
    do{
    printf("\nEnter the choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("---ADDING EDGES---\n");
        printf("Enter the FROM node and TO node:\n");
        scanf("%d%d",&from,&to);
        ret_val=add_edge(g1,from,to);
        if(ret_val)
            printf("Edge added\n");
        else
            printf("Edge not added\n");
        break;
    case 2:
        printf("---REMOVING EDGES---\n");
        printf("Enter FROM node and TO node:");
        scanf("%d%d",&from,&to);
        ret_val=remove_edge(g1,from,to);
        if(ret_val)
            printf("Edge removed\n");
        else
            printf("Edge does not exit to be removed\n");
        break;
    case 3:
        printf("---DISPLAYING---");
        print_graph(g1);
        break;
    case 4:
        printf("---BFS TRAVERSAL---");
        printf("\nEnter the vertex of traversal:\n");
        scanf("%d",&from);
        memset(visited,0,numnodes*sizeof(int));
        Breadth_First_Traversal(g1,visited,from,arr,&index,&count);
        break;
    case 5:
        printf("--- DFS TRAVERSAL---");
        printf("\nEnter the vertex of traversal:\n");
        scanf("%d",&from);
        memset(visited,0,g1->numnodes*sizeof(int));
        Depth_First_Traversal(g1,visited,from);
        break;
    case 6:
        break;
    default:
        printf("Invalid choice!!\n");
    }}while(ch!=6);
   // print_graph(g1);
    destroy_graph(g1);
}
void Enqueue(int x)
{
	 temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->data=x;
	temp->next=NULL;
	if(rear==NULL && front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else{
		rear->next=temp;
		rear=temp;
	}
}
int Dequeue()
{
	 if(front==rear)
    {
        int item=front->data;
        front=NULL;
        rear=NULL;
        return item;
    }
	if(front==NULL){
		printf("Queue is empty\n");
		return NULL;}
	int item=front->data;
	temp=front;
	front=front->next;
	return item;

}
int isempty()
{
    if(front==NULL)
		return 1;
    return 0;
}
void push(int item)
{
	struct stack* newnode=(struct stack*)malloc(sizeof(struct stack));
	newnode->data=item;
	newnode->link=top;
	top=newnode;
}
int pop()
{
	int item;
	item=top->data;
	top=top->link;
	return item;
}
int isempty1()
{
    if(top==NULL)
        return 1;
    return 0;
}
