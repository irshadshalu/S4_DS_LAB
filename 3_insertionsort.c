#include<stdio.h>
int count=0;
int main()
{
	int a[1010],n,i,j,temp,minpos;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
		scanf("%d",a+i);

	for(i=1;i<n;i++)
	{
		j=i;
		count++;
		while( j>0 && a[j-1]>a[j])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			count+=4;
			j--;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf(" Count : %d ",count);
}


