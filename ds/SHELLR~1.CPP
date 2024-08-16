#include<iostream.h>
#include<conio.h>
void shell();
void main()
{
	clrscr();
	shell();
	getch();
}
void shell()
{
	int gap,i,a[5],j,t;
	cout<<"\nEnter The Elements Of Array:";
	for(i=0;i<5;i++)
	{
		cin>>a[i];
	}
	gap=5/2;
	while(gap!=0)
	{
		for(j=gap;j<5;j++)
		{
			for(i=j-gap;i>=0;i=i-gap)
			{
				if(a[gap+i]<a[i])
				{
					t=a[gap+i];
					a[gap+i]=a[i];
					a[i]=t;
				}
			}
		}
		gap=gap/2;
	}
for(i=0;i<5;i++)
{
	cout<<"\t"<<a[i];
}
}