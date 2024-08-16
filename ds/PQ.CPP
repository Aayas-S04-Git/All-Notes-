#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class queue
{
    int item[max],prio[max],front,rear;
public:
    void create(queue *);
    void insert(queue *,int,int);
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear=-1;
    cout<<"Priority Queue is created ";
}
void queue::insert(queue *p,int x,int pr)
{
    if(p->rear==max-1)
    {
	cout<<"Priority Queue Overflow";
    }
    else
    {
	++p->rear;
	p->item[p->rear]=x;
	p->prio[p->rear]=pr;
    }
}
int queue::remove(queue *p)
{
    if(p->front==p->rear)
    {

	cout<<"Priority Queue Underflow";
	return(0);
    }
    else
    {
	int m,pos=0,i,z;
	m=p->prio[0];
	for ( i = p->front+1; i<=p->rear; i++)
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
    cout<<"Queue Elements \n";
    for(i=p->front+1;i<=p->rear;i++)
    {
	cout<<"\t"<<p->item[i];
    }
    cout<<"\nElements Priority \n";
    for(i=p->front+1;i<=p->rear;i++)
    {
	cout<<"\t"<<p->prio[i];
    }
}
void main()
{
 clrscr();
 int ch,n,x,pr;
 queue obj,p,*q;
 q=&p;
 do
 {

cout<<"\n1:Create\n2:Insert\n3:Remove\n4:Display\n5:Exit :";
 cin>>ch;
 switch(ch)
 {
case 1:
obj.create(q);
break;
case 2:
cout<<"\nEnter ele= ";
cin>>n;
cout<<"\nEnter Pri=";
cin>>pr;
obj.insert(q,n,pr);
break;
case 3:
x=obj.remove(q);
cout<<"\nRemoved Val="<<x;
break;
case 4:
obj.display(q);
break;
case 5:
exit(0);
 }
 }while(ch!=5);
 getch();
}
