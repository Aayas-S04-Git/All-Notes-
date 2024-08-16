#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class queue
{
	int item[max],front,rear;
public:
	void create(queue *);
	void insert(queue *,int );
	void display(queue *);
	void isempty(queue *);
	void isfull(queue *);
	int remove(queue *);      
};
void queue::create(queue *p)
{
      p->front=p->rear=-1;
	cout<<"Queue is created ";
}
void queue::isempty(queue *p)
{
	if(p->front==-1)
	{
		cout<<"Queue is empty";
	}
	else
	{
		cout<<"Queue is NOt empty";
	}
}
void queue::isfull(queue *p)
{
	if((p->front==0&&p->rear==max-1)||(p->front==p->rear+1))
	{
		cout<<"Queue is full";
	}
	else
	{
		cout<<"Queue is NOt Full";
	}
}
void queue::insert(queue *p,int x)
{
	if((p->front==0&&p->rear==max-1)||(p->front==p->rear+1))
	{
		cout<<"Queue Overflow";
	}
	else
	{
		if(p->front==-1)
		{
			p->rear=p->front=0;
		}
		else
		{
			p->rear=(p->rear+1)%max;
		}
	}
	p->item[p->rear]=x;
}
int queue::remove(queue *p)
{       int z;
	if(p->front==-1)
	{
		cout<<"Queue Underflow";
		return(0);
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
			p->front=(p->front+1)%max;
		}
	}
	return(z);
}
void queue::display(queue *p)
{
	int i;
	for(i=p->front;i!=p->rear;i=(i+1)%max)
	{
		cout<<"\t"<<p->item[i];
	}
	cout<<"\t"<<p->item[p->rear];
}
void main()
{
	int n,ch,z;
	queue *p,q,obj;
	p=&q;
	do
	{
		cout<<"1:Create\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:exit\n";
		cout<<"Enter your choice=";
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
    			cout<<"Enter any element to insert";
    			cin>>n;
   			 obj.insert(p,n);
   			 break;
	 	case 5:
    			z=obj.remove(p);
    			cout<<"Removed element="<<z;
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