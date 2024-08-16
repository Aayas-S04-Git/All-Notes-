#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 5

class queue

{
	public:
	int item[max],rear,front;
	void create(queue*);
	void insert(queue*,int);
	int remove(queue*);
	void display(queue*);
};
void queue::create(queue *q)
{
	q->rear=q->front=-1;
	cout<<"\nQueue is created";
}
void queue::insert(queue *q,int x)
{
	if(q->rear==max-1)
	{
	  cout<<"\nQueue is Overflow";
	}
	else
	{
	 ++q->rear;
	 q->item[q->rear]=x;
	}
}
int queue::remove(queue *q)
{
	  if(q->front==q->rear)
	  {
	    cout<<"\nQueue is Underflow";
	    return 0;
	  }
	  else
	  {
	    ++q->front;
	    return(q->item[q->front]);
	  }
}

void queue::display(queue *q)
{
	 for(int i=q->rear;i>=q->front;i--)
	 {
	  cout<<"\t"<<q->item[i];
	 }
}
void main()
{
	 int n,ch;
	 clrscr();
	 queue *q,p,k;
	 q=&p;
	 do
	 {
	   cout<<"\n1.Create\n2.Insert\n3.Remove\n4.Display\n5.Exit";
	   cout<<"\nEnter Your Choice: ";
	   cin>>ch;
	   switch(ch)
	   {
	     case 1:
			k.create(q);
	     		break;
	     case 2:
	     		cout<<"\nEnter The no: ";
	     		cin>>n;
	     		k.insert(q,n);
	     		break;
	     case 3:
	     		n=k.remove(q);
			cout<<"\nRemoved Element: "<<n;
	     		break;
	     case 4:
	       		k.display(q);
	       		break;
	     case 5:
	     		exit(5);
	    }
	 }while(ch!=5);
	 
  getch();

 }
