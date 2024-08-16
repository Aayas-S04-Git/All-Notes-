#include<iostream.h>
#include<conio.h>
#include<process.h>
class edge
{

}
class node
{
     int info;
     node *next;
     edge *edge;
public:
     void ins_vertex(int );
     void ins_edges(int ,int );
     void search_vertex(int);
     void display();
     void dis_adj(int );
     void dis_graph();
}*start;
void node::ins_vertex(int x)
{
     node *p,*temp;
     p=start;
     p=new node;
     p->next=NULL;
     p->info=x;
     p_>adj=NULL;
     if(p==NULL)
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
   if(p!=NULL)
   {
    if(srch==p->info)
    {
      a=1;
      break;
    }
   }
   if(q!=NULL)
   {
      if(srch==q->info)
      {
	 b=1;
	 break;
      }
   }
   if(a==1||b==1)
   {
       edge *e,*t;
       e=new edge;
       e->dest=de;
       e->right=NULL;
       if(p->dest==NULL)
       {
	   p->adj=e;
       }
       else
       {
	   t=p->adj;
	   while(t->right!=NULL)
	   {
	      t=t->right;
	   }
	   t->right=e;
       }
   }
   else
   {
      cout<<"Vertices are invalid ";
   }
}
