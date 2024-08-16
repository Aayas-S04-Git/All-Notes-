#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class queue
{
    int item[max],front,rear;
public:
    void create(queue *);
    void insert(queue *,int);
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear=-1;
    cout<<"Circular Queue is Created ";
}
void queue::insert(queue *p,int x)
{
    if(((p->front==0)&&(p->rear==max-1))&&(p->front==p->rear+1))
    {
	cout<<"Queue Overflow";
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
int queue::remove(queue *p)
{
    if(p->front==-1)
    {
	cout<<"Queue is UNderflow";
	return(0);
    }
    else{
	int x;
	x=p->item[p->front];
	if(p->front==p->rear)
	{
	    p->front=p->rear=-1;
	}
	else
	{
	    p->front=(p->front+1)%max;
	}
	return(x);
    }
}
void queue::display(queue *p)
{
    int i;
    for(i=p->front;i!=p->rear;i++)
    {
	cout<<"\t"<<p->item[i];
    }
    cout<<"\t"<<p->item[i];

}
void main()
{
    clrscr();
    int n,ch,z;
    queue *p,q,obj;
    do
    {
	cout<<"\n1:create\n2:insert\n3:remove\n4:display\n5:Exit\n";
	cout<<"\nEnter your choice =";
	cin>>ch;
	switch (ch)
	{
	case 1:
	    obj.create(p);
	    break;
	case 2:
	    cout<<"\nEnter any no to insert :";
	    cin>>n;
	    obj.insert(p,n);
	    break;
	case 3:
	    z=obj.remove(p);
	    cout<<"Reemoved element ="<<z;
	    break;
	case 4:
	    obj.display(p);
	    break;
	case 5:
		exit(0);
	default:
	    break;
	}
    } while(ch!=7);
	getch();
}