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
	void  inorder(node *);
	void delete_main(int);
	void del_leaf(node *,node*);
	void del_one(node *,node *);
	void del_two(node *);
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
void node::inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		cout<<"\t"<<p->info;
		inorder(p->right);
	}

}
void node::delete_main(int srch)
{
	node *p,*c;
	c=root;
	p=root;
	int t=0;
	while(c!=NULL)
	{
		if(c->info==srch)
		{
			t=1;
			break;
		}
		if(srch<c->info)
		{
			p=c;
			c=c->left;
		}
		else if(srch>c->info)
		{
			p=c;
			c=c->right;
		}
	}
	if(t==1)
	{
		if(c->left==NULL&&c->right==NULL)
		{
			del_leaf(p,c);
		}
		else if(c->left!=NULL&&c->right!=NULL)
		{
			del_two(c);	
		}
		else
		{
			del_one(p,c);
		}
	}
	else
	{
		cout<<"Node is not found ";
	}
}
void node::del_leaf(node *p,node *c)
{
	if(c==p->left)
	{
		p->left=NULL;
	}
	else if(c==p->right)
	{
		p->right=NULL;
	}
	delete(c);
	cout<<"Node is deleted ";
}
void node::del_one(node *p,node *c)
{
	if(c==p->left)
	{
		if(c->left!=NULL)
		{
			p->left=c->left;
		}	
		else
		{
			p->left=c->right;
		}
	}
	else if(c==p->right)
	{
		if(c->right!=NULL)
		{
			p->right=c->right;
		}
		else
		{
			p->right=p->left;
		}
	}
	delete(c);
	cout<<"Node is deleted ";
}
void node::del_two(node *c)
{
	node *p,*lft;
	p=NULL;
	lft=c->left;
	while(lft->right!=NULL)
	{
		p=lft;
		lft=lft->right;
	}
	c->info=p->info;
	if(p==NULL)	
	{
		p=c;
	}
	if(lft->left==NULL&&lft->right==NULL)
	{
		del_leaf(p,lft);
	}
	else
	{
		del_one(p,lft);
	}
}
void main()
{
clrscr();
int  n,ch;
node p;
do
{
	cout<<"\n1:insert\n2:inorder\n3:delete\n4:exit\n";
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
			p.inorder(root);
			break;
		case 3:
			cout<<"Enter node to delete =";
			cin>>n;
			p.delete_main(n);
			break;
		case 4:
			exit(0);
	}
}while(ch!=4);
getch();
}