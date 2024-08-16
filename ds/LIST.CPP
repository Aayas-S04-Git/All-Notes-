#include<iostream.h>
#include<conio.h>
#include<process.h>
class node
{
    int info;
    node *next;
public:
    node* create();
    void ins_beg(int );
    void ins_end(int);
    void ins_bett(int ,int);
    int rem_beg();
    int rem_end();
    int rem_bett(int );
    void display();
    void search(int );
    void count();
    void reverse();
}*list;
node* node::create()
{
    node *z;
    z=new node;
    return(z);
}
void node::ins_beg(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p->create();
        p->info=x;
        p->next=NULL;
        p=list;
    }
    else
    {
        q=create();
        q->info=x;
        q->next=p;
        list=q;
    }
}
void node::ins_end(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p->create();
        p->info=x;
        p->next=NULL;
        p=list;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        q=create();
        q->info=x;
	q->next=NULL;
        p->next=q;
    }
}
void node::ins_bett(int srch,int x)
{
     node *p,*q;
     p=list;
     if(p==NULL||p->next==NULL)
     {
	    cout<<"Insert between is not possible ";
     }
     else
     {
        while(p->next!=NULL)
        {
            if(p->info==srch)
            {
                q=create();
                q->info=x;
		p->next=q;
                q->next=p->next;
            }
            p=p->next;
        }
     }
}
int node::rem_beg()
{
    node *p;
    int  z;
    p=list;
    if(p==NULL)
    {
	cout<<"Linked list is empty";
	return(0);
    }
    else if(p->next==NULL)
    {
        z=p->info;
	delete(p);
        list=NULL;
        return(z);
    }
    else
    {
        z=p->info;
        list=p->next;
        delete(p);
        return(z);
    }
}
int node::rem_end()
{
    int z;
    node *p,*temp;
    p=list;
    if(p==NULL)
    {
        cout<<"Linked list is empty";
	return(0);
    }
    else if(p->next==NULL)
    {
        z=p->info;
        delete(p);
        list=NULL;
        return(z);
    }
    else
    {
            while(p->next->next==NULL)
            {
                p=p->next;
            }
            temp=p->next;
            z=temp->info;
	    p->next=NULL;
            delete(temp);
            return(z);
    }

}
int node::rem_bett(int after)
{
    node *p,*temp;
    int z;
    p=list;
    if(p==NULL)
    {
	cout<<"Linked ist is empty";
	return(0);
    }
    else if(p->next==NULL||p->next->next==NULL)
    {
	cout<<"Remove between is not possible";
	return(0);
    }
    else
    {
	while(p->next!=NULL)
        {
            if(after==p->info)
            {
                temp=p->next;
                z=temp->info;
                p->next=temp->next;
                delete(temp);
                return(z);
            }
            p=p->next;
	}
	return(z);
    }
}
void node::display()
{
    node *p;
    p=list;
    while(p!=NULL)
    {
	cout<<"\t"<<p->info;
        p=p->next;
    }
}
void node::search(int srch)
{
    node *p;
    p=list;
    int t=0;
    while(p!=NULL)
    {
        if(srch==p->info)
        {
            t=1;
            break;
        }
        p=p->next;
    }
    if(t==1)
    {
	cout<<"NOde is found ";
    }
    else
    {
        cout<<"Node is not found ";
    }
}
void node::count()
{
    node *p;
    int cnt=0;
    p=list;
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    cout<<"Total node present in singly linear linked list="<<cnt;
}
void node::reverse()
{
    node*p1,*p2,*p3;
    p1=list;
    while(p1!=NULL)
    {
        p2=p1->next;
        p1->next=p3;
        p3=p1;
        p1=p2;
    }
    list=p3;
    cout<<"linked list is reversed ";
}
void main()
{
    clrscr();
    int ch,n,z,srch,after;
    node obj;
    do
    {
	cout<<"\n1:insert begin \n2:insert end \n3:insert between\n4:remove begin\n5:remove end \n6:remove between\n7:display\n8:search\n9:count\n10:Reverse\n11:Exit\n";
        cout<<"Enter your choice =";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter no to insert=";
                cin>>n;
                obj.ins_beg(n);
                break;
            case 2:
                cout<<"Enter no to insert=";
                cin>>n;
                obj.ins_end(n);
                break;
            case 3:
                cout<<"Enter no to insert=";
                cin>>n;
		cout<<"\nAfter witch node=";
                cin>>after;
		obj.ins_bett(n,after);
                break;
            case 4:
                z=obj.rem_beg();
                cout<<"Remved NOde ="<<z;
                break;
            case 5:
                z=obj.rem_end();
                cout<<"\nRemoved Node="<<z;
                break;
            case 6:
                cout<<"After which node =";
                cin>>after;
                z=obj.rem_bett(after);
                cout<<"Removed Node ="<<z;
                break;
            case 7:
                obj.display();
                break;
            case 8:
                cout<<"Enter search node =";
                cin>>srch;
                obj.search(srch);
                break;
            case 9:
                obj.count();
                break;
            case 10:
		obj.reverse();
                break;
            case 11:
                exit(8);
            default:
                cout<<"Wrong input";

        }
    }while(ch!=11);
    getch();
}