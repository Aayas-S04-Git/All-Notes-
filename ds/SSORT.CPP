#include<iostream.h>
#include<conio.h>
void main()
{
    clrscr();
    int a[10],i,j,k,n;
    cout<<"Enter how many no you want to insert ";
    cin>>n;
    cout<<"ENter "<<n<<" element =";
    for ( i = 0; i <=n-1; i++)
    {
        cin>>a[i];
    }
    for(i=0;i<=n-1;i++)
    {
	for(j=0;j<=n-1;j++)
        {
	    if(a[i]<a[j])
            {
                k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    cout<<"\nsorted array";
    for(i=0;i<=n-1;i++)
    {
        cout<<"\t"<<a[i];
    }  
    getch();
}