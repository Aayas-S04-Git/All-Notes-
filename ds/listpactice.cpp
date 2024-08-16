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
    void ins_bett(int,int);
    int rem_beg();
    int rem_end();
    int rem_bett(int );
    void  search(int);
    void count();
    void display();
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
    p=ist;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=NULL;
        list=p;
    }
    else
    {
        q=create();
        q->info=x;
        q->next=p;
        list=p;
    }
}
void node::ins_end(int x)
{
    node *p,*q;
    p=list;
    if(p==NULL)
    {
        p=create();
        p->info=x;
        p->next=NULL;
        list=p;
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
void ins_bett(int x,int after)
{
    node *p,*q;
    p=list;
    if(p==NULL||p->next==NULL)
    {
        cout<<"Linked list is empty";
    }
    else 
    {
        while(p->next!=NULL)
        {
            if(p->info==after)
            {
                q=create();
                q->info=x;
                q->next=p->next;
                p->next=q;
            }
            p=p->next;
        }
    }
}
int node::rem_beg()
{
    int z;
    node *p;
    p=list;
    if(p==NULL)
    {
        cout<<"Linked list is empty";
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
        returnn(z);
    }
}
int rem_end()
{
    node *p,*temp;
    p=list;
    int z;
    if(p==NULL)
    {
        cout<<"Linked list is empty";
    }
    else if(p->next==NULL)
    {
        z=p->info;
        delete(p);
        list=NULL;
        return(Z);
    }
    else
    {
        while(p->next->next!=NULL)
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
    p=list;
    int z;
    if(p==NULL)
    {
        cout<<"Linked list is empty";
    }
    else if(p->next==NULL||p->next->next==NULL)
    {
        cout<<"Remove between is not possible ";
    }
    else
    {
        while(p->next!=NULL)
        {
            if(p->info==srch)
            {
                temp=p->next;
                z=teemp->info;
                p->next=temp->next;
                delete(temp);
                return(z);
            }
            p=p->next;
        }
    }
}