#include<stdio.h>
int count=0;
// This code follows the exact functions and algorithms sir gave in the class,
// See the non-function version for another implementation
// For easeness, I took a 1-indexed array as given in the algorithm
//
//
void max_heapify(int a[],int i,int n); // Take a node i of heap with length n and make a max_heap assuming it's left and right subtree are maxheap
void build_max_heap(int a[],int n); // build max heap from an array of length n
void heap_sort(int a[],int n); // heap sort a given array
int main()
{
	int a[1010],n,i,j,temp,minpos;
	scanf("%d",&n); 
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	//heap_sort(a,n);
	heap_sort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	printf(" Count : %d ",count);
}

void heap_sort(int a[],int n)
{
	int i,temp;
	build_max_heap(a,n);
	for(i=n;i>1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		count+=3;
		max_heapify(a,1,i-1);
	}
}
void build_max_heap(int a[],int n)
{
	int i;
	count++;
	for(i=n/2;i>=1;i--)
		max_heapify(a,i,n);
}
void max_heapify(int a[],int i,int n)
{
	int largest=i,temp;
	count++;
	if(2*i<=n && a[2*i]>a[largest])
	{
		count++;
		largest=2*i;
	}
	if(2*i+1<=n && a[2*i+1]>a[largest])
	{
		count++;
		largest=2*i+1;
	}
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		count+=3;
		max_heapify(a,largest,n);
	}
}


