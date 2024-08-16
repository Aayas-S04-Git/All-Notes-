#include<conio.h>
#include<iostream.h>
#include<process.h>
class edge
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
    void insert_edge(int ,int);
    void insert_vertex(int );
    void search_vertex(int );
    void display_vertex();
    void display_graph();
    void display_adj(int );

}*start;
void node::insert_vertex(int v)
{
    node *p,*q;
    p=start;
    p=new node;
    p->info=v;
    p->next=NULL;
    p->adj=NULL;
    if(start==NULL)
    {
        start=p;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
void node::insert_edge(int sc,int de)
{
    node *p,*q;
    p=q=start;
    int a=0,b=0;
    while(p!=NULL)
    {
	if(p->info==sc)
	{
	    a=1;
	    break;
	}
	p=p->next;
    }
    while(q!=NULL)
    {
	if(q->info==de)
	{
	    b=1;
	    break;
	}
	q=q->next;
    }
    if(a==1&&b==1)
    {
	edge *r,*z;
        z=new edge;
        r->dest=de;
        r->right=NULL;
        if(p->adj==NULL)
        {
            p->adj=z;
        }
        else
        {
            r=p->adj;
            while (r->right!=NULL)
            {
                r=r->right;
            }
            r->right=z;
        }
    }
    else
    {
	cout<<"Vertex is not found ";
    }
}
void node::display_vertex()
{
    node *p;
    p=start;
    while(p!=NULL)
    {
        cout<<"\n"<<p->info;
        p=p->next;
    }
}
void node::display_graph()
{
    node *p;
    edge *q;
    p=start;
    while (p!=NULL)
    {
	cout<<"\n"<<p->info;
        q=p->adj;
        while(q!=NULL)
        {
            cout<<"->"<<q->dest;
            q=q->right;
        }
        p=p->next;
    }   
}
void node::display_adj(int srch)
{
    node *p;
    edge *q;
    p=start;
    int t=0;
    while(p!=NULL)
    {
	if(p->info==srch)
        {
            t=1;
            break;
        }
        p=p->next;
    }
    if(t==1)
    {
        q=p->adj;
        while (q!=NULL)
        {
            cout<<"\t"<<q->dest;
            q=q->right;
        }
        
    }
    else{
        cout<<"Node is not found ";
    }
}
void node::search_vertex(int srch)
{
    node *p;
    int t;
    p=start;
    while(p!=NULL)
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
        cout<<"Node is found ";
    }
    else{
        cout<<"Node is not found ";
    }
}
void main()
{
    clrscr();
    int n,srch,sc,ch,de;
    node obj;
    do
    {
	cout<<"\n1:insert vertex\n2:insert edge\n3:display vertex \n4:display \n5:display adj\n6:serch vertex \n7:exit\n";
	cout<<"Enter your choice =";
	cin>>ch;
	switch(ch)
	{
            case 1:
                cout<<"Enter any no =";
                cin>>n;
                obj.insert_vertex(n);
                break;
            case 2:
                cout<<"Enter source vertex =";
                cin>>sc;
                cout<<"Enter destination vertex =";
                cin>>de;
                obj.insert_edge(sc,de);
                break;
            case 3:
                obj.display_vertex();
                break;;
            case 4:
                obj.display_graph();
                break;
            case 5:
                cout<<"Enter source vertex =";
                cin>>srch;
                obj.display_adj(srch);
                break;
            case 6:
                cout<<"Enter source vertex =";
                cin>>srch;
                obj.search_vertex(srch);
                break;
            case 7:
                exit(0);
        }
    } while(ch!=7);
    getch();    
}