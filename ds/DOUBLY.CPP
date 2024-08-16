#include<iostream.h>
#include<conio.h>
#include<process.h>

class node
{
	public:
	int info;
	node *next,*pre;
	node* create();
	void insert_Begin(int);
	void insert_End(int);
	void insert_After(int,int);
	int remove_Begin();
	int remove_End();
	int remove_After(int);
	void reverse();
	void search(int);
	void count();
	void display();
}*list;

node* node::create()
{
	node *z;
	z=new node;
	return(z);
}

void node::insert_Begin(int n)
{
	node *p;
	if(list==NULL)
	{
		p=create();
		p->next=NULL;
		p->info=n;
		p->pre=NULL;
		list=p;

	}
	else
	{
		p=create();
		p->next=list->next;
		p->info=n;
		p->pre=NULL;
		list=p;
	}
	cout<<"\nNode is inserted";
}

void node::insert_End(int n)
{
	node *p;
	if(list==NULL)
	{
		p=create();
		p->next=NULL;
		p->info=n;
		p->pre=NULL;
		list=p;
	}
	else
	{
		node *t=list;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		p=create();
		p->next=NULL;
		p->info=n;
		p->pre=t;
		t->next=p;

	}
	cout<<"\nNode is inserted";
}

void node::insert_After(int after,int n)
{
	node *p=list;
	if(p==NULL || (p->next==NULL&&p->pre==NULL))
	{
		cout<<"\nUnable insert Node";
	}
	else
	{
		node *t=list;
		while(t->next!=NULL)
		{
			if(t->info==after)
			{
				p=create();
				p->next=t->next;
				p->info=n;
				p->pre=t;
				t->next->pre=p;
				t->next=p;
			}
			t=t->next;
		}
	}
	cout<<"\nNode is inserted";
}

int node::remove_Begin()
{
	node *p=list;
	int z;
	if(p==NULL)
	{
		cout<<"\nList Is Empty";
		return 0;
	}
	else if(p->next==NULL && p->pre==NULL)
	{
		z=p->info;
		delete(p);
		list=NULL;
		return(z);
	}
	else
	{
		z=p->info;
		p->next->pre=NULL;
		list=p->next;
		delete(p);
		return(z);
	}
}

int node::remove_End()
{
	node *p=list;
	int z;
	if(p==NULL)
	{
		cout<<"\nList is Empty";
		return 0;
	}
	else if(p->next==NULL && p->pre==NULL)
	{
		z=p->info;
		delete(p);
		list=NULL;
		return z;
	}
	else
	{
		while(p->next->next!=NULL)
		{
			p=p->next;
		}
		node *temp=p->next;
		z=temp->info;
		p->next=NULL;
		delete(temp);
		return(z);

	}
}

int node::remove_After(int after)
{
	node *p=list;
	int z;
	if(p==NULL)
	{
		cout<<"\nList is Empty";
		return 0;
	}
	else if((p->next==NULL &&p->pre==NULL)|| (p->next->next==NULL && p->next->pre==NULL))
	{
		cout<<"\nUnable To insert Node";
		return 0;
	}
	else
	{
		while(p->next!=NULL)
		{
			if(p->info==after)
			{
				node *temp=p->next;
				z=temp->info;
				p->next=temp->next;
				temp->next->pre=p;
				delete(temp);
				return(z);
			}
			p=p->next;
		}
	}
}
void node::display()
{
  node *p=list;
  while(p!=NULL)
  {
   cout<<"\t"<<p->info;
   p=p->next;
  }
}
void node::count()
{
	node *p=list;
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}

	cout<<"\nTotal Nodes: "<<cnt;
}

void node::search(int srch)
{
	node *p=list;
	int t=0;
	while(p!=NULL)
	{
		if(p->info==srch)
		{
			t=1;
			break;
		}
		p=p->next;
	}
	if(t==1)
		cout<<"\nNode is Found";
	else
		cout<<"\nNode is NOT Found";
}

void node::reverse()
{
	node *t1=list,*t2,*t3=NULL;
	while(t1!=NULL)
	{
		t2=t1->next;
		t1->next=t3;
		t1->pre=t2;
		t3=t1;
		t1=t2;
	}
	list=t3;
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
			cout<<"\nEnter The No.: ";
			cin>>n;
			k.insert_Begin(n);
			break;
		case 2:
			cout<<"\nEnter The No.: ";
			cin>>n;
			k.insert_End(n);
			break;
		case 3:
			cout<<"\nEnter After Which Node You Want To  Insert: ";
			cin>>after;
			cout<<"\nEnter The NO.: ";
			cin>>n;
			k.insert_After(after,n);
			break;
		case 4:
			n=k.remove_Begin();
			cout<<"\nRemoved Node: "<<n;
			break;
		case 5:
			n=k.remove_End();
			cout<<"\nRemoved Node.: "<<n;
			break;
		case 6:
			cout<<"\nAfter Which node ou Want To delete The Node: ";
			cin>>after;
			n=k.remove_After(after);
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