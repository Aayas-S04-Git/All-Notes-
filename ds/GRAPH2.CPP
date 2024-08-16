#include<iostream.h>
#include<conio.h>
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
    void ins_vertex(int );
    void ins_edge(int ,int );
    void dis_vertex();
    void dis_graph();
    void search_vertex(int );
    void find_adj(int );
}*start;
void node::ins_vertex(int x)
{
       node *p,*temp;
       p=start;
       p=new node;
       p->next=NULL;
       p->info=x;
       p->adj=NULL;
       if(start==NULL)
       {
	    start=p;
       }
       else
       {
	    temp=start;
	    while(temp->next!=NULL)
	    {
		 temp=temp->next;
	    }
	    temp->next=p;
       }
}
void node::ins_edge(int sc,int de)
{
    node *p,*q;
    p=q=start;
    int a=0,b=0;
    while(p->next!=NULL)
    {
	if(sc==p->info)
	{
	    a=1;
	    break;
	}
	p=p->next;
    }
    while (q->next!=NULL)
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
        edge *z,*r;
        z=new edge;
        z->dest=de;
        z->right=NULL;
        if(p->adj==NULL)
        {
            p->adj=z;
        }
        else
        {
            r=p->adj;
            while(r->right!=NULL)
            {
                r=r->right;
            }
            r->right=z;
        }
    }
    else
    {
        cout<<"Invalid edge";
    }
}
void node::dis_vertex()
{
    node *p;
    p=start;
    while(p->next!=NULL)
    {
        cout<<"\t"<<p->info;
        p=p->next;
    }
}
void node::dis_graph()
{
    node *p;
    edge *z;
    p=start;
    while(p->next!=NULL)
    {
        cout<<"\n"<<p->info;
        z=p->adj;
        while(z->right!=NULL)
        {
            cout<<"->"<<z->dest;
            z=z->right;
        }
        p=p->next;
    }
}
void node::search_vertex(int srch)
{
    node *p;
    p=start;
    int t=0;
    while(p->next!=NULL)
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
        cout<<"Vertex is found ";
    }
    else
    {
        cout<<"Vertex is not found ";
    }
}
void node::find_adj(int x)
{
    node *p;
    p=start;
    int t=0;
    while(p->next!=NULL)
    {
        if(p->info==x)
        {
            t=1;
            break;
        }
        p=p->next;
    }
    if(t==1)
    {
	edge *z;
	z=p->adj;
	while (z->right!=NULL)
	{
	    cout<<"\t"<<z->dest;
	    z=z->right;
	}
    }
    else{
        cout<<"Vertex is not found ";
    }
}
void main()
{
    clrscr();
    int v,sc,de,ch,srch;
    node obj;
    do
    {
	cout<<"\n1:insert vertex\n2:insert edge\n3:display vertex\n4:display graph\n5:search veratx\n6:find adjcent vertex=\n7:Exit\n";
        cout<<"Enter your choice =";
        cin>>ch;
        switch (ch)
        {
	case 1:
	    cout<<"Enter vertex name =";
	    cin>>v;
	    obj.ins_vertex(v);
	    break;
	case 2:
	    cout<<"Enter source vertex =";
	    cin>>sc;
	    cout<<"Enter destination vertex =";
	    cin>>de;
	    obj.ins_edge(sc,de);
	    break;
	case 3:
	    obj.dis_vertex();
	    break;
	case 4:
            obj.dis_graph();
            break;
        case 5:
            cout<<"Enter vertex to search=";
            cin>>srch;
            obj.search_vertex(srch);
            break;
        case 6:
            cout<<"Enter vertex=";
            cin>>v;
            obj.find_adj(v);
            break;
	case 7:
            exit(0);        
        default:
            cout<<"wrong input";
        }
    } while (ch!=7);
    
}