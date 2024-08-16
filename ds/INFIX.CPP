#include<iostream.h>
#include<conio.h>
#define max 100
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
	  cout<<"Stack Overflow";
      }
      else
      {
	   ++p->top;
	   p->item[p->top]=x;
      }
}
int  stack::pop(stack *p)
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
    int i,j;
    char infix[100],post[100],ch;
    stack *p,q,obj;
    p=&q;
    obj.create(p);    //creating stack
    cout<<"Enter any infix expression=";
    cin>>infix;
    while(infix[i]!='\0')
    {
	 if(infix[i]=='('||infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='^'||infix[i]=='%'||infix[i]=='/'||infix[i]=='$'||infix[i]=='#')
	 {
	     obj.push(p,infix[i]);
	 }
	 else if(infix[i]==')')
	 {
	      while(p->item[p->top]!='(')
	      {
		  ch=obj.pop(p);
		  if(ch=='(')
		  {
		     post[j]=ch;
		     j++;
		  }
	      }
	      obj.pop(p);
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
	     ch=obj.pop(p);
	     if(ch=='(')
	     {
		post[j]=ch;
		j++;
	     }
       }
    }
    post[j]='\0';     //manual end of string
    cout<<"\npostfix string ="<<post;
    getch();
}