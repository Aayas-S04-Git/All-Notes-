#include<iostream.h>
#include<conio.h>
int split(int [],int ,int);
void quick(int[],int,int);
void main()
{
	clrscr();
	int n[5],i;
	cout<<"Enter 5 number =";
	for(i=0;i<=4;i++)
	{
		cin>>n[i];
	}
	quick(n,0,4);
	cout<<"Sorted array =";
	for(i=0;i<=4;i++)
        {
            cout<<"\t"<<n[i];
        }
        getch();
}
void quick(int  a[],int lw,int up)
{
    int i;
    if(up>lw)   
    {
        i=split(a,lw,up);
        quick(a,lw,i-1);
        quick(a,i+1,up);
    }
}
int split(int a[],int lw,int up)
{
    int t,pivot,lower,upper;
    pivot=a[lw];
    lower=lw;
    upper=up;
    while (upper>lower)
    {
        while (a[lower]<=pivot)
        {
            lower++;
        }
        while (a[upper]>pivot)
        {
            upper--;
        }
        if(upper>lower)
        {
            t=a[lower];
            a[lower]=a[upper];
            a[upper]=t;
	}
    }
    t=a[lw];
    a[lw]=a[upper];
    a[upper]=t;
    return(upper);
}