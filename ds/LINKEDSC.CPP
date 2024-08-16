#include <conio.h>
#include <iostream.h>
#include <process.h>
class node
{
	int info;
	node *next;
public:
	node* create();
	void insert_f(int);
	void insert_m(int ,int);
	void insert_l(int);
	int remove_f();
	int remove_m(int);
	int remove_l();
	void search(int);
	void count();
	void reverse();
	void display();
}*list;
node* node::create()
{
	node *p;
	p=new node;
	return(p);
}
void node::insert_f(int x)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		p=create();
		p->info=x;
		p->next=p;
		list=p;
	}
	else
	{
		q=create();
		while(p->next!=list)
		{
			p=p->next;
		}
		q->info=x;
		q->next=p->next;
		p->next=q;
		list=q;
	}
}
void node::insert_m(int x,int a)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		cout<<"\nll is empty";
	}
	else if(p->next==list)
	{
		cout<<"\nNot Possible";
	}
	else
	{
		while(p->next!=list)
		{
			if(p->info==a)
			{
				q=create();
				q->next=p->next;
				q->info=x;
				p->next=q;
				break;
			}
			p=p->next;
		}

	}
}
void node::insert_l(int x)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		p=create();
		p->info=x;
		p->next=p;
		list=p;
	}
	else
	{
		while(p->next!=list)
		{
			p=p->next;
		}
		q=create();
		q->info=x;
		q->next=p->next;
		p->next=q;
	}
}
int node::remove_f()
{
	node *p,*q;
	int z;
	p=list;
	if(p==NULL)
	{
		cout<<"\nLL is empty";
	}
	else if(p->next==NULL)
	{
		z=p->info;
		list=NULL;
		delete(p);
		return(z);
	}
	else
	{
		while(p->next!=list)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		z=q->info;
		list=q->next;
		delete(q);
		return(z);
	}
}
int node::remove_m(int x)
{
	node *p,*q;
	int z;
	p=list;
	if(p==NULL)
	{
		cout<<"\nLL is Empty";
	}
	else if(p->next==list || p->next->next==list)
	{
		cout<<"\nImpossible";
	}
	else
	{
		while(p->next!=list)
		{
			if(p->info==x)
			{
				q=p->next;
				z=q->info;
				p->next=q->next;
				z=q->info;
				delete(q);
			}
		}
		return(z);
	}
}
int node::remove_l()
{
	node *p,*q;
	int z;
	p=list;
	if(p==NULL)
	{
		cout<<"\nLL is Empty";
	}
	else if(p->next==list)
	{
		z=p->info;
		list=NULL;
		delete(p);
		return(z);
	}
	else
	{
		while(p->next->next!=list)
		{
			p=p->next;
		}
		q=p->next;
		z=q->info;
		p->next=q->next;
		delete(q);
		return(z);
	}
}
void node::search(int x)
{
	node *p;
	int t=0;
	p=list;
	do
	{
		if(p->info==x)
		{
			t=1;
			break;
		}
		p=p->next;
	}while(p->next!=list);
	if(t==1)
	{
		cout<<"\nNode is Found";
	}
	else
	{
		cout<<"\nNode is Not Found";
	}
}
void node::count()
{
	node *p;
	p=list;
	int cnt=0;
	do
	{
		cnt++;
		p=p->next;
	}while(p!=list);
	cout<<"\nCount="<<cnt;
}
void node::reverse()
{
	node *t1,*t2=NULL,*t3=NULL;
	t1=list;
	do
	{
		t2=t1->next;
		t1->next=t3;
		t3=t1;
		t1=t2;
	}while(t1!=list);
	list=t3;
	t1->next=t3;
	cout<<"\nReversed";
}
void node::display()
{
	node *p;
	p=list;
	do
	{
		cout<<"\t"<<p->info;
		p=p->next;
	}while(p!=list);
}
void main()
{
	int a,b,c;
	clrscr();
	node p;
	do
	{
		cout<<"\nOperations on SCLL\n1:insert_f\n2:insert_m\n3:insert_l\n4:remove_f\n5:remove_m\n6:remove_l\n7:search\n8:count\n9:reverse\n10:display\n11:exit";
		cout<<"\nEnter Your Choice=";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"\nEnter";
				cin>>a;
				p.insert_f(a);
				break;
			case 2:
				cout<<"\nEnter=";
				cin>>a;
				cout<<"\nEnter=";
				cin>>b;
				p.insert_m(a,b);
				break;
			case 3:
				cout<<"\nEnter";
				cin>>a;
				p.insert_l(a);
				break;	
			case 4:
				a=p.remove_f();
				cout<<"\nRemoved="<<a;
				break;
			case 5:
				cout<<"\nEnter=";
				cin>>a;
				a=p.remove_m(b);
				cout<<"\nRemoved="<<a;
				break;
			case 6:
				a=p.remove_l();
				cout<<"\nRemoved="<<a;
				break;	
			case 7:
				cout<<"\nEnter=";
				cin>>a;
				p.search(a);
				break;
			case 8:
				p.count();
				break;
			case 9:
				p.reverse();
				break;
			case 10:
				p.display();
				break;
			case 11:
				exit(0);
				break;		
		}
	}while(c!=11);
	getch();
}
