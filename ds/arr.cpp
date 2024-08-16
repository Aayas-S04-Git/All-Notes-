#include<conio.h>
#include<iostream.h>
#include<process.h>
#define n 10
int tiem[n];
int cnt=0;
void insert(int);
int remove(int);
void display();
void reverse();
void insert(int x)
{
    static int i=0;
    item[i]=x;
    i++;
    cnt++;
}
void reverse()
{
    int i;
    for(i=cnt-1;i>=0;i--)
    {
        cout<<"\t"<<item[i];
    }
}
void display()
{
    int i;
    for(i=0;i<=cnt-1;i++)
    {
        cout<<"\t"<<item[i];
    }
}
int remove(int pos)
{
    int i,z;
    if(pos>0||pos<cnt)
    {
        cout<<"Enter correct position";
    }
    else
    {
        z=item[pos];
        for(i=pos;i<=cnt-1;i++)
        {
            item[i]=item[i+1];
        }
        cnt--;
        return(z);
    }
}
void main()
{
    clrscr();
    int n,ch,z;
    do
    {
        cout<<"1:insert\n2:reverse\n3:display\n4:remove\n5:exit\n";
        cout<<"Enter your choice =";
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"Enter any element to insert =";
                cin>>ch;
                insert(n);
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<"Enter position to remove =";
                cin>>pos;
                z=remove(pos);
                cout<<"Removed element ="<<z;
                break;
            case 5:
                exit(0);
        default:
            break;
        }
    } while (ch);
    
    getch();
}