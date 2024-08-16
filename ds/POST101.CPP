#include<conio.h>
#include<process.h>
#include<iostream.h>
#define max 20
class stack
{
public:
    int item[max],top;
    void create(stack *);
    void push(stack *,int);
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
    char post[20],in[20],ch;
    int i=0,j=0;
    stack *p,q,obj;
    p=&q;
    obj.create(p);
    cin>>in;
    while (in[i]!='\0')
    {
        if(in[i]=='('||in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='$'||in[i]=='^'||in[i]=='%')
        {
            obj.push(p,in[i]);
        }
        else if(in[i]==')')
        {
            while (p->item[p->top]!='(')
            {
                ch=obj.pop(p);
                if(ch!='(')
                {
                    post[j]=ch;
                    j++;
                }
	    }
	    obj.pop(p);
        }
        else
        {
            post[j]=in[i];
            j++;
        }
        i++;
    }
    if (p->top!=-1)
    {
       while (p->top!=-1)
       {
            ch=obj.pop(p);
            if(ch!='(')
            {
                post[j]=ch;
                j++;
            }
       }
    }
    post[j]='\0';
    cout<<"Postfix expression ="<<post;
    getch();
}