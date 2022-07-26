#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;

int partition(int arr[],int l,int r)
{
	int pi=arr[l];
	int i=l+1,j=r;
	
	while(i<=j)
	{
		count++;
		while(i<=r && arr[i]<pi)
		{
			count++;
			i++;
		}	
		count++;
		while(arr[j]>pi)
		{
			count++;
			j--;
		}
		
		if(i<=j)
		{
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			i++;
			j--;
		}
	}
	
	int temp=arr[l];
	arr[l]=arr[j];
	arr[j]=temp;
	
	return j;
}

void quicksort(int arr[],int l,int h)
{
	int s;
	if(l<h)
	{
		s=partition(arr,l,h);
		quicksort(arr,l,s-1);
		quicksort(arr,s+1,h);
	}
}
void analysis(int ch)
{
	int i,j,k;
	FILE *fp;
	int *a,*b,*w;
	srand(time(NULL));
	
	for(i=10;i<=100;i+=10)
	{
		a=(int *)malloc(sizeof(int)*i);
		b=(int *)malloc(sizeof(int)*i);
		w=(int *)malloc(sizeof(int)*i);
			
		for(j=0;j<i;j++)
		{
			b[j]=10;
			w[j]=j+1;
			a[j]=rand()%100;	
		}
		count=0;
		switch(ch)
		{
			case 1:
				fp=fopen("best.txt","a");
				quicksort(b,0,i-1);
				fprintf(fp,"%d\t%d\n",i,count);
				fclose(fp);	
				break;
			case 2:
				fp=fopen("worst.txt","a");
				quicksort(w,0,i-1);
				fprintf(fp,"%d\t%d\n",i,count);
				fclose(fp);
				break;
			case 3:
				fp=fopen("avg.txt","a");
				quicksort(a,0,i-1);
				fprintf(fp,"%d\t%d\n",i,count);
				fclose(fp);		
				break;
		}
		//fclose(fp);
		
		
	}
}
void main()
{
	int choice;
	system("rm -r *.txt");
	while(1)
	{
		printf("Press 1 for best case\n");
		printf("Press 2 for worst case\n");
		printf("Press 3 for avg case\n");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			case 2:	
			case 3:
				analysis(choice);
				break;
			default:
				exit(1);
		}
	}
}		



/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define X 10

int count;

int partition(int *a,int s,int e){
	int i = s+1,j = e, p = a[s];
	while(i<=j){
		count++;
		while(i<=e && a[i] < p){
			count++;
			i++;
		}
		count++;
		while(a[j]>p){
			count++;
			j--;
		}
		//count++;
		if(i<=j){
			//count++;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
			j--;
		}
		if(i==j && a[i] == p){
			count++;
			return j;
		}
	} 
	if(a[j]!=a[e]){
	int temp = a[s];
	a[s] = a[j];
	a[j]= a[s];
	}

	return j;
}

void quick(int *a,int s,int e){
	if(s<e){
		int l = partition(a,s,e);
		quick(a,s,l-1);
		quick(a,l+1,e);
	}
}
void analysis(int ch){
	FILE *f;
	srand(time(NULL));
	int *a,*b,*w;
	for(int i = 10;i<=100;i+=10){
		a = (int *)malloc(sizeof(int)*i);
		b = (int *)malloc(sizeof(int)*i);
		w = (int *)malloc(sizeof(int)*i);

		for(int j = 0;j<i;j++){
			b[j] = X;
			w[j] = j;
			a[j] = rand()%100;
		}
		count = 0;
		switch(ch){
			case 1:
				quick(b,0,i-1);
				f = fopen("best.txt","a");
				break;
			case 2:
				quick(w,0,i-1);
				f = fopen("worst.txt","a");
				break;
			case 3:
				quick(a,0,i-1);
				f = fopen("avg.txt","a");
				break;
		}
		fprintf(f, "%d %d\n",i,count );
		fclose(f);

	}
}

int main(){
	int ch;
	system("rm -r *.txt");
	while(1){
		printf("1.Best case\n2.Worst case\n3.Avg case\n");
			scanf("%d",&ch);

		switch(ch){
			case 1:
			case 2:
			case 3:
			
				analysis(ch);break;
			
			
			
			
			default: exit(1);
		}
	}
}*/		
		
		
		
		
		
		
		
	
