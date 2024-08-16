#include<iostream.h>
#include<conio.h>
#include<process.h>
class 
{
public:
int dest;
edge *right;
};
class node
{
    int info;
    node *next;
    edge *adj;
public:
      void insert_vertex(int );
      void insert_edge(int ,int);
      void search_vertex(int );
      void display_vertex();
      void display_graph();
      void display_adjcent(int );
}*start;
void node::insert_vertex(int x)
{
    node *p,*q;
    p=new node;
    p->next=NULL;
    p->adj=NULL;
    p->info=x;
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        q=start;
        while (q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
        
    }
}
void node::display_vertex()
{
    node *p;
    p=start;
    while (p!=NULL)
    {
        /* code */
        cout<<"\n"<<p->info;
        p=p->next;
    }
    
}
void node::insert_edge(int sc,int de )
{
    node *p,*q;
    p=q=start;
    edge *r;
    int a=0,b=0;
    while(p!=NULL)
    {
        if(sc==p->info)
        {
            a=1;
            break;
        }
        p=p->next;
    }
    while (q!=NULL)
    {
        if(de==p->info)
        {
            b=1;
            break;
        }
        p=p->next;
    }
    if(a==1&&b==1)
    {
        r=new edge;
        r->right=NULL;
        r->dest=de;
        if(p->adj==NULL)
        {
            p->adj=r;
        }
        else
        {
             edge *z;
             z=p->adj;
             while(z->right!=NULL)
             {
                  z=z->right;
             }
             z->right=r;
        }
    }
    else
    {
          cout<<"Edge is invalid ";
    }
}
void node::display_graph()
{
        node *p;
        edge *r;
        p=start;
        while(p!=NULL)
        {
            cout<<"\n"<<p->info;
            r=p->adj;
            while(r!=NULL)
            {
                 cout<<"-->"<<r->dest;
                 r=r->right;
            }
            p=p->next;
        }
}
void node::search_vertex(int srch)
{
     node *p;
     p=start;
     while (p!=NULL)
     {
        if(srch==p->info)
        {
            t=1;
            break;
        }
        p=p->next;
     }
     if(t==1)
     {
        cout<<"vertex is found ";
     }
     else 
     {
        cout<<"Vertex is not found ";
     }
     
}
void node::display_adjcent(int srch)
{
       node *p;
       p=start;
       int t=0;
       whiel(p!=NULL)
       {
            if(srch==p->info)
            {
                t=1;
                break;
            }
       }
       if(t==1)
       {
               edge *z;
               z=p->adj;
               while(z->right)
               {
                   cout<<"-->"<<z->dest; 
                   z=z->right;
               }
       }
       else{
        cout<<"vertex has no adjecacent vertex ";
       }
}
void main()
{
       clrscr();
       int ch,z,z,sc,de;
       node obj;
       do
       {
                cout<<"1:insert vertex \n2:insert edge\n3:display vertex \n5:display graph\n6:display adjacacent vertex 7:search\n8:exit\n"
                cout<"Enter your choice =";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                    
                }
       } while (ch!=);            
}