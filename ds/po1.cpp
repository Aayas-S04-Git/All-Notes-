#include<iostream.h>
#include<conio.h>
#define max 10
class stack
{
	int item[max],top;
public:
	void create(stack *);
	void push(stack *);
	int  pop(stack *);
};
void stack::create(stack *p)
{
	p->top=-1;
}
void satck::push(int  n,stack *p)
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
int stack::pop(stack  p)
{
	if(p->top==-1)
	{
		cout<<"Stack is Underflow ":
		return(0);
	}
	else
	{
		rturn(p->item[p->top--]);
	}
}
void main()
{
clrscr();
char ch,infix[10],post[10];
int   i=0,j=0;
stack   *p,q,obj;
	p->create();
	cout<<"Enter infix string =";
	cin>>infix;
	while(infix!='\0')
	{
		if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^'||infix[i]=='%'||infix[i]=='(')
		{
			p->item[p->top]=infix[i];
		}
		else     if(infix[i]==')')
		{
			while(p->item[p->top]!='(')
			{
				ch=obj.pop(p);
				if(ch!='(')
				{
					post[j]=ch;
				}
				j++;
		}
		else
		{
			post[j]=infix[i];
			j++;
		}
		i++;
	}
	if(p->top!=-1)
	{
		while(p->top!=-1)
		{
			c=obj.pop(p);
			if(ch!='(')
			{
				post[j]=ch;
				j++;
			}
		}
	}
	post[j]='\0';
	cout<<"postfix string ="<<post;
	getch();
}