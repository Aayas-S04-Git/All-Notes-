#include<conio.h>
#include<iostream.h>
void main()
{
	int  n,a[10],i,srch,t=0;
	clrscr();
	cout<<"Enter how many element you want to search =";
	cin>>n;
	cout<<"Enter "<<n<<" Element =";
	for(i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter search element =";
	cin>>srch;
	for(i=0;i<=n-1;i++)
	{
		if(srch==a[i])
		{
			t=1;
			break;
		}
	}
	if(t==1)
	{
		cout<<"search element is fount on index :"<<i;
	}
	else
	{
		cout<<"Element is not found ";
	}
getch();
}