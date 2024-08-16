#include<iostream.h>
#include<conio.h>
void main()
{
    clrscr();
    int a[10],i,j,k,n,mid,srch,down,up,t;
    cout<<"Enter no of element to insert:";
    cin>>n;
    cout<<"Enter "<<n<<" no inarray :";
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
    cout<<"\nSorted array =";
    for(i=0;i<=n-1;i++)
    {
        cout<<"\t"<<a[i];
    }
    down=0;
    up=n-1;
    cout<<"Enter search element =";
    cin>>srch;
    while(down<=up)
    {
        mid=(up+down)/2;
        if(a[mid]==srch)
        {
            t=1;
            break;
        }
        else if(srch>a[mid])
        {
	    down=mid+1;
	}
	else if(srch<a[mid])
	{
	    up=mid-1;
        }
    }
    if(t==1)
    {
        cout<<"Found ";
    }
    else
    {
        cout<<"Not found ";
    }
    getch();
}