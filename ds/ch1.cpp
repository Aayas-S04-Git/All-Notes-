#include<conio.h>
#include<iostream.h>
#define max 10
class stack 
{
	int  item[max],top;
public:
	void create(stack *);
	void push(stack *,int );
	void pop(stack *);
};
void stack::create(stack *p)
{
	p->top=-1;
}
void stack::push(stack *p,int x)
{
	if(p->top==max-1)
	{
		cout<<"Stack Overflow ";
	}
	else
	{
		++p->top;
		p->item[p->top]=x;
	}
}
int stack ::pop(stack *p)
{
	if(p->top==-1)
	{
		cout<<"Stack is Underflow ";
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
char exp[10];
int no1,no2,i=0,ans;
stack *p,q,obj;
p=&q;
obj.create(p);
cout<<"Enter any postfix string =";
cin>>exp;
while(exp[i]!='\0')
{
	if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='^'||exp[i]=='%'||exp[i]=='/')
	{
			
	}
}
getch();
}