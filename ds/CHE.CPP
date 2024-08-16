#include<iostream.h>
#include<conio.h>
#define max 10
class stack
{
public:
    int item[max],top;
public:
    void create(stack *);
    void push(stack*,int );
    int  pop(stack *);
};
void stack::create(stack *p)
{
    p->top=-1;
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
void main()
{
    clrscr();
    char exp[10],ch;
    int t=0,i=0;
    cout<<"Enter any expression =";
    cin>>exp;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    while(exp[i]!='\0')
    {
	if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
	{
	    obj.push(p,exp[i]);
	}
	else if(exp[i]==')'||exp[i]==']'||exp[i]=='}')
	{
	    ch=obj.pop(p);
	    if((ch=='(')!=(exp[i]==')')||(ch=='[')!=(exp[i]==']')||(ch=='{')!=(exp[i]=='}'))
	    {
		t=1;
		break;
	    }
	}
	i++;
    }
    if(p->top!=-1||t==1)
    {
	cout<<"Expression is Invalid ";
    }
    else
    {
	cout<<"Expression is valid ";
    }
    getch();
}