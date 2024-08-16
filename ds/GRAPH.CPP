#include<iostream.h>
#include<conio.h>
#include<process.h>

class edge
{
	public:
	int dest;
	edge *right;
};

class node
{
	public:
	int info;
	node *next;
	edge *adj;
	void insert(int);
	void display_Vertex();
	void insert_Edge(int,int);
	void display_Edge(int);
	void search(int);
	void display_Graph();
}*start;

void node::insert(int n)
{
	node *p=new node;
	p->next=NULL;
	p->info=n;
	p->adj=NULL;
	if(start==NULL)
	{
	  start=p;
	}
	else
	{
	 node *k=start;
	 while(k->next!=NULL)
	 {
	 k=k->next;
	 }
	 k->next=p;
	}
	cout<<"\nNode is Innserted";
}

void node::display_Vertex()
{
	node *p=start;
	while(p!=NULL)
	{
	 cout<<"\t"<<p->info;
	 p=p->next;
	}
}
void node::search(int n)
{
	int t=0;
	node *p=start;
	while(p!=NULL)
	{
	  if(p->info==n)
	  {
	   t=1;
	   break;
	  }
	  p=p->next;
	}
	if(t==1)
	  cout<<"\nFound";
	else
	 cout<<"\nNOT Found";
}

void node::insert_Edge(int n,int x)
{
	int t=0,m=0;
	node *p,*q;
	q=start;
	p=start;
	while(p!=NULL)
	{
	 if(p->info==n)
	 {
	 t=1;
	 break;
	 }
	 p=p->next;
	}
	while(q!=NULL)
	{
		if(q->info==x)
		{
			m=1;
			break;
		}
		q=q->next;
	}
	if(t==1 && m==1)
	{
	 edge *z=new edge;
	 z->dest=x;
	 z->right=NULL;
	 if(p->adj==NULL)
	 {
	 p->adj=z;
	 }
	 else
	 {
	 edge *o=p->adj;
	 while(o->right!=NULL)
	 {
	 o=o->right;
	 }
	 o->right=z;
	 }
	}
	else 
	  cout<<"\nInvalid Edge";
}

void node::display_Edge(int n)
{
	int t=0;
	node  *p=start;
	while(p!=NULL)
	{
		if(p->info==n)
		{
			t=1;
			break;
		}
		p=p->next;
	}
	if(t==1)
	{
		edge *z=p->adj;
		while(z!=NULL)
		{
			cout<<"\t"<<z->dest;
			z=z->right;
		}
	}
	else
	{
		cout<<"\nNode is NOT Found";
	}
}

void node::display_Graph()
{
	node *p=start;
	while(p!=NULL)
	{
		cout<<"\n"<<p->info;
		if(p->adj!=NULL)
		{
			edge *z=p->adj;
			while(z!=NULL)
			{
				cout<<"->"<<z->dest;
				z=z->right;
			}
		}
		p=p->next;
	}
}

void main()
{
	 int n,ch,dest;
	 clrscr();
	 node k;
	 do
	 {
	 cout<<"\n1.Insert\n2.Display\n3.Search\n4.Insert_Edge\n5.Display_Edge\n6.Display_Graph\n7.Exit";
	 cout<<"\nEnter Your Choice: ";
	 cin>>ch;
	 switch(ch)
	 {
	 case 1:
	 		cout<<"\nEnter The No: ";
	 		cin>>n;
	 		k.insert(n);
	 		break;
	 case 2:
	 		k.display_Vertex();
	 		break;
	 case 3:
	 		cout<<"\nEnter The Node: ";
	 		cin>>n;
	 		k.search(n);
	 		break;
	 case 4:
	 		cout<<"\nEnter The Parent Node: ";
	 		cin>>n;
	 		cout<<"\nEnter The Value: ";
	 		cin>>dest;
	 		k.insert_Edge(n,dest);
	 		break;
	 case 5:
	 		cout<<"\nEnter The Vertex: ";
	 		cin>>n;
	 		k.display_Edge(n);
	 		break;
	 case 6:
	 		k.display_Graph();
	 		break;
	 case 7:
	 		exit(5);
	 }
	 }while(ch!=7);
	getch();
}