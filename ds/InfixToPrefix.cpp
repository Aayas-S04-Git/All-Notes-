#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 50

class stack
{
public:
	int item[max],top;
	void create(stack*);
	void push(stack*,int);
	int pop(stack*); 
}

void stack::create(stack *p)
{
	 p->top=-1;
}

void stack::push(stack *p,int n)
{
	if(p->top==max-1)
		cout<<"\nStack is Overflow";
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
	 	cout<<"\nStack is Underflow";
	 	return 0;
	 }
	 else
	 	return p->stack[p->top--];
}

void main()
{
	 char infix[50],prefix[50];
	 int i=0,j=0;
	 stack *p,k,q;
	 p=&q;
	 cout<<"\nEnter The Infix String: ";
	 gets(infix);
	 while(infix[i]!='\0')
	 {
	 	if(infix[i]=='(' || infix[i]=='+' || infix[i]=='-')
	 		k.push(p,infix[i]);
	 	else if(infix[i]==')')
	 	{
	 		ch=k.pop(p);
	 		if(ch!='(')
	 		{
	 			prefix[j]=ch;
	 			j++;
	 		}
	 	}
	 	else
	 	{
	 		prefix[j]=infix[i];
	 		j++;
	 	}
	 }
	 if(p->top!=-1)
	 {
	 	while(p->top!=-1)
	 	{
	 		ch=k.pop(p);
	 		if(ch!='(')
	 		{
	 			pre[j]=ch;
	 			j++;
	 		}
	 	}
	 }
	 prefix[j]='\0';
	 cout<<"Prefix Expression: "<<prefix;
	getch();

}