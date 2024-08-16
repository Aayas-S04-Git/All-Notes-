#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class     queue
{
	int item[max],front,rear;
public:
	void create(queue *);
	void isempty(queue *);
	void isfull(queue *);
	void insert(queue *int);
	int remove(queue *p);
	void display(queue *p);
};
void   queue::create(queue *p)
{
	p->front=p->rear=-1;
	cout<<"Queue is created ";
}
void   queue::isempty(queue *p)
{
	if(p->front==-1)
	{
		cout<<"Queue is emoty";
	}
	else
	{
		cout<<"Queue is Not empty";
	}
}
void   queue::isfull(queue *p)
{
	if((p->front==-1&&p->rear==max-1)||(p->front==p->rear+1))
	{
		cout<<"Queue is full";
	}
	else
	{
		cout<<"Queue is not full";	
	}
}
void   queue::insert(queue *p,int  x)
{
	if((p->fron==-1&&p->rear==max-1)||(p->front==p->rear+1))
	{
		cout<<"Queue Overflow";
	}
	else
	{
		if(p->front ==-1)
		{
			p->front=p->rear=0;
		}
		else
		{
			p->rear=(p->rear+1)%max;
		}
	}
}
void    queue::remove(queue *p)
{
	int z;
	if(p->front==-1)
	{
		cout<<"Queue Underflow ";
	}
	else
	{
		z=p->item[p->front];
		if(p->front==p->rear)
		{
			p->front=p->rear=-1;
		}
		else
		{
			p-front=(p->front+1)%max;
		}
	} 
}
void  queue::display(queue *p)
{
	int i;
	for(i=p->front;i!=p->rear;i=(i+1)%max)
	{
		cout<<"\t"<<p->item[i];
	}
	cout<<"\t"<<p->item[p->rear];
}
void main(0
{
clrscr();
int n,ch,z;
queue   *p,q,obj;
p=&q;
do
{
	cout<<"\n1:crreate\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:Exit\n";
	cout<<"\nEnter your choice =";
	cin>>ch;
	switch(ch)
	{
		case 1:
			obj.create(p);
			break;
		case 2:
			obj.isempty(p);
			break;
		case 3:
			obj.isfull(p);
			break;
		case 4:
			cout<<"Enter any no to insert =";
			cin>>n;
			obj.insert(n,p);
			break;
		case 5:
			z=obj.remove(p);
			cout<<"Removed element ="<<z;
			break;
		case 6:
			obj.display(p);
			break;
		case 7:
			exit(0);
	}
}while(ch!=7);
getch();
}