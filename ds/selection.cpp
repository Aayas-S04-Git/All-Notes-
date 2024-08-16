#include<conio.h>
#include<iostream.h>
void main()
{
clrscr();
int i,j,k,n,min,pos,a[100];
cout<<"\nNo";
cin>>n;
for(i=0;i<=n-1;i++)
{
	cin>>a[i];
}
for(i=0;i<=n-1;i++)
{
	min=a[i];
	for(j=i;j<=n-1;j++)
	{
		if(min>a[j])
		{
			min=a[j];
			pos=j;
		}
	}
	if(a[i]!=min)
	{
		k=a[i];
		a[i]=a[pos];
		a[pos]=k;
	}
}
cout<<"Sorted array ==";
for(i=0;i<=n-1;i++)
{
	cout<<"\t"<<a[i];
}
getch();
}