#include<iostream.h>
#include<conio.h>
void main()
{
	int n,a[10],i,j,k,min,pos;
	clrscr();
	cout<<"ENter how many no you want insert =";
	cin>>n;
	cout<<"Enter "<<n<<" element :";
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
	cout<<"\nSorted array =\n";
	for(i=0;i<=n-1;i++)
	{
		cout<<"\t"<<a[i];
	}
	getch();
}