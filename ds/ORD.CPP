#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class ord
{
    int item[max],left,right;
public:
    void create(ord *);
    void insert_left(ord *,int );
    void insert_right(ord *,int );
    void display(ord *);
    int remove(ord *);
};
void ord::create(ord *p)
{
    p->left=p->right=-1;
    cout<<"Ord Created ";
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
void  ord::insert_left(ord *p,int x)
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
		 p->item[i]=p->item[i-2];
	   }
	   p->item[p->left+1]=x;
	   ++p->right;
     }
}
int ord::remove(ord *p)
{
    if(p->left==p->>right)
    {
	cout<<"Ord Overflows";
	return(0);
    }
    else
    {
	++p->left;
	return(p->item[p->left]);
    }
}
void  ord::display(ord *p)
{
    int i;
    for(i=left+1;i<=p->right;i++)
    {
	cout<<"\t"<<p->item[i];
    }
}
void main()
{
    clrscr();
    int n,z,ch;
    ord *p,q,Obj;
    p=&q;
    do
    {
	cout<<"1:create\n2:insert left \n3:insert right\n4:remove\n5:display\n6:Exit";
	cout<<"\nEnter your  choice =";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		obj.create(p);
		break;
	    case 2:
		cout<<"Enter any element =";
		cin>>n;
		obj.insert_left(p,n);
		break;
	    case 3:
		cout<<"Enter any element =";
		cin>>n;
		obj.insert_right(p,n);
		break;
	    case 3:
		z=obj.remove(p);
		cout<<"Removed element="<<z;
		break;
	    case 4:
		obj.display(p);
		break;
	    case 5:
		exit(0);
	    default:
		cout<<"Wrong Input";
	}
    }while(ch!=5);
    getch();
}