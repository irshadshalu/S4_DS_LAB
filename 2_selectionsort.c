#include<stdio.h>
int count=0;
int main()
{
	int a[1010],n,i,j,temp,minpos;
	scanf("%d",&n); // input number of elements
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n-1;i++)
	{
		minpos=i;
		count+=2;
		for(j=i+1;j<n;j++)
		{
			count++;
			if(a[minpos]>a[j])
			{
				minpos=j;
				count++;
			}
		}
		temp=a[i];
		a[i]=a[minpos];
		a[minpos]=temp;
		count+=3;
	}

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf(" Count : %d ",count);
}


