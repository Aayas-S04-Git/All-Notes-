#include<conio.h>
#include<process.h>
#include<iostream.h>
#define max 10
class stack
{
        int item[max],top;
    public:
        void create(stack *);
        void isempty(stack *);
        void isfull(stack *);
	void push(stack *,int);
        int pop(stack *);
        void dispalay(stack*);
};
void stack::create(stack *p)
{
    p->top=-1;
    cout<<"Stack is create";
}
void stack::isempty(stack *p)
{
    if(p->top==-1)
    {
        cout<<"Satck is empty";
    }
    else
    {
        cout<<"Stack is Not empty";
    }
}
void stack::isfull(stack *p)
{
    if(p->top==max-1)
    {
        cout<<"Stack is Full";
    }
    else{
        cout<<"stack is Not empty";
    }
}
int stack::pop(stack *p)
{
    if(p->top==-1)
    {
        cout<<"Stack Underflow";
        return(0);
    }
    else
    {
        return(p->item[p->top--]);
    }
}
void stack::push(stack *p,int x)
{
    if(p->top==max-1)
    {
        cout<<"Stack Overflow";
    }
    else
    {
        ++p->top;
        p->item[p->top]=x;
    }
}
void stack::dispalay(stack *p)
{
    int i;
    for(i=p->top;i>=0;i--)
    {
        cout<<"\n"<<p->item[i];
    }
}
void main()
{
    clrscr();
    int n,ch;
    stack *p,q,obj;
    p=&q;
    do
    {
	cout<<"\n1:create\n2:isempty\n3:isfull\n4:push\n5:pop\n6:display\n7:Exit";
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
	    cout<<"ENter any no to insert :";
	    cin>>n;
	    obj.push(p,n);
	    break;
	case 5:
	    n=obj.pop(p);
	    cout<<"Removed elelment ="<<n;
	    break;
	case 6:
	    obj.dispalay(p);
	    break;
	case 7:
		exit(0);
        default:
            break;
        }
    } while(ch!=7);
    
    getch();
}