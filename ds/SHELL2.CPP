#include<conio.h>
#include<iostream.h>
void main()
{
	int n,a[100],j,i,k,gap;
	clrscr();
	cout<<"Number of ele =";
	cin>>n;
	cout<<"array "<<5 <<" ele";
	for(i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}

	gap=gap/2;
	while(gap!=0)
	{
	for(j=gap;j<=n-1;j++)
	{
		for(i=j-gap;i>=0;i-gap)
		{
			if(a[gap+1]>a[i])
			{
				k=a[i];
				a[i]=a[gap+1];
				a[gap+1]=k;
			}
		}

	}
	gap=gap/2;
	}
	/*
	gap=gap/2;
	while(gap!=0)
	{
		for(j=gap;j<=n-1;j++)
		{

			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[gap+1]>=a[i])
				{
					k=a[i];
					a[i]=a[gap+1];
					a[gap+1]=k;
				}
			}
		}
		gap=gap/2;
	}*/
	cout<<"Sorted array =";
	for(i=0;i<=n-1;i++)
	{
		cout<<"\t"<<a[i];
	}
getch();
}