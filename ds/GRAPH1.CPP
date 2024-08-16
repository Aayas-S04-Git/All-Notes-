#include<conio.h>
#include<iostream.h>
#include<process.h>
class edge
{
    public:
    int des;
    edge *right;
};
class node
{
    public:
    int info;
    node *next;
    edge *adj;
    node* create();
    void insert_v(int x);
    void display_v();
    void insert_e(int,int);
    void display();
    void adjacent_v(int);
}*start;
node* node::create()
{
    node *p;
    p=new node();
    return(p);
}
void node::insert_v(int x)
{
    node *p,*q;
    p=start;
    if(p==NULL)
    {
	p=create();
	p->info=x;
	p->next=NULL;
	p->adj=NULL;
    }
    else
    {
	q=create();
	q->info=x;
	q->next=NULL;
	q->adj=NULL;
	while(p->next!=NULL)
	{
	    p=p->next;
	}
	p->next=q;
    }
}
void node::display_v()
{
    node *p;
    p=start;
    while(p!=NULL)
    {
	cout<<"\t"<<p->info;
	p=p->next;
    }

}
void node::insert_e(int sc ,int de)
{
    int a=0,b=0;
    node *p,*q;
    p=q=start;
    while(p!=NULL)
    {
	if(sc==p->info)
	{
	    a=1;
	    break;
	}
	p=p->next;
    }
    while (q!=NULL)
    {
	if(de==q->info)
	{
	    b=1;
	    break;
	}
	q=q->next;
    }
    if(a==1&&b==1)
    {
	edge *m,*n;
	m->des=de;
	m->right=NULL;
	if(p->adj==NULL)
	{
	    p->adj=m;
	}
	else
	{
	    n=p->adj;
	    while(n->right!=NULL)
	    {
		n=n->right;
	    }
	    n->right=m;
	}

    }
}
    void node::display()
    {
	node *p;
	edge *q;
	p=start;
	while(p!=NULL)
	{
	    cout<<"\n"<<p->info;
	    if(p->adj!=NULL)
	    {
		q=p->adj;
		while(q!=NULL)
		{
		    cout<<"--> "<<q->des;
		    q=q->right;
		}
	    }
	    p=p->next;
	}
    }
    void node::adjacent_v(int x)
    {
	node *p;
	edge *q;
	p=start;
	while (p!=NULL)
	{
	   if(p->info==x)
	   {
	    if(p->adj!=NULL)
	    {
		q=p->adj;
		while(q!=NULL)
		{
		    cout<<"\t"<<q->des;
		    q=q->right;
		}
	    }
	    else
	    {
		cout<<"\nNOT ADJCENT EDGE";
		break;
	    }
	   }
	   p=p->next;
	}

    }
void main()
{
    int n,m,ch;
    node k;
    clrscr();
    do
    {
	cout<<"\nOperations On GRAPH\n1:insert_V\n2:insert_E\n3:display_V\n4:ADjacent_V\n5;display\n6;exit\n CHOICE=";
	cin>>ch;
	switch(ch)
	{
	    case 1:
		cout<<"\nEnter Vertex=";
		cin>>n;
		k.insert_v(n);
		break;
	    case 2:
		cout<<"\nENTER EDGE\nSC\nDE";
		cin>>n>>m;
		k.insert_e(n,m);
		break;
	    case 3:
		k.display_v();
		break;
	    case 4:
		cout<<"VERTEX=";
		cin>>n;
		k.adjacent_v(n);
		break;
	    case 5:
		k.display();
		break;
	    case 6:
		exit(0);
		break;
	}
    } while (ch!=6);
    getch();
    
}