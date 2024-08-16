#include<iostream.h>
#include<conio.h>
void quick(int [],int,int);
int split(int[],int,int);
void main()
{
	int i,j,a[10],n;
	clrscr();
	cout<<"\Enter The no of element ypu wanna to sort:";
	cin>>n;
	cout<<"\Enter The Elements You Want To Sort:";
	for(i=0;i<n;i++)
	{
 		cin>>a[i];
	}
	quick(a,0,n-1);
cout<<"\nSorted Array:";
	for(i=0;i<n;i++)
	{
 		cout<<"\t"<<a[i];
	}
	getch();
}
void quick(int z[],int lw,int up)
{
	int i;
	if(up>lw)
	{
		i=split(z,lw,up);
		quick(z,lw,i-1);
		quick(z,i+1,up);
	}
}
int split(int z[],int lw,int up)
{
 	int upper,lower,pivot,t;
	upper=up;
	lower=lw;
	pivot=z[lw];
	while(upper>lower)
	{
		while(z[lower]<=pivot)
		{
			lower++;
		}
		while(z[upper]>pivot)
		{
			upper--;
		}
		if(upper>lower)
		{
			t=z[upper];
			z[upper]=z[lower];
			z[lower]=t;
		}
	}
	t=z[upper];
	z[upper]=z[lw];
	z[lw]=t;
return upper;
}