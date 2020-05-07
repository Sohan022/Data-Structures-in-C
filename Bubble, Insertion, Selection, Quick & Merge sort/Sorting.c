#include<stdio.h>
#include<stdlib.h>
#include<time.h>
                   //GeeksforGeeks

int n_swap=0;
long long int n_comp=0;
void swap(int *x, int *y)
{
	int t;
	t=*x;
	*x=*y;
	*y=t;
	return;
}
void bubble_s(int n,int a[])
{
	n_swap=0,n_comp=0;
	int i,j,flag=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			n_comp++;
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				flag=1;
				n_swap++;
			}
		}
		if(flag==0)
		break;
	}
    return;
}
void selection_s(int n,int a[])
{
	n_swap=0,n_comp=0;
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			n_comp++;
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		swap(&a[i],&a[min]);
		n_swap++;
	}
	return;
}
void insertion_s(int n,int a[])
{
	n_swap=0,n_comp=0;
	int i,j,t;
	for(i=0;i<n;i++)
	{
	    t=a[i];
	    for(j=i;j>0;j--)
		{
			n_comp++;
		    if(t<a[j-1])
			{
			    n_swap++;
				a[j]=a[j-1];
			}
		  	else
            {
                break;
            }
	    }
	    a[j]=t;
	}
	return;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    while(1)
    {
        n_comp++;
        while(pivot<a[high])
        {
            high--;
            n_comp++;
        }
        n_comp++;
        while(pivot>a[low])
        {
            low++;
            n_comp++;
        }
        if(low<=high)
        {
            swap(&a[low],&a[high]);
            n_swap++;
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
void merge(int a[],int low,int mid,int high)
{
    int n1,n2;
    n1=mid-low+1;
    n2=high-mid;
    int a1[n1],a2[n2],i=0,j=0,k;
    while(i<n1)
    {
    	a1[i]=a[low+i];
    	i++;
	}
	while(j<n2)
	{
		a2[j]=a[mid+1+j];
	    j++;
	}
    i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
    	if(a1[i]<=a2[j])
    	{
    		a[k]=a1[i];
    		i++;
		}
		else
		{
			a[k]=a2[j];
			j++;
		}
		k++;
		n_comp++;
	}
	
	while(i<n1)
	{
		a[k]=a1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=a2[j];
		k++;
		j++;
	}
}
void merge_s(int a[],int low,int high)
{
	if(low<high){
	int mid=low+(high-low)/2;
	merge_s(a,low,mid);
	merge_s(a,mid+1,high);
	merge(a,low,mid,high);
   
	}
}
int main()
{
	int m,i;
    int n;
	printf("1.bubble sort\n2.selection sort\n3.insertion sort\n4.quick sort\n5.merge sort\n6.exit\n");
	clock_t start,end;
	double timetaken;
	while(1)
	{
		printf("press the key for above operation = ");
		scanf("%d",&m);

		if(m==6)
 		break;
		printf("enter the size of array = ");
		scanf("%d",&n);
		int *a=(int *)malloc(n*sizeof(int));

		srand(time(0));
		for(i=0;i<n;i++)
		a[i]=rand();
		switch(m)
		{
			case 1:
				start=clock();
				bubble_s(n,a);
				end=clock();
				timetaken=((double)(end-start))/CLOCKS_PER_SEC;
				for(i=0;i<n;i++)
				printf("%d,  ",a[i]);
				printf("\ntime taken %f\n",timetaken);
				printf("no. of comparision = %lld\n",n_comp);
				printf("no. of swap= %d",n_swap);
   				break;
   			case 2:
   			    start=clock();
   				selection_s(n,a);
   				end=clock();
   				timetaken=((double)(end-start))/CLOCKS_PER_SEC;
   				for(i=0;i<n;i++)
				printf("%d,  ",a[i]);
				printf("\ntime taken %f\n",timetaken);
				printf("no. of comparision = %lld\n",n_comp);
				printf("no. of swap= %d",n_swap);
   				break;
   			case 3:
   				start=clock();
   				insertion_s(n,a);
   				end=clock();
   				timetaken=((double)(end-start))/CLOCKS_PER_SEC;
   				for(i=0;i<n;i++)
				printf("%d,  ",a[i]);
				printf("\ntime taken %f\n",timetaken);
				printf("no. of comparision = %lld\n",n_comp);
				printf("no. of swap= %d",n_swap);
   				break;
   		    case 4:
   			    n_comp=0,n_swap=0;
   				start=clock();
   				quick_s(a,0,n-1);
   				end=clock();
   				timetaken=((double)(end-start))/CLOCKS_PER_SEC;
   				for(i=0;i<n;i++)
				printf("%d,  ",a[i]);
				printf("\ntime taken %f\n",timetaken);
				printf("no. of comparision = %lld\n",n_comp);
				printf("no. of swap= %d",n_swap);
   				break;
   			case 5:
   			    n_comp=0,n_swap=0;
   				start=clock();
   				merge_s(a,0,n-1);
   				end=clock();
   				timetaken=((double)(end-start))/CLOCKS_PER_SEC;
   				for(i=0;i<n;i++)
				printf("%d,  ",a[i]);
				printf("\ntime taken %f\n",timetaken);
				printf("no. of comparision = %lld\n",n_comp);
				printf("no. of swap= %d",n_swap);
   				break;
		}
		printf("\n\n");
	}
	return 0;
}
