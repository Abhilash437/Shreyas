#include<stdio.h>
#include<stdlib.h>

int cnt=0,count=0;

int insert(int *a,int n)
{
	int cnter=0;
	for(int i=n/2;i>=1;i--)
	{
		int k=i;
		int v=a[k];
		int heap=0;
		while(heap!=1 && 2*k<=n)
		{
			int j=2*k;
			if(j<n)
			{
				cnter++;
				if(a[j+1]>a[j])
				 j++;	
			}
			cnter++;
			
			if(v>=a[j])
				heap=1;
			else
			{
				a[k]=a[j];
				k=j;
			}
				
		}
		a[k]=v;
	}
	return cnter;
}

int delete(int *a,int n)
{
	int size=n,cnter=0,v;
	
	for(int i=0;i<size-1;i++)
	{
		int temp=a[1];
		a[1]=a[n];
		a[n]=temp;
		n--;
		int k=1;
		v=a[k];
		int heap=0;
		
		while(heap!=1 && 2*k<=n)
		{
			int j=2*k;
			if(j<n)
			{
				cnter++;
				if(a[j+1]>a[j])
				 j++;	
			}
			cnter++;
			
			
			if(v>=a[j])
				heap=1;
			else
			{
				a[k]=a[j];
				k=j;
			}
				
		}
		a[k]=v;	
	}
	printf("Counter : %d\n",cnter);
}

void analysis(int ch)
{
	
	FILE *f;
	
	for(int i=10;i<=100;i+=10)
	{
		int *b=(int *)malloc(sizeof(int)*(i+1));
		int *w=(int *)malloc(sizeof(int)*(i+1));
		
		for(int j=1;j<i;j++)
		{
			b[i]=i-j;
			w[i]=j;
		}
		
		switch(ch)
		{
			case 1:
				f=fopen("best.txt","a");
				count=insert(b,i-1);
				fprintf(f,"%d\t%d\n",i-1,count);
				break;
			case 2:
				f=fopen("worst.txt","a");
				count=insert(w,i-1);
				fprintf(f,"%d\t%d\n",i-1,count);
				break;
			case 3:
				//cnt=insert(b,i-1);
				f=fopen("delete.txt","a");
				cnt=delete(w,i-1);
				fprintf(f,"%d\t%d\n",i-1,cnt);
				break;
		}
		count=0;
		cnt=0;
		fclose(f);
		
	}
}

void main()
{
	system("rm -r *.txt");
	int ch;
	
	while(1)
	{
		printf("1.Best\n2.Worst\n3.Deletion\n");
			scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			case 2:
			case 3:
				analysis(ch);
				break;
			default:
				exit(1);
		}
		
	}
}
