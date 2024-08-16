#include<iostream.h>
#include<conio.h>
int split(int[],int,int);
void quick(int[],int,int);
void main()
{
    clrscr();
    int a[5],i;
    cout<<"Enter 5 number =";
    for ( i = 0; i <=4; i++)
    {
        cin>>a[i];
    }
    quick(a,0,4);
    cout<<"Sorted data=\n";
    for ( i=0;i<=4;i++)
    {
       cout<<"\t"<<a[i];
    }
    getch();
}
void quick(int a[],int lw,int up)
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
    int lower,upper,pivot,t;
    pivot=a[lw];
    lower=lw;
    upper=up;
    while(upper>lower)
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