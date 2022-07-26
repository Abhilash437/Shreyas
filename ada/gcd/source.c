#include<stdio.h>
#include<stdlib.h>


int euclid(int x,int y)
{
	int r,cnt=0;
	while(y>0)
	{
		cnt++;
		r=x%y;
		x=y;
		y=r;
	}
	return cnt;
}
float me(int x,int y)
{
	int temp;
	float cnt=0.0;
	
	while(y>0)
	{
		cnt+=0.5;
		if(y>x)
		{
			temp=x;
			x=y;
			y=temp;
		}
		x=x-y;
	}
	return cnt;
}

float coni(int x,int y)
{
	int min;
	float cnt=0.0;
	
	if(x>y)
		min=y;
	else
		min=x;
		
	while(min>0)
	{
		cnt+=1.0;
		if(x%min==0 && y%min==0)
			break;
		
		min--;
	}
	return cnt;
		
}
void main()
{
	int i,j,k;
	FILE *a,*b;
	
	system("rm -r *.txt");
	for(i=10;i<=100;i+=10)
	{
	
	
	
		int max1=0;
		float max2=0.0,min2=999.0;
		float min3=999.0,max3=0.0;
		int min1=999;
		
		for(j=2;j<i;j++)
		{
			for(k=0;k<i;k++)
			{
			 	int cnt1=euclid(j,k);
					if(cnt1>max1)
					 	max1=cnt1;
					else
					 	min1=cnt1;
					 
				int cnt2=me(j,k);
					if(cnt2>max2)
						max2=cnt2;
					else
						min2=cnt2;
				float cnt3=coni(j,k);
					if(cnt3>max3)
						max3=cnt3;
					else
						min3=cnt3;	
				
					
			}
		}
		a=fopen("euclidbest.txt","a");
		b=fopen("euclidworst.txt","a");
		
		fprintf(a,"%d\t%d\n",i,min1);
		fprintf(b,"%d\t%d\n",i,max1);
		
		fclose(a);
		fclose(b);
		
		a=fopen("me_best.txt","a");
		b=fopen("me_worst.txt","a");
		
		fprintf(a,"%d\t%.2f\n",i,min2);
		fprintf(b,"%d\t%.2f\n",i,max2);
		
		fclose(a);
		fclose(b);
		
		a=fopen("consint_best.txt","a");
		b=fopen("consint_worst.txt","a");
		
		fprintf(a,"%d\t%.2f\n",i,min3);
		fprintf(b,"%d\t%.2f\n",i,max3);
		
		fclose(a);
		fclose(b);
	}
}
