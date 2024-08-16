
#include<iostream.h>
#include<conio.h>
#include<process.h>

class node
{
	public:
	int info;
	node *next,*prev;
	node* create();
	void insert_Begin(int);
	void insert_End(int);
	void insert_After(int,int);
	int remove_Begin();
	int remove_End();
	int remove_After(int);
	void search(int);
	void reverse();
	void count();
	void display();
}*list;

node* node::create()
{
	node *z;
	z=new node;
	return z;
}

void node::insert_Begin(int n)
{
	node *p=list,*q;
	if(p==NULL)
	{
		p=create();
		p->prev=p;
		p->info=n;
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
	   q->prev=p;
	   q->info=n;
	   q->next=p;
	   p->next=q;
	   list=p;
	}
	cout<<"\nNode is Inserted";
}

void node::insert_End(int n)
{
	node *p,*q;
	if(list==NULL)
	{
	p=create();
	p->prev=p;
	p->info=n;
	p->next=p;
	list=p;
	}
	else
	{
	q=list;
	while(q->next!=list)
	{
	  q=q->next;
	}
	p=create();
	p->prev=q;
	p->next=q->next;
	p->info=n;
	q->next=p;
	p->next->prev=p;
	}
	cout<<"\nNode is Inserted";
}

void node::insert_After(int after ,int n)
{
	node *p=list,*q;
	if(p==NULL || p->prev==p&&p->next==p)
	{
	  cout<<"\nUnable to Insert";
	}
	else
	{
	 p=list;
	 while(p->next!=list)
	 {
	  if(p->info==after)
	  {
	  q=create();
	  q->prev=p;
	  q->info=n;
	  q->next=p->next;
	  p->next=q;
	  q->next->prev=q;
	  }
	  p=p->next;
	 }
	}
	cout<<"\nNode is Innserted";
}

int node::remove_Begin()
{
	node *p=list;
	int z;
	if(p==NULL)
	{
	 cout<<"\nList is Empty";
	 return 0;
	}
	else if(p->next==NULL && p->prev==NULL)
	{
      z=p->info;
      delete(p);
      list=NULL;
      return z;
	}
	else
	{
	 while(p->next!=list)
	 {
	 p=p->next;
	 }
	 node *temp=p->next;
	 z=temp->info;
	 p->next=temp->next;
	 temp->next->prev=p;
	 list=temp->next;
	 delete(temp);
	 return z;
	}
}

int node::remove_End()
{
	node *p=list,*q;
	int z;
	if(p==NULL)
	{
		cout<<"\nList is Empty";
		return 0;
	}
	else if(p->next==NULL && p->prev==NULL)
	{
		z=p->info;
		delete(p);
		list=NULL;
		return z;
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
	q->next->prev=p;
	delete(q);
	return(z);
 }
}

int node::remove_After(int after)
{
	node *p=list,*q;
	int z;
	if(p==NULL)
	{
		cout<<"\nList is Empty";
		return 0;
	}
	else if(p->next==NULL && p->prev==NULL)
	{
		cout<<"\nUnable To Remove";
		return 0;
	}
	else
	{
		q=list;
		while(q->next!=list)
		{
			if(q->info==after)
			{
				node *temp=q->next;
				z=temp->info;
				p->next=temp->next;
				p->next->prev=p;
				delete(temp);
				return z;
			}
			q=q->next;
		}
	}
}

void node::search(int srch)
{
	int t=0;
	node *p=list;
	do
	{
		if(p->info==srch)
		{
			t=1;
			break;
		}
		p=p->next;
	}while(p!=list);
	if(t==1)
		cout<<"\nFound";
	else
		cout<<"\nNOT Found";
}

void node::count()
{
	int cnt=0;
	node *p=list;
	do
	{
		cnt++;
		p=p->next;
	}while(p!=list);
	cout<<"\nTotal Nodes: "<<cnt;
}

void node::reverse()
{
	node *t1=list,*t2,*t3=list;
	do
	{
		t2=t1->next;
		t1->next=t3;
		t1->prev=t2;
		t3=t1;
		t1=t2;
	} while(t1!=list);
	list=t3;
}
void node::display()
{
	node *p=list;
	do
	{
		cout<<"\t"<<p->info;
		p=p->next;
	} while(p!=list);
}
void main()
{
	int n,ch,after;
	clrscr();
	node k;
	do
	{
		cout<<"\n1.Insert_Begin\n2.Insert_End\n3.Insert_After\n4.Remove_Begin\n5.Remove_End\n6.Remove_After\n7.Search\n8.Count\n9.Reverse\n10.Display\n11.Exit";
		cout<<"\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"\nEnter The Node: ";
			cin>>n;
			k.insert_Begin(n);
			break;
		case 2:
			cout<<"\nEnter The Node: ";
			cin>>n;
			k.insert_End(n);
			break;
		case 3:
			cout<<"\nEnter After Which Node You Want To Insert Node: ";
			cin>>after;
			cout<<"\nEnter The Node: ";
			cin>>n;
			k.insert_After(after,n);
			break;
		case 4:
			n=k.remove_Begin();
			cout<<"\nRemoved Element: "<<n;
			break;
		case 5:
			n=k.remove_End();
			cout<<"\nRemoved Element: "<<n;
			break;
		case 6:
			cout<<"\nEnter After Which node u want to delete the node: ";
			cin>>after;
			k.remove_After(after);
			cout<<"\nRemoved Element: "<<n;
			break;
		case 7:
			cout<<"\nEnter The Node To Search: ";
			cin>>n;
			k.search(n);
			break;
		case 8:
			k.count();
			break;
		case 9:
			k.reverse();
			break;
		case 10:
			k.display();
			break;
		case 11:
			exit(5);
		}

	}while(ch!=11);
	getch();
}
