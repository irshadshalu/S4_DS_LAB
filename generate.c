#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,j;
//	printf(" Enter number of elements to generate : ");
	scanf("%d",&n);
	printf("%d\n",n);
	for(i=0;i<n;i++)
		printf("%d ",i);
	printf("%ld", random()%n);

}
