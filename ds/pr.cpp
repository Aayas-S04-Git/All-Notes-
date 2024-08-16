#include<string.h>
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
int   i=0,j=0;
char ch,infix[10],pre[10];
stack    *p,*q,pp,qq,obj;
p=&pp;
q=&qq;
obj.create();
cout<<"Enter infix string =";
cin>>infix;
strrev(infix);
while(infix[i]=='\0')
{
	if(infix[i]==')'||infixpi[i]=='+'||infix[i]=='*'||infixpi[i]=='/'||infix[i]=='^'||infixpi[i]=='%'||infix[i]=='$'||infixpi[i]=='-')
	{
		obj.push(infix[i],p);
	}
	else if(p->item[p->top]=='(')
	{
		while(p->top!=-1)
		{
			ch=obj.pop(p);
			if(ch!=')')
			{
				obj.push(ch,q);
			}
		}
	}
	else
	{
		obj.push(infix[i],q);
	}
	i++;
}
if(p->top==-1)
{
	while(p->top!=-1)
	{
		ch=obj.pop(p);
		if(ch!=')')
		{
			obj.push(ch,q);
		}
	}
}
while(q->top==-1)
{
	ch=obj.pop(q);
	pre[j]=ch;
	j++;	
}
pre[j]='\0';
cout<<"Prefix string  ="<<prefix;
getch();
}