#include<iostream.h>
#include<process.h>
#include<conio.h>
#define max 10
class stack
{
    int item[max],top;
public:
    void create(stack *);
    void push(stack*,int );
    int  pop(stack *);
    void display(stack *p);
    void isempty(stack *);
    void isfull(stack *);
};
void stack::create(stack *p)
{
    p->top=-1;
    cout<<"stack is created ";
}
void stack::push(stack*p,int x)
{
    if(p->top==max-1)
    {
	cout<<"Stavk overflow";
    }
    else
    {
	++p->top;
	p->item[p->top]=x;
    }
}
int stack::pop(stack *p)
{
    if(p->top==-1)
    {
	cout<<"Stack Underflow ";
	return(0);
    }
    else
    {
	return(p->item[p->top--]);
    }
}
void stack::isempty(stack *p)
{
    if(p->top==-1)
    {
	cout<<"Stack is empty";
    }
    else
    {
	cout<<"Stack is not empty";
    }
}
void stack::isfull(stack *p)
{
    if(p->top==max-1)
    {
	cout<<"Stack is full";
    }
    else{
	cout<<"Satck is not full";
    }
}
void stack::display(stack *p)
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
    int ch,n,z;
    stack *p,q,obj;
    p=&q;
    do
    {
        cout<<"\n1:create\n2:push\n3:pop\n4:isempty\n5:isfull\n6:display\n7:exit\n";
        cout<<"Enter your chpice =";
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.create(p);
                break;
            case 2:
		cout<<"Enter any no =";
                cin>>n;
                obj.push(p,n);
                break;
            case 3:
                z=obj.pop(p);
                cout<<"Removed element ="<<z;
                break;
            case 4:
                obj.isempty(p);
                break;
            case 5:
                obj.isfull(p);
                break;
            case 6:
		obj.display(p);
		break;
            case 7:
                exit(0);
        }
    } while(ch!=7);
 getch();   
}