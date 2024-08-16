#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 20
class queue
{
    int item[max],front,rear;
public:
    void create(queue *);
    void isempty(queue *);
    void isfull(queue *);
    void insert(queue *,int);
    int remove(queue *);
    void display(queue *);
};
void queue::create(queue *p)
{
    p->front=p->rear=-1;
    cout<<"Queue is created";
}
void queue::isempty(queue *p)
{
    if(p->front==p->rear)
    {
        cout<<"Queue is Empty";
    }
    else
    {
        cout<<"Queue is Not Empty";
    }
}
void queue::isfull(queue *p)
{
    if(p->rear==max-1)
    {
        cout<<"Queue is Full";
    }
    else
    {
        cout<<"Queue is Not Full";
    }
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
        cout<<"\t"<<p->item[i];
    }
}
void main()
{
    clrscr();
    int n,z,ch;
    queue *p,q,obj;
    p=&q;
    do
    {
	cout<<"\n1:Create\n2:isempty\n3:isfull\n4:insert\n5:remove\n6:display\n7:Exit";
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
	    cout<<"Enter any no to insert =";
	    cin>>n;
            obj.insert(p,n);
            break;
        case 5:
            z=obj.remove(p);
            cout<<"Removed element ="<<z;
            break;
        case 6:
            obj.display(p);
            break;
        case 7:
            exit(0);        
        default:
            break;
        }
    } while (ch!=7);
    getch();   
}