#include<iostream.h>
#include<conio.h>
#include<process.H>>
#define max 10
class queue
{
  int item[max],front,rear;
public:
   void create(queue *);
   void insert(queue *,int);
   void isfull(queue *);
   void isempty(queue *);
   int remove(queue *);
   void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear=-1;
    cout<<"\nQueue is created";
}
void queue::insert(queue *p,int x)
{
    if(p->rear==max-1)
    {
	cout<<"Queue Overflow";
    }
    else
    {
       ++p->rear;
       p->item[p->rear]=x;
    }
}
void queue::isempty(queue *p)
{
     if(p->front==p->rear)
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
    if(p->rear==max-1)
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
      if(p->front==p->rear)
      {
	cout<<"Queue Underflow";
	return(0);
      }
      else
      {
	++p->front;
	return(p->item[p->front]);
      }
}
void queue::display(queue *p)
{
     int i;
     for(i=p->front+1;i<=p->rear;i++)
     {
	cout<<"  "<<p->item[i];
     }
}
void main()
{
     clrscr();
     int n,ch,z;
     queue *p,q,b;
     p=&q;
     do
     {
	  cout<<"\n1:create\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:Exit\n";
	  cout<<"\nEnter your choice= ";
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
			cout<<"REmoved ele="<<z;
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