#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
int a[max];
int cnt =0;
void insert(int );
void display();
void reverse();
int remove(int );
void main()
{
    clrscr();
    int n,ch,z;
    do
    {
        cout<<"\n1:insert\n2:remove\n3:display\n4:reverse\n5:Exit\n";
        cout<<"Enter your choice =";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter any no =";
                cin>>n;
                insert(n);
                break;
            case 2:
                cout<<"Enter position to remove element =";
                cin>>n;
                z=remove(n);
                cout<<"\nremoved element ="<<z;
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                break;
            case 5:
                exit(0);
        }
    } while (ch!=5);
    getch();
}
void insert(int x)
{
    static int i=0;
    a[i]=x;
    i++;
    cnt++;
}
void display()
{
    int i;
    for(i=0;i<=cnt-1;i++)
    {
        cout<<"\t"<<a[i];
    }
}
void reverse()
{
    int i;
    for ( i = cnt-1; i>0; i--)
    {
	cout<<"\t"<<a[i];
    }

}
int remove(int pos)
{
    int i,z;
    if(pos<0||pos>max-1)
    {
	cout<<"Invalid index";
	return(0);
    }
    else
    {
	z=a[pos];
	for(i=pos;i<=cnt;i++)
	{
	    a[i]=a[i+1];
	}
	cnt--;
	return(z);
    }
}
