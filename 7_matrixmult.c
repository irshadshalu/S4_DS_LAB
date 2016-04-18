#include<stdio.h>
int count=0;
int main()
{
	int a[31][31],b[31][31],c[31][31],n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&b[i][j]);		
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			c[i][j]=0;
			count++;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
				count++;
			}
		}
	
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
	printf("Count : %d \n",count);
}
