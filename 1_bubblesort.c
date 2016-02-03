#include<stdio.h>
int count=0;
int main()
{
	int a[1010],n,i,j,temp;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
	{
		count++;
		for(j=0;j<n-i-1;j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				count+=3;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf(" Count : %d ",count);
}


