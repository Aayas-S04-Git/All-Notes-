#include<iostream.h>
#include<conio.h>
#include<process.h>
#defie max 10
class node
{
	int info;
	node next;
public:
	node*   create();
	void  insert_beg(int );
	void  insert_end(int);
	void  insert_bett(int,int );
	int    remove_beg();
	int     remove_bett(int);
	int     remove end();
	void  display();
	void  search(int );
	void   reverse();
}list;
node * node::create()
{
	node *z;
	z=new node ;
	return(z);
}
void node::insert_beg(int x)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		p=create();
		p->info=x;
		p->next=NULL;	
		list=q;
	}
	else
	{
		q=create();
		q->info=x;
		q->next=p;
		list=q;
	}
}
void   node::inser_end(int x)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		p=create();
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
		q->next=NULL;
		q->info=x;
		p->next=q;
	}
}
void node::insert_bett(int x,int aft)
{
	node *p,*q;
	p=list;
	if(p==NULL)
	{
		p=create();
		p->infox=x;
		p->next=NULL;
		p=list;
	}
	else
	{
		while(p->next!=NULL)
		{
			if(p->info==aft)
			{
				q=create();
				q->info=x;
				q->next=NULL;
				p->next=q;
			}
			p=p->next;	
		}
	}
}
int node::remove_beg()
{
	node  *p;
	p=list;
	int z;
	if(p==NULL)
	{
		cout<<"Linked list is empty";
	}
	else	if(p->next==NULL)
	{
		z=p->info;
		p=NULL;
		delete(p);
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
int   node::remove_bett(int   aft )
{
	node *p,*temp;
	p=list;
	int   z;
	if(p==NULL)
	{
		cout<<"Linked list is empty";
	}
	else	if(p->next==NULL)
	{
		cout<<"Remove between is not possible ";
	}
	else  
	{
		while(p->next!=NULL)
		{
			if(p->info=aft)
			{
				temp=p->next;
				z=temp->info;
				p->next=temp->next;
				delete(temp);
				return(z);
			}
			p=p->next;
		}
	}
}
int   node::remove_end()
{
	node *p,*q;
	p=list;
	int   z;
	if(p==NULL)
	{
		cout<<"Linked list is empty";	
	}
	else	if(p->next==NULL)
	{
		z=p->info;
		list=NULL;
		delete(p);
		return(z);
	}
	else  
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}		
		q=p->next;
		z=q->info;
		p->next=NULL;
		delete(q);
		return(z);
	}
}
void  node::display()
{
	node *p;
	p=list;
	while(p!=NULL)
	{
		cout<<"\t"<<p->info;
		p=p->next;
	}
}
void  node::search(int srch)
{
	node *p;
	p=list;
	int t=0;
	if(p==NULL)
	{
		cout<<"linked list is empty";
	}
	else
	{
		while(p->next!=NULL)
		{
			if(p->info==srch)
			{
				t=1;
				break;
			}
			p=p->next;
		}
	}
	if(t==1)
	{
		cout<<"search element is found ";
	}
	else
	{
		cout<<"Search element is not found ";
	}
	
}
void node::reverse()
{
	node *t1,*t2,*t3;
	t1=list;
	t3=NULL;
	while(t1!=NULL)
	{
		t2=t1->next;
		t1->next=t2;
		t2=t1;
		t1=t3;
		p=p->next;
	}
	list=t3;
	cout<<"LInked list is reversed ";
}
void main()
{
clrscr();
int n,ch,z;
node *p,q,obj;
p=q;

getch();
}