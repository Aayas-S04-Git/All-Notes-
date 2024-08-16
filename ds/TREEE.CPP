#include<conio.h>
#include<iostream.h>
#include<process.h>
class  node
{
int   info;
node  *left,*right;
public:
	node* create();
	void insert(int );
	void preorder(node *);
	void inorder(node *);
	void postorder(node *);
	void search(int );
	int  leaf_node(node *);
	int  total_node(node *);
}*root;
node* node::create()
{

	node *z;
	z=new node;
	return(z);
}
void   node::insert(int  x)
{
	node *p,*q;
	p=create();
	p->info=x;
	p->left=NULL;
	p->right=NULL;
	if(root==NULL)
	{
		root=p;
	}
	else
	{
		q=root;
	    while(q!=NULL)
	    {
		if(p->info>q->info)
		{
			if(q->right==NULL)
			{
				q->right=p;
				break;
			}
			else
			{
				q=q->right;
			}
		}
		else if(p->info<q->info)
		{
			if(q->left==NULL)
			{
				q->left=p;
				break;
			}
			else
			{
				q=q->left;
			}
		}
	    }
	}
}
void node::preorder(node *p)
{
	if(p!=NULL)
	{
		cout<<"\t"<<p->info;
		preorder(p->left);
		preorder(p->right);
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
void node::postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<"\t"<<p->info;
	}
}
void node::search(int x)
{
	node *p;
	p=root;
	int t=0;
	while(p!=NULL)
	{
		if(x==p->info)
		{
			t=1;
			break;
		}
		else if(x>p->info)
		{
			p=p->right;
		}	
		else if(x<p->info)
		{
			p=p->left;
		}
	}
	if(t==1)
	{
		cout<<"Node is found ";
	}
	else
	{
		cout<<"NOde os not found ";
	}
}
int node::leaf_node(node *p)
{
	if(root==NULL)
	{
		return(0);
	}
	else if(p->left==NULL&&p->right==NULL)
	{
		cout<<"\t"<<p->info;
		return(1);
	}
	else
	{
		return(leaf_node(p->left)+leaf_node(p->right));
	}
}
int  node::total_node(node *p)
{
	if(root==NULL)
	{
		return(0);
	}
	else if(p->left==NULL&&p->right==NULL)
	{
		return(1);
	}
	else
	{
		return(total_node(p->left)+total_node(p->right)+1);
	}
}
void main()
{
	clrscr();
	int n,ch,srch,z;
	node p;
	do
	{
		cout<<"1:insert\n2:preorder\n3:inorder\n4:postorder\n5:search\n6:leaf count \n7:total count \n8:exit\n";
		cout<<"Enter your choice =";
		cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter any no =";
			cin>>n;
			p.insert(n);
			break;
		case 2:
			p.preorder(root);
			break;
		case 3:
			p.inorder(root);
			break;
		case 4:
			p.postorder(root);
			break;
		case 5:
			cout<<"Enter any no =";
			cin>>n;
			p.search(n);
			break;
		case 6:
			p.leaf_node(root);
			break;
		case 7:
			p.total_node(root);
			break;
		case 8:
			exit(0);
	}
	}while(ch!=8);
	getch();

}