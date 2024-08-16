#include<iostream.h>
#include<conio.h>
#define max 5
#include<process.h>
class  queue
{
  int item[max],front,rear;
public:
   void create(queue *);
   void isempty(queue *);
   void isfull(queue *);
   void insert(queue *,int );
   int remove(queue *);
   void display(queue *);
};
void queue::insert(queue *p,int x)
{
    if((p->front==0&&p->rear==max-1)&&(p->front==p->rear+1))
    {
	cout<<"Queue Overfow";
    }
    else
    {
	  if(p->front==-1)
	  {
	     p->front=p->rear=0;
	  }
	  else
	  {
	     p->rear=(p->rear+1)%max;
	  }
	  p->item[p->rear]=x;
    }
}
void queue::create(queue *p)
{
     p->front=p->rear=-1;
     cout<<"Circuler queue is created";
}
void queue::isempty(queue *p)
{
    if(p->front==-1)
    {
       cout<<"Queue is empty";
    }
    else
    {
      cout<<"Queue is not empty";
    }
}
void queue::isfull(queue *p)
{
       if((p->front==0&&p->rear==max-1)&&(p->front==p->rear+1))
       {
		cout<<"Queue is full";
       }
       else
       {
	    cout<<"Queue is not full";
       }
}
int queue::remove(queue *p)
{
     if(p->front==-1)
     {
	 cout<<"Queue Underflow";
	 return(0);
     }
     else
     {
	  int z;
	  z=p->item[p->front];
	   if(p->front==p->rear)
	   {
		p->front=p->rear=-1;
	   }
	   else
	   {
	       p->front=(p->front)%max;
	   }
	   return(z);
     }
}
void queue::display(queue *p)
{
	int i;
	for(i=p->front;i!=p->rear;i=(i+1)%max)
	{
	     cout<<"  "<<p->item[i];
	}
	cout<<"  "<<p->item[i];
}
void main()
{
    clrscr();
    int n,z,ch;
    queue *p,q,b;
    p=&q;
    do
    {
	cout<<"\n1:Create\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:Exit\n";
	cout<<"\nEnter your choice =";
	cin>>ch;
	switch(ch)
	{
		case 1:
			b.create(p);
			break;
		case 2:
			b.isempty(p);
			break;
		case 3:
			b.isfull(p);
			break;
		case 4:
			cout<<"Enter any no=";
			cin>>n;
			b.insert(p,n);
			break;
		case 5:
			z=b.remove(p);
			cout<<"Removed element="<<z;
			break;
		case 6:
			b.display(p);
			break;
		case 7:
			exit(0);
		default:
			cout<<"Wrong input";
	}
    }while(ch!=7);
    getch();
}