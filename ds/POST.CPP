#include<string.h>
#include<conio.h>
#include<iostream.h>
#define max 10
class stack 
{
public:
    int item[max],top;
    void create(stack *);
    void push(stack *,int );
    int pop(stack *);
};
void stack::create(stack *p)
{
    p->top=-1;
}
void stack::push(stack *p,int x)
{
    if(p->top==max-1)
    {
        cout<<"Stack overflow";
    }
    else
    {
        ++p->top;
        p->item[p->top]=x;
    }
}
int stack::pop(stack *p)
{
    if (p->top==-1)
    {
        cout<<"Stack is Underflow";
        return(0);
    }
    else
    {
        return(p->item[p->top--]);
    }
    
}
void main()
{
	clrscr();
    char infix[100],post[100],ch;
    int i=0,j=0;
    stack *p,*q,pp,qq,obj;
    p=&pp;
    q=&qq;
    obj.create(p);
    obj.create(q);
    cout<<"Enter any infix string =";
    cin>>infix;
    strrev(infix);
    while (infix[i]=='\0')
    {
	if(infix[i]==')'||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^'||infix[i]=='%'||infix[i]=='$')
	{
	    obj.push(p,infix[i]);
	}
	else if(infix[i]=='(')
	{
	    while (p->top!=-1)
	    {
		ch=obj.pop(p);
		if (ch!=')')
		{
		    obj.push(q,ch);
		}
	    }

	}
	else
	{
	    obj.push(q,infix[i]);
	}
	i++;
    }
    if(p->top!=-1)
    {
	while (p->top!=-1)
	{
	    ch=obj.pop(p);
	    if (ch!=')')
	    {
		obj.push(q,ch);
	    }

	}

    }
    while(q->top!=-1)
    {
	post[j]=obj.pop(q);
	j++;
    }
    post[j]='\0';
    cout<<"postfix string ="<<post;
    getch();
}