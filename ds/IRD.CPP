#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class ird
{
    int item[max],left,right;
public:
    void create(ird *);
    void insert(ird *,int );
    int remove_left(ird *);
    int remove_right(ird *);
    void display(ird *);
};
void ird::create(ird *p)
{
    p->left=p->right=-1;
    cout<<"Ird Created";
}
void ird::insert(ird *p,int x)
{
    if(p->right==max-1)
    {
	cout<<"Ird Overflow";
    }
    else
    {
	p->right++;
	p->item[p->right]=x;
    }
}
int ird::remove_left(ird *p)
{
	if(p->left==p->right)
	{
		cout<<"Ird Underflows";
		return(0);
	}
	else
	{
	    ++p->left;
	    return(p->item[p->left]);
	}
}
int ird::remove_right(ird *p)
{
    if(p->left==p->right)
    {
	cout<<"Ird Underflows";
	return(0);
    }
    else
    {
	return(p->item[p->right--]);
    }
}
void ird::display(ird *p)
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
    int n,z,ch;
    ird *p,q,obj;
    p=&q;
    do
    {
        cout<<"1:create\n2:insert\n3Lremove left\n4:remove right\n5:display\n6:Exit\n";
        cout<<"Enter your choice=";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.create(p);
            break;
        case 2:
            cout<<"Enter any element to insert=";
            cin>>n;
            obj.insert(p,n);
            break;
        case 3:
            z=obj.remove_left(p);
            cout<<"Removed element ="<<z;
        case 4:
	    z=obj.remove_right(p);
            cout<<"Removed element ="<<z;
            break;
        case 5:
            obj.display(p);
            break;  
        default:
                cout<<"Wrong input";
        }
    }while(ch!=6);
        
}