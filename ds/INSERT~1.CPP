#include<iostream.h>
#include<conio.h>
void insertionSort();
void main()
{
	clrscr();
	insertionSort();
	getch();
}
void insertionSort()
{
	int i,j,k,t,n,a[10];
	cout<<"\nEnter Value Of N:";
	cin>>n;
	cout<<"\nEnter The Array Eleemts:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			 if(a[i]<a[j])
			 {
				t=a[j];
				a[j]=a[i];
				for(k=i;k>j;k--)
				{
					a[k]=a[k-1];
				}
				a[k+1]=t;
			  }
		}
	}
	cout<<"\nSorted Array:";
	for(i=0;i<n;i++)
	{
		cout<<"\t"<<a[i];
	}
}