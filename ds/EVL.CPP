#include<iostream.h>
#include<conio.h>
#define max 10
class stack
{
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
    int i=0,n1,n2,ans;
    char post[100],ch;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    cout<<"Enter infix expression =";
    cin>>post;
    while(post[i]!='\0')
    {
	if(post[i]=='+'||post[i]=='-'||post[i]=='*'||post[i]=='^'||post[i]=='/')
	{
	    n2=obj.pop(p);
	    n1=obj.pop(p);
	    switch(post[i])
	    {
		case '+':
		    ans=n1+n2;
		    obj.push(p,ans);
		    break;
		case '-':
		    ans=n1-n2;
		    obj.push(p,ans);
		    break;
		case '*':
		    ans=n1*n2;
		    obj.push(p,ans);
		    break;
		case '/':
		    ans=n1/n2;
		    obj.push(p,ans);
		    break;
		case '^':
		    ans=n1*n2;
		    obj.push(p,ans);
		    break;
	    }
	}
        else
        {
	    obj.push(p,post[i]-48);
        }
        i++;
    }
    ans=obj.pop(p);
    cout<<"Answer of postfix string ="<<ans;
    getch();
}