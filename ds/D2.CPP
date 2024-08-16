#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class ord 
{
    int item[max],right,left;
public:
    void create(ord *);
    void insert_left(ord *,int);
    void insert_right(ord *,int);
    int remove(ord *);
    void display(ord *);
};
void ord::create(ord *p)
{
    p->right=p->left=-1;
    cout<<"Ord created ";
}
void ord::insert_left(ord *p,int x)
{
    if(p->right==max-1)
    {
	cout<<"Ord Overflow";
    }
    else
    {
	int i;
	for(i=p->right+1;i>=p->left+2;i--)
	{
	    p->item[i]=p->item[i-1];
	}
	p->item[p->left+1]=x;
	++p->right;
    }
}
void ord::insert_right(ord *p,int x)
{
    if(p->right==max-1)
    {
	cout<<"Ord Overflow";
    }
    else
    {
	++p->right;
	p->item[p->right]=x;
    }
}
int ord::remove(ord *p)
{
    if(p->left==p->right)
    {
	cout<<"Ord Underflow";
	return(0);
    }
    else
    {
	++p->left;
	return(p->item[p->left]);
    }
}
void ord::display(ord *p)
{
    int i;
    for(i=p->left+1;i<=p->right;i++)
    {
        cout<<"\t"<<p->item[i];
    }
}
void main()
{
    clrscr();
    int n,ch,z;
    ord *p,q,obj;
    p=&q;
    do
    {
        cout<<"\n1:create\n2:insert left \n3:insert right\n4:remove \n5:display\n6:Exit\n";
        cout<<"\nEnter your choice =";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.create(p);
            break;
        case 2:
            cout<<"ENter element to insert =";
            cin>>n;
            obj.insert_left(p,n);
            break;
        case 3:
	    cout<<"ENter element to insert =";
	    obj.insert_right(p,n);
            cin>>n;
            break;       
        case 4:
            z=obj.remove(p);
            cout<<"Removed element ="<<z;
            break;
        case 5:
            obj.display(p);
            break;
        case 6:
                exit(0);
        default:
            cout<<"Wrong Input";
            break;
        }
    } while (ch!=6);
    
    getch();
}