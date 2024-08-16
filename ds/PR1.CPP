#include<conio.h>
#include<iostream.h>
#include<string.h>
#define max 20
class stack
{
public:
    int item[max],top;
public:
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
        cout<<"Stack Overflow ";
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
    int i=0,j=0;
    char pre[20],in[20],ch;
    stack *op,*opernd,q,qq,obj;
    op=&q;
    opernd=&qq;
    obj.create(op);
    obj.create(opernd);
    cout<<"Enter any infix string :";
    cin>>in;
    strrev(in);
    while (in[i]!='\0')
    {
        if(in[i]==')'||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/')
        {
            obj.push(op,in[i]);
        }
        else if(in[i]=='(')
        {
	    while(op->top!=-1)
            {
                ch=obj.pop(op);
                if(ch!=')')
                {
                    obj.push(opernd,ch);
                }
            }
        }
        else
        {
            obj.push(opernd,in[i]);
	}
	i++;
    }

	if(op->top!=-1)
	{
	    while (op->top!=-1)
	    {
		ch=obj.pop(op);
		if(ch!=')')
		{
		    obj.push(opernd,ch);
		}
	    }
	}
	while(opernd->top!=-1)
	{
	    ch=obj.pop(opernd);
	    if(ch!=')')
	    {
		pre[j]=ch;
		j++;
	    }
	}
	pre[j]='\0';
	cout<<"Prefix string ="<<pre;
    getch();
}
