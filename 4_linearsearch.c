#include<stdio.h>
int count=0;
int main()
{
	int a[1010],n,i,key,pos;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&key);
	pos=-1;
	for(i=0;i<n;i++)
	{
		count++;
		if(a[i]==key)
		{
			count++;
			pos=i;
			break;
		}
	}
	if(pos!=-1)
		printf(" Found at pos %d ",pos);
	else
		printf(" Not found");
	printf("\n Count : %d \n",count);
}


