#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;

void split(int *a,int *left1,int *right1,int l,int m,int h)
{
	int i,j;
	for(i=0;i<m-l;i++)
		left1[i]=a[2*i];
	for(j=0;j<h-m;j++)
		right1[j]=a[2*i+1];
}

void join(int *a,int *left1,int *right1,int l,int m,int h)
{
	int i,j;
	for( i=0;i<=m-l;i++)
		a[i]=left1[i];
	for( j=0;j<h-m;j++)
		a[i+j]=right1[j];
		
}

void merge(int *a,int l,int m,int h)
{
	int b[101];
	int k=0;
	int i=l;
	int j=m+1;
	
	while(i<=m && j<=h)
	
	{
		count++;
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=m)
	{
		//count++;
		b[k++]=a[i++];
	}
	while(j<=h)
	{
		//count++;
		b[k++]=a[j++];
	}
	for(int l=0;l<=h;l++)
		a[l]=b[l];
}
void mergesort(int *a,int l,int h)
{
	int m=(l+h)/2;
	
	if(l<h)
	{
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

void generateworst(int *a,int l,int h)
{
	
		int m= l+(h-l)/2;
	if(l<h)
	{
		int left1[m-l+1];
		int right1[h-m];
		
		split(a,left1,right1,l,m,h);

		generateworst(left1,l,m);
		generateworst(right1,m+1,h);
		
		join(a,left1,right1,l,m,h);
	}
}
void analysis(int ch)
{
	int i,j;
	FILE *fp;
	srand(time(NULL));
	
	for(i=10;i<=100;i+=10)
	{
		int *a=(int *)malloc((i+1)*sizeof(int));
		int *b=(int *)malloc((i+1)*sizeof(int));
		int *w=(int *)malloc((i+1)*sizeof(int));
		
		for(j=0;j<i;j++)
		{
			b[j]=j;
			w[j]=j;
			a[j]=rand()%100;
		}
		
		switch(ch)
		{
			case 1:
				fp=fopen("best.txt","a");
				mergesort(b,0,i-1);
				break;
			case 2:
				fp=fopen("worst.txt","a");
				generateworst(w,0,i-1);
				mergesort(w,0,i-1);
				break;
			case 3:
				fp=fopen("avg.txt","a");
				mergesort(a,0,i-1);
				break;
					
		}
		fprintf(fp,"%d\t%d\n",i,count);
		count=0;
		//free(a);
		//free(b);
		//free(w);
		fclose(fp);
	}
}

void main()
{
	int ch;
	system("rm -r *.txt");
	while(1)
	{
		printf("Press 1 for best case\n");
		printf("Press 2 for worst case\n");
		printf("Press 3 for avg case\n");
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
