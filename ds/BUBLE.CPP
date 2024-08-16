#include<conio.h>
#include<iostream.h>
void main()
{
    int n,a[100],i,j,k;
    clrscr();
    cout<<"Entre how many number you want to sort=";
    cin>>n;
    cout<<"Enter "<<n<<" number =";
    for(i=0;i<=n-1;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<=n-1;i++)
    {
	for(j=0;j<=n-2;j++)
	{
	    if(a[j]>a[j+1])
	    {
		k=a[j];
		a[j]=a[j+1];
		a[j+1]=k;
	    }
	}
    }
    cout<<"Sorted array =\n";
    for(i=0;i<=n-1;i++)
    {
        cout<<"\t"<<a[i];
    }
    getch();
}
