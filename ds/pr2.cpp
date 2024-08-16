#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class   queue
{
	int item[max],prio[max],front,rear;
public:
	void    create(queue  *);
	void     insert(queue *,int ,int);
	void     display(queue *);
	int remove(queue *);
};
void    queue::create(queue *p)
{
	p->front=p->rear;
	cout<<"Priority Queue is created ";
}
void   queue::insert(queue *p,int x,int pr)
{
	if(p->rear==max-1)
	{
		cout<<"Queue Overflow";
	}
	else
	{
		++p->rear;
		p->item[p->rear]=x;
		p->prio[p->rear]=pr;
		cout<<"Element is inserted ";
	}	
}
void   queue::remove(queue *p)
{
	int i,m=0,pos=0,z;
	if(p->front==p->rear)
	{
		cout<<"queue Underflow";
		return(0);
	}
	else
	{
		m=prio[0];
		for(i=p->front+1;i<=p->rear;i++)
		{
			if(m<prio[i])
			{
				m=prio[i];
				pos=i;
			}
		}
		z=item[pos];
		for(i=pos;i<=p->rear;i++)
		{	
			p->item[i]=p->item[i+1];
		}
		--p->rear;
		eturn(z);
	}
}
void   queue::display(queue *p)
{
	int    i;

	cout<<"Priority of elements =\n";
	for(i=p-front+1;i<=p->rear;i++)
	{
		cout<<"\t"<<p->prio[i];
	}
	cout<<"\nElements of queue =\n";
	for(i=p->front+1;i<=p->rear;i++)
	{
		cout<<"\t"<<p->item[i];
	}
}
void   main()
{
clrscr();
int ch,n,z;
queue  *p,q,obj;
p=&q;
do
{
	cout<<"\n1:create\n2:insert\n3:remove\n4:display\n5:exit\n";
	cout<<"\nEnter your  choice =";
	cin>>ch;
	switch(ch)
	{
		case 1:
			obj.create(p);
			break;
		case 2:
			cout<<"Enter any no to insert =";
			cin>>n;
			cout<<"Priority of element =";
			cin>>z;
			obj.insert(p,n,z);
			break;
		case 3:
			z=obj.remove(p);
			cout<<"Removed element ="<<z;
			break;
		case 4:
			obj.display(p);
			break;
		case 5:
			exit(0);
	}
}while(ch!=5);
getch();
}