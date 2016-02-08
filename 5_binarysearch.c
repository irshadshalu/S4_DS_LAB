#include<stdio.h>
int count=0;
int main()
{
	int a[1010],n,i,key,pos,beg,mid,end;
	scanf("%d",&n); 
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&key);
	beg=0;
	end=n;
	pos=-1;
	count+=2;
	while(beg<=n)
	{
		mid=(beg+end)/2;
		count++;
		if(key==a[mid])
		{
			count++;
			pos=mid;
			break;
		}
		else if(key<a[mid])
		{
			end=mid-1;
			count++;
		}
		else
		{
			beg=mid+1;
			count++;
		}
	}
	if(pos!=-1)
		printf(" Found at pos %d ",pos);
	else 
		printf("Not found ");
	printf("\n Count : %d \n",count);
}


