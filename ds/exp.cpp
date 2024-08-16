#include<iostream.h>
#include<conio.h>
#define mx 10
class stack 
{
	int item[max],top;
public:
	void create(stck *p);
	void push(int ,stack *p);
	int pop(stack *);
};
void stack::create(int x,stack *p)
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
void main()
{
clrscr();
int ch,exp[10];
stack *p,q,obj;
p=&q;
int i=0,t=0;
obj.create(p);
cout<<"Enter any expression =";
cin>>exp;
while(exp[i]=='\0')
{
	if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
	{
		obj.push(exp[i],p);	
	}
	else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
	{
		ch=obj.pop(p);
		if((ch=='(')!=(exp[i]==')')||(ch=='{')!=(exp[i]=='}')||(ch=='[')!=(exp[i]==']'))
		{
			t=1;
		}
	}
	i++;
}
if(t==1||p->top==-1)
{
	cout<<"Expression is invalide ";
}
else
{
	cout<<"Expression is valide ";
}
getch();
}