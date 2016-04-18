#include<stdio.h>
int swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void quicksort(int a[],int p, int r){
	if(p<r){
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int partition(int a[],int p,int r){
	int i,j,pivot=a[r];
	i=p-1;
	for(j=p;j<r;j++){
		if(a[j]<=pivot){
			i++;
			swap(a+i,a+j);
		}
	}
	swap(a+i+1,a+r);
	return i+1;
}
		
int main()
{
	int n,a[10000],i,j,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quicksort(a,0,n-1);
	printf(" sorted array is : \n ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);

}
