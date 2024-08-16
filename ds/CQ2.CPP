#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 10
class queue
{
public:
    int item[max],front,rear;
    void create(queue *);
    void isempty(queue *);
    void isfull(queue *);
    void insert(queue *,int);
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear;
    cout<<"Circular Queue is Created";
}
void queue::isempty(queue *p)
{
    if(p->front==-1)
    {
        cout<<"Circular Queue is Empty";
    }
    else
    {
        cout<<"Circular Queue is Not Empty";       
    }
}
void queue::isfull(queue *p)
{
    if((p->front==0 && p->rear==max-1)&&(p->front ==p->rear+1))
    {
        cout<<"Circular Queue is Full";
    }
    else
    {
        cout<<"Circular Queue is Not Full";
    }
}
void queue::insert(queue *p,int x)
{
    if((p->front==0 && p->rear==max-1)&&(p->front ==p->rear+1))
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
	cout<<"Element is inserted";
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
            p->front=(p->front+1)%max;
        }
        return(z);
    }

}
void queue::display(queue *p)
{
    int i;
    for(i=p->front+1;i!=p->rear;i++)
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
	cout<<"\n1:create\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:Exit\n";
	cout<<"\nEnter your choice =";
	cin>>ch;
	switch (ch)
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
	    cout<<"\nEnter any no to insert :";
	    cin>>n;
	    obj.insert(p,n);
	    break;
	case 5:
	    z=obj.remove(p);
	    cout<<"Reemoved element ="<<z;
	    break;
	case 6:
	    obj.display(p);
	    break;
	case 7:
		exit(0);
	default:
	    break;
	}
    } while(ch!=7);
	getch();
}