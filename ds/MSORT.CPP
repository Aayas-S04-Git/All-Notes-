#include<iostream.h>
#include<conio.h>
void quick(int [],int ,int );
int  split(int[],int,int);
void main()
{
	clrscr();
	int a[5],i;
	cout<<"Enter  5 numbers to sort :";
	for(i=0;i<=5-1;i++)
	{
		cin>>a[i];
	}
	quick(a,0,4);
	cout<<"Sorted array :";
	for(i=0;i<=5-1;i++)
	{
		cout<<"\t"<<a[i];
	}
	getch();
}
void quick(int a[],int  lw,int up)
{
	int i;
	if(up>lw)
	{
		i=split(a,lw,up);
		quick(a,lw,i-1);
		quick(a,i+1,up);
	}
}
int   split(int a[],int lw,int up)
{
	int upper,lower,pivot,k;
	pivot=a[lw];
	lower=lw;
	upper=up;
	while(upper>lower)
	{
		while(a[lower]<pivot)
		{
			lower++;
		}
		while(a[upper]>pivot)
		{
			upper--;
		}
		if(upper>lower)
		{
			k=a[lower];
			a[lower]=a[upper];
			a[upper]=k;
		}
	}
	k=a[lw];
	a[lw]=a[upper];
	a[upper]=k;
	return(upper);
}