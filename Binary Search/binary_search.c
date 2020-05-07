#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int comp;
void swap(int *x, int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
	return;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    while(1)
    {
        while(pivot<a[high])
        {
            high--;
        }
        while(pivot>a[low])
        {
            low++;
        }
        if(low<=high)
        {
            swap(&a[low],&a[high]);
            high--;
            low++;
        }
        else
        break;
    }
    return high;
}
void quick_s(int a[],int low,int high)
{
	if(low<high){
	    int index=partition(a,low,high);
	    quick_s(a,low,index);
	    quick_s(a,index+1,high);
	}

	return;
}
int binary_search(int a[],int low,int high,int k)
{
	if(low<=high){
	int mid=(low+high)/2;
	comp++;
	if(k==a[mid])
	return mid;
	else
	{
		if(k>a[mid])
		binary_search(a,mid+1,high,k);
		else
		binary_search(a,low,mid-1,k);
	}
}
else
return -1;
}
int main()
{
	int n,i,k,z;
	comp=0;
	printf("enter the size of array = ");
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	srand(time(0));
	for(i=0;i<n;i++)
	{
		a[i]=rand();
	}
	quick_s(a,0,n-1);
    for(i=0;i<n;i++)
    printf("%d,  ",a[i]);
    printf("\nenter the element which you want to search = ");
    scanf("%d",&k);
	clock_t start,end;
	double time_used;
	start=clock();
	z=binary_search(a,0,n-1,k);
	end=clock();
	if(z==-1)
		printf("element is not found");
	else
		printf("element is found at index %d",z);
	time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("running time = %lf\nno. of comparision = %d",time_used,comp);
	return 0;
}
