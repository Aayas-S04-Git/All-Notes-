#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class queue
{
public:
	int item[max],front,rear,prio[max];
public:
	void create(queue *);
	void insert(queue *,int ,int );
	int remove (queue *);
	void display(queue *);
};
void queue::create(queue *p)
{
	p->front=p->rear=-1;
}
void queue::insert(queue *p,int n,int pr)
{
	if(p->rear==max-1)
	{
		cout<<"Queue is Overflow";
	}
	else
	{
		++p->rear;
		p->item[p->rear]=n;
		p->prio[p->rear]=pr;
	}
}
int queue::remove(queue *p)
{
    int m,pos=0,z,i;
    if(p->front==p->rear)
    {
		cout<<"Queue Underflow";
		return(0);
    }
    else
    {
	m=p->prio[0];
	for(i=p->front+1;i<=p->rear;i++)
	{
		if(m<p->prio[i])
		{
		      m=p->prio[i];
		      pos=i;
		}
	}
	z=p->item[pos];
	for(i=pos;i<=p->rear;i++)
	{
	    p->item[i]=p->item[i+1];
	    p->prio[i]=p->prio[i+1];
	}
	--p->rear;
	return(z);
     }

}
void queue::display(queue *p)
{
	int i;
	cout<<"\nPriority of element =\n";
	for(i=p->front+1;i<=p->rear;i++)
	{
		cout<<"\t"<<p->prio[i];
	}
	cout<<"\nNumber of element =\n";
	for(i=p->front+1;i<=p->rear;i++)
	{
		cout<<"\t"<<p->item[i];
	}
}
void main()
{
	clrscr();
	int n,ch,prio,z;
	queue *p,q,obj;
	p=&q;
	do
	{
		cout<<"\n1:create\n2:insert\n3:remove \n4:display\n5:exit\n";
		cout<<"\nEnter your choice =";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create(p);
				break;
			case 2:
				cout<<"Enter any no =";
				cin>>n;
				cout<<"Enter priority of the no=";
				cin>>prio;
				obj.insert(p,n,prio);
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