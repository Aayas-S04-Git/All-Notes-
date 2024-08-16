#include<iostream.h>
#include<process.h>
#include<conio.h>
class node 
{
     int info,t;
     node *left,*right;
public:
   void insert(node *,int );
   void check(node *);
   void inorder(node *);
}*root;
void  node::insert(node *p,int x)
{
    node *q;
    p=new node();
    p->left=NULL;
    p->right=NULL;
    p->info=x;
    if(root==NULL)
    {
	root=p;
    }
    else
    {
	q=root;
	while(q!=NULL)
	{
	    if(q->left==NULL)
	    {
		q->left=p;
	    }
	    else if(q->left!=NULL&&q->right!=NULL)
	    {
		if(q->left->left==NULL)
		{
		    insert(q->left,q->info);
		}
		else{

		    insert(q->right,q->info);
		}
	    }
	    {
		q->right=p;
	    }
	}

    }
}
void node::inorder(node *p)
{
	if(p!=NULL)
	{
	     inorder(p->left);
	     cout<<"\t"<<p->info;
	     inorder(p->right);
	}
}
void node::check(node *p)
{
  static t=0;
    if(t!=1)
    {
	if(p->right->info>p->info&&p->left->info<p->info)
	{
	    check(p->left);
	    check(p->right);
	}
	else
	{
	    t=1;
	    cout<<"Invalid suraj code ";
	}
    }
}
void main()
{
    clrscr();
    int n,m,ch;
    node obj;
    do
    {
	cout<<"1:\n2:\n3\n4:\n";
	cout<<"Enter";
	cin>>ch;
	switch (ch)
	{
	case 1:
		cout<<"Enter";
		cin>>n;
		obj.insert(root,n);
            break;
        case 2:
            obj.check(root);
            break;
        case 3:
            obj.inorder(root);
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    } while(ch!=4);
    getch();
}