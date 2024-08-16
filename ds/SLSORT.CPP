#include<conio.h>
#include<iostream.h>
void main()
{
    int a[10],j,n,i,min,k,pos;
    clrscr();
    cout<<"Enter how many element you want to search :";
    cin>>n;
    cout<<"Enter "<<n<<" Numbers =";
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
    cout<<"\nsorted array\n";
    for(i=0;i<=n-1;i++)
    {
	cout<<"\t"<<a[i];
    }
    getch();
}