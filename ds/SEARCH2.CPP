#include<iostream.h>
#include<conio.h>
void main()
{
    clrscr();
    int a[10],i,j,t=0,k,n,srch;
    cout<<"Enter how many element you want to sort:";
    cin>>n;
    cout<<"Enter "<<n<<" element in array=";
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
        cout<<"Found ";
    }
    else{
        cout<<"NOt found ";
    }
    getch();
}