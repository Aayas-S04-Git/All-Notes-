#include<string.h>
#include<iostream.h>
#include<conio.h>
#define max 100
class stack
{
public:
     int item[max],top;
public:
    void create(stack *);
    int  pop(stack *);
    void push(stack* ,int );
};
void stack::create(stack *p)
{
    p->top=-1;
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
    int i=0,j=0;
    char ch,pre[100],infix[100];
    stack *oper,*operand,q,t,obj;
    operand=&q;
    oper=&t;
    obj.create(oper);
    obj.create(operand);
    cout<<"Enter infix string =";
    cin>>infix;
    strrev(infix);
    cout<<"Reverse string ="<<infix;
    while(infix[i]!='\0')
    {
	if(infix[i]==')'||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^'||infix[i]=='%'||infix[i]=='$')
	{
	    obj.push(oper,infix[i]);
	}
	else  if(infix[i]=='(')
	{
	    while(oper->item[oper->top]!=-1)
	    {
		ch=obj.pop(oper);
		if(ch!='(')
		{
		    obj.push(operand,ch);
		}
	    }
	}
	else
	{
	    obj.push(operand,infix[i]);
	}
	i++;
    }
    if (oper->top!=-1)
    {
	 while(oper->top!=-1)
	 {
	    ch=obj.pop(oper);
	    if(ch!=')')
	    {
		obj.push(operand,ch);
	    }
	 }
    }
    while(operand->item[operand->top]!=-1)
    {
	pre[j]=obj.pop(operand);
	j++;
    }
    pre[j]='\0';
    cout<<"Prefix string ="<<pre;
    getch();
}