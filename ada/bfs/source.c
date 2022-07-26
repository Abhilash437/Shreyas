#include<stdio.h>
#include<stdlib.h>

int count=0,cycle;

typedef struct 
{
	int v;
	int flag;
}n;

typedef struct
{
	n items[100];
	int f,r;
}Que;

Que q;

void enqueue(int i)
{
	q.r=q.r+1;
	q.items[q.r].v=i;
	q.items[q.r].flag=0;
		
}
void dequeue(int i)
{
	q.f++;
}

void bfs(int n,int *a[n],int v,int vis[])
{
	
	//Que q;
	q.f=0;
	q.r=-1;
	count++;
	vis[v]=count;
	enqueue(v);
	printf("%d - %d\n",v,count);
	
	while(q.f<=q.r)
	{
		q.items[q.f].flag=1;
		for(int i=0;i<n;i++)
		{
			if (a[q.items[q.f].v][i]==1)
			{
				if(vis[i]==0)
				{
					count++;
					vis[i]=count;
					printf("%d - %d\n",i,count);
					enqueue(i);
					
				}
				else if(q.items[q.items[i].v].flag==0)
				 cycle++;
			}
		}
		dequeue(v);
	}
	
}

void BFS(int n,int *a[n])
{
	int vis[n+1],connected=0;
	
	for(int i=0;i<n;i++)
		vis[i]=0;
		
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			printf("BFS tree: %d\n",connected+1);
			bfs(n,a,i,vis);
			connected++;
		}
	}	
	
	if(connected>1)
		printf("DISCONNECTED GRAPH\n");
	else
		printf("CONNECTED GRAPH\n");
		
	if(cycle>0)
		printf("GRAPH IS CYCLIC\n");
	else
		printf("GRAPH IS ACYCLIC\n");	
}

void main()
{
	int v;
	
	printf("Enter the no of vertices\n");
		scanf("%d",&v);
	int *a[v];
	
	for(int i=0;i<v;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*v);
		q.items[i].flag=-1;
	}
	printf("Enter the matrix\n");
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			scanf("%d",&a[i][j]);
	BFS(v,a);
}



