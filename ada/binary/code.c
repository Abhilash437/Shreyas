#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;

void bin(int *a,int key,int low,int high)
{
	int mid = low + (high-low)/2;
	count++;
	
	if(a[mid]==key)
		return;
	else if(a[mid]>key)
		bin(a,key,low,mid-1);
	else
		bin(a,key,mid+1,high);
	
}

void analysis(int ch)
{
	int key,*a,temp,i;
	FILE *f;
	srand(time(NULL));
	
	for(i=10;i<=100;i+=10)
	{
		int *a=(int *)malloc(sizeof(int)*i);
		
		for(int j=0;j<i;j++)
			a[j]=j+1;
			
		switch(ch)
		{
			case 1:
				f=fopen("best.txt","a");
				key=a[(i-1)/2];
				bin(a,key,0,i-1);
				break;
			case 2:
				f=fopen("worst.txt","a");
				key=a[i-1];
				bin(a,key,0,i-1);
				break;
			case 3:
				f=fopen("avg.txt","a");
				temp=rand()%(i-1);
				key=a[temp];
				bin(a,key,0,i-1);
				break;	
		}	
		fprintf(f,"%d\t%d\n",i,count);
		count=0;
		fclose(f);		
	}
}

void main()
{
	system("rm -r *.txt");
	int ch;
	
	while(1)
	{
		printf("1.best\n2.worst\n3.avg\n");
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
