#include<conio.h>
#include<iostream.h>
#include<process.h>
#define max 10
class queue
{
    int item[max],front,rear;
public:
    void create(queue *);
    void insert(queue *,int );
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear=-1;
    cout<<"Queue is created ";
}
void queue::insert(queue *p,int x)
{
    if((p->front==0&&p->rear==max-1)||(p->front==p->rear+1))
    {
        cout<<"Queue is Overflow";
    }
    else
    {
        if(p->front==-1)
        {
            p->front=p->rear=0;
        }
        else{
            p->rear=(p->rear+1)%max;
        }
        p->item[p->rear]=x;
    }
}
int queue::remove(queue *p)
{
    int z;
    if(p->front==-1)
    {
	cout<<"Queue Underflow ";
	return(0);
    }
    else
    {
	z=p->item[p->front];
	if(p->front==p->rear)
	{
	    p->rear=p->front=-1;
	}
	else
	{
	    p->front=(p->front+1)%max;
	}
	return(z);
    }
}
void queue::display(queue *p)
{
    int i;
    for(i=p->front;i!=p->rear;i++)
    {
        cout<<"\t"<<p->item[i];
    }
    cout<<"\t"<<p->item[p->rear];
}
void main()
{
	clrscr();
	int n,ch,z;
	queue  *p,q,obj;
	p=&q;
	do
	{
		cout<<"1:create\n2:insert\n3:remove \n4:display\n5:exit\n";
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
				obj.insert(p,n);
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
	}while(ch!= 7);
	getch();
}