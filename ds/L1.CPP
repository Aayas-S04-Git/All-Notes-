#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class node
{
	int info;
	node *next;
public:
	node* create();
	void insert_beg(int  );
	void insert_end(int  );
	void insert_bett(int,int);
	int remove_beg();
	int remove_end();
	int remove_bett(int );
	void display();
	void search(int);
	void count();
	void reverse();
}*list;
node* node::create()
{
	node *z;
	z=new node();
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
		list=p;
	}
	else
	{
		q=create();
		q->info=x;
		q->next=NULL;
		q->next=p;
		list=q;
	}
} 
void node::insert_end(int x)
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
void node::insert_bett(int x,int aft)
{
	node *p,*q;
	p=list;
	if(p==NULL||p->next==NULL)
	{
		cout<<"Insert bettween is not possible";
	}
	else
	{
		while(p->next!=NULL)
		{
			if(aft==p->info)
			{
				q=create();
				q->info=x;
				q->next=NULL;
				q->next=p->next;
				p->next=q;

			}
			p=p->next;
		}
	}
}
int node::remove_beg()
{
	int z;
	node *p;
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
int node::remove_end()
{
	node *p,*temp;
	p=list;
	int z;
	if(p==NULL)
	{
		cout<<"Linked list is empty";
		return(0);
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
int node::remove_bett(int aft)
{
	node *p,*temp;
	p=list;
	int z;
	if(p==NULL)
	{
		cout<<"Linked list is empty";
		return(0);
	}
	else if(p->next==NULL|| p->next->next==NULL)
	{
		cout<<"Remove between is not possible";
		return(0);
	}
	else
	{
		while(p->next!=NULL)
		{
			if(aft==p->info)
			{
				temp=p->next;
				z=temp->info;
				p->next=temp->next;
				delete(temp);
			}
			p=p->next;
		}
		return(z);
	}

}
void node::search(int srch)
{
	node *p;
	int t=0;
	p=list;
	while(p!=NULL)
	{
		if(srch==p->info)
		{
			t=1;
		}
		p=p->next;
	}
	if(t==1)
	{
		cout<<"Element is found";
	}
	else
	{
		cout<<"Element is not found";
		
	}
}
void node::count()
{
	node *p;
	p=list;
	int cnt=0;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	cout<<"Node Count is ="<<cnt;
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
void node::reverse()
{
	node *t1,*t2,*t3;
	t1=list;
	t2=t3=NULL;
	while(t1!=NULL)
	{
		t2=t1->next;
		t1->next=t3;
		t3=t1;
		t1=t2;
	}
	list=t3;
	cout<<"Linked list is reversed";
}
void main()
{
	clrscr();
	int n,z,ch,aft,srch;
	node obj;
	do
	{
		cout<<"\n1:insert begin \n2:insert end \n3:insert bett\n4:remove begin \n5:remove end\n6:Remove bett\n7:search\n8:count\n9:display\n10:reverse\n11:Exit\n";
		cout<<"Enter your choice =";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter ele to insert =";
				cin>>n;
				obj.insert_beg(n);
				break;
			case 2:
				cout<<"Enter ele to insert =";
				cin>>n;
				obj.insert_end(n);
				break;
			case 3:
				cout<<"Enter ele to insert =";
				cin>>n;
				cout<<"Enter after which node =";
				cin>>aft;
				obj.insert_bett(n,aft);
				break;
			case 4:
				z=obj.remove_beg();
				cout<<"Removed ele="<<z;
				break;
			case 5:
				z=obj.remove_end();
				cout<<"Removed ele="<<z;
				break;
			case 6:
				cout<<"After which ele =";
				cin>>aft;
				z=obj.remove_bett(aft);
				cout<<"Removed ele="<<z;
				break;
			case 7:
				cout<<"Enter search ele=";
				cin>>srch;
				obj.search(srch);
				break;
			case 8:
				obj.count();
				break;
			case 9:
				obj.display();
				break;
			case 10:
				obj.reverse();
				break;
			case 11:
				exit(0);
			default:
				cout<<"Wrong input";
		}
	}while (ch!=11);
	getch();
}