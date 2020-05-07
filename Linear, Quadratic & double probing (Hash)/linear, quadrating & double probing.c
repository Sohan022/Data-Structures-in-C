#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n_col,n_empty;
int e_slot(int h[],int m)
{
    n_empty=0;
    int i;
    for(i=0;i<m;i++)
    {
    	if(h[i]==-1)
    	n_empty++;
	}
	return n_empty;
}
void linear(int h[],int m,int a[],int n)
{
    n_col=0;
    int i,b;
    for(i=0;i<n;i++)
    {
        b=a[i]%m;
        if(h[b]==-1)
        h[b]=a[i];
        else
        {
            while(1)
            {
                n_col++;
                b=(b+1)%m;
                if(h[b]==-1)
                {
                    h[b]=a[i];
                    break;
                }
            }
        }
    }
}
void quadratic(int h[],int m,int a[],int n)
{
	n_col=0;
	int i,b,j=1;
	for(i=0;i<n;i++)
	{
		b=a[i]%m;
		if(h[b]==-1)
		h[b]=a[i];
		else
		{
			while(1)
			{
				n_col++;
				b=(b+j*j)%m;
				if(h[b]==-1)
				{
					h[b]=a[i];
					break;
				}
				j++;
			}
			j=1;
		}
	}
}
void double_h(int h[],int m,int a[],int n)
{
    n_col=0;
    int i,b,j=0;
    for(i=0;i<n;i++)
    {
        b=a[i]%m;
        if(h[b]==-1)
        h[b]=a[i];
        else
        {
            while(1)
            {
                n_col++;
                j=j+(8-(a[i]%8));
                if(h[j]==-1)
                {
                    h[j]=a[i];
                    break;
                }
            }
            j=0;
        }
    }
}
int main()
{
    int a[1000],t,j,i,n,m;
    printf("enter the no. of elements = ");
    scanf("%d",&n);
    srand(time(0));
    printf("enter elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
 /*   for(i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    for(i=n-1;i>0;i--)
    {
        j=rand()%(i+1);
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    for(i=0;i<n;i++)
    printf("%d,  ",a[i]);*/
    printf("\nenter the no. of slot = ");
    scanf("%d",&m);
    int b,d,h[m];
    for(i=0;i<m;i++)
    h[i]=-1;
    printf("choose one of the following operation\n");
    printf("1.linear probing\n2.quadratic probing\n3.double hashing\n");
    scanf("%d",&b);
    switch(b)
    {
         case 1:
             if(m>=n)
             {
                printf("yes, all the integer inserted into the hash table\n");
             }
             else
             {
                printf("you should give m greater than n\n");
                break;
			 }
             linear(h,m,a,n);
             printf("no of collision %d\n",n_col);
             printf("no of empty slot %d\n",e_slot(h,m));
             break;
             case 2:
             	 if(m>=n)
                 {
                    printf("yes, all the integer inserted into the hash table\n");
                 }
                else
                {
                	printf("you should give m greater than n\n");
                	break;
				}
                quadratic(h,m,a,n);
                printf("no of collision %d\n",n_col);
                printf("no of empty slot %d\n",e_slot(h,m));
                break;
             case 3:
             	if(m>=n)
                {
                   printf("yes, all the integer inserted into the hash table\n");
                }
                else
                {
                	printf("you should give m greater than n\n");
                	break;
				}
				double_h(h,m,a,n);
                printf("no of collision %d\n",n_col);
                printf("no of empty slot %d\n",e_slot(h,m));
                break;
    }
    return 0;
}
