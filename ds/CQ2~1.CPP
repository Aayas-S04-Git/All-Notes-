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
    cout<<"Queue is created ";
}
void queue::insert(queue *p,int x,int pr)
{
    if(p->rear==max-1)
    {
        cout<<"Queue Overflow";
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
        cout<<"Queue Underflow";
        return(0);
    }
    else
    {
        int i,m,pos=0,z;
        m=p->item[pos];
        for(i=p->front+1;i<=p->rear;i++)
        {
            if(m<p->item[pos])
            {
                m=p->item[i];
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
    cout<<"\nPriority=\n";
    for(i=p->front+1;i<=p->rear;i++)
    {
        cout<<"\t"<<p->prio[i];
    }
    cout<<"\nElements=\n";
    for(i=p->front+1;i<=p->rear;i++)
    {
        cout<<"\t"<<p->item[i];
    }
}
void main()
{
    clrscr();
    int n,ch,z;
    queue *p,q,obj;
    p=&q;
    do
    {
        cout<<"\n1:craete\n2:insert\n3:remove\n4:display\n5:Exit\n";
        cout<<"Enter your choice =";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.create(p);
            break;
        case 2:
            cout<<"Enter element to insert =";
            cin>>n;
            cout<<"Enter priority of an element =";
            cin>>z;
            obj.insert(p,n,z);
            break;
        case 3:
            z=obj.remove(p);
            cout<<"Removed ele ="<<z;
            break;
        case 4:
            obj.display(p);
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }while(ch!=5);
    getch();
}