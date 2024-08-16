#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#define max 50

class stack
{
	public:
	int item[max],top;
	void create(stack*);
	void push(stack*,int);
	int pop(stack*);

};

void stack::create(stack *p)
{
	p->top=-1;

}

void stack::push(stack *p,int n)
{
	if(p->top==max)
	  cout<<"\nStack is overFlow";
	else
	{
	 ++p->top;
	 p->item[p->top]=n;
	}
}

int stack::pop(stack *p)
{
	if(p->top==-1)
	{
	  cout<<"\nStack is UnderFlow";
	  return 0;
	}
	else
	  return p->item[p->top--];
}

void main()
{
	int i=0,j=0;
	char infix[50],prefix[50],ch;
	clrscr();
	stack *oprnd,*oprtr,p,q,k;
	oprnd=&q;
	oprtr=&p;
	k.create(oprnd);
	k.create(oprtr);
	cout<<"\nEnter The Expression: ";
	gets(infix);
	strrev(infix);
	while(infix[i]!='\0')
	{
	  if(infix[i]==')' || infix[i]=='+' || infix[i]=='-'||infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
	  {
	    k.push(oprtr,infix[i]);
	  }
	  else if(infix[i]=='(')
	  {
	    while(oprtr->top!=-1)
	    {
	    ch=k.pop(oprtr);
	    if(ch!=')')
	    {
	     k.push(oprnd,ch);
	    }
	    }
	  }
	  else
	  {
	  k.push(oprnd,infix[i]);
	  }
	  i++;
	}
	if(oprtr->top!=-1)
	{
	while(oprtr->top!=-1)
	{
	ch=k.pop(oprtr);
	if(ch!=')')
	{
	 k.push(oprnd,ch);
	}
	}
	}
	while(oprnd->top!=-1)
	{
	 ch=k.pop(oprnd);
	 prefix[j]=ch;
	 j++;
	}
	prefix[j]='\0';
	cout<<"\nPrefix Expression: "<<prefix;
  getch();
} //(A+B) * (C-D) ) / E
