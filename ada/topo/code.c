#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int f,r,cnt,*arr;
}Que;

int count=0;

void indeg(int v,int *a[v],int *flag,Que *q,int *inq)
{
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
		{
			count++;
			if(a[j][i]==1)
				inq[i]++;
			if(inq[i]==0 && flag[i]==0)
			{
				q->r=q->r+1;
				q->arr[q->r]=i;
				flag[i]=1;
				q->cnt++;
			}
		}
}

void sourceremoval(int v,int *a[v],int *flag,Que *q,int *inq)
{
	while(q->cnt!=0)
	{
		int source=q->arr[q->f];
		q->f=q->f+1;
		q->cnt--;
		printf("%d\t",source+1);
		//count++;
		for(int i=0;i<v;i++)
		{
			count++;
			if(a[source][i]==1){
				//count++;
				inq[i]=inq[i]-1;
			}
			if(inq[i]==0 && flag[i]==0)
			{
				//count++;
				q->r=q->r+1;
				q->arr[q->r]=i;
				q->cnt++;
				flag[i]=1;
		
			}
		}
	}
}


void main()
{
	int v;
		printf("Enter the number of vertices\n");
			scanf("%d",&v);
		int *a[v];
		for(int i=0;i<v;i++)	
			a[i]=(int *)malloc(sizeof(int)*v);
		
		printf("Enter the adjacnecy matrix\n");
			for(int i=0;i<v;i++)
				for(int j=0;j<v;j++)
					scanf("%d",&a[i][j]);
		Que q;
		q.f=0;
		q.r=-1;
		q.cnt=0;
		
		int *inq=(int *)malloc(sizeof(int)*v);
		q.arr=(int *)malloc(sizeof(int)*v);
		for(int i=0;i<v;i++)
			inq[i]=0;
			
		int *flag=(int *)malloc(sizeof(int)*v);
		
		for(int i=0;i<v;i++)
			flag[i]=0;
		indeg(v,a,flag,&q,inq);
		printf("Count for indeg: %d\n",count);
		
		count=0;
		
		printf("Topological sorting is:\n");
		sourceremoval(v,a,flag,&q,inq);
		printf("\n");
		
		/*while(q.f<=q.r)
		{
		
			printf("%d ",q.arr[q.f++]);
		
		}*/
		printf("Count for source_rem: %d\n",count);
		printf("\n");
}
