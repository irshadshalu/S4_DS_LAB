#include<stdio.h>
int swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void mergesort(int a[],int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int merge(int a[],int p,int q,int r){
	int L[100],R[100];
	int i,j,k,n1=q-p+1,n2=r-q;
	//printf("%d %d %d %d\n ", n1,n2,a[p],a[r-1]);
	for(i=0;i<n1;i++)
		L[i]=a[p+i];
	for(j=0;j<n2;j++)
		R[j]=a[q+j+1];
	i=0;
	j=0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
		
int main()
{
	int n,a[1000],i,j,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergesort(a,0,n-1);
	printf(" sorted array is : \n ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]); 
}
