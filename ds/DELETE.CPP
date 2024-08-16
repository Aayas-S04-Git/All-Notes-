#include<iostream.h>
#include<conio.h>
#include<process.h>
class node
{
    int info;
    node *left,*right;
public:
    node* create();
    void insert(int);
    void del_one(node *,node *);
    void del_two(node *);
    void del_leaf(node *,node *);
    void del_main(int );
    void inorder(node *);
}*root;
node* node::create()
{
    node *z;
    z=new node;
    return(z);
}
void node::inorder(node *p)
{
    if(p!=NULL){
	inorder(p->left);
	cout<<"\t"<<p->info;
	inorder(p->right);
    }
}
void node ::insert(int x)
{
    node *p,*q;
    p=create();
    p->left=NULL;
    p->right=NULL;
    p->info=x;
    if(root==NULL)
    {
	root=p;
    }
    else{
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
void node ::del_leaf(node *p,node *c)
{
    if(c==p->left)
    {
	p->left=NULL;
    }
    else if(c==p->right)
    {
	p->right=NULL;
    }
    delete (c);
}
void node ::del_one(node *p,node *c)
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
	    p->right=c->left;
	}
    }
    delete(c);
}
void node ::del_two(node *c)
{
    node *p,*lft;
    p=NULL;
    lft=c->left;
    while(lft->right!=NULL)
    {
	p=lft;
	lft=lft->right;
    }
    if(p==NULL)
    {
	p=c;
    }
    c->info=lft->info;
    if(lft->left==NULL&&lft->right==NULL)
    {
	del_leaf(p,lft);
    }
    else
    {
	del_one(p,lft);
    }
}
void node::del_main(int srch)
{
    node *p,*c;
    p=c=root;
    int t=0;
    while (c!=NULL)
    {
	if(srch==c->info)
	{
	    t=1;
	    break;
	}
	else if(srch>c->info)
	{
	    p=c;
	    c=c->right;
	}
	else if(srch<c->info)
	{
	    p=c;
	    c=c->left;
	}
    }
    if(t==1)
    {
	if(c->left==NULL&&c->right==NULL)
        {
            del_leaf(p,c);
        }
        else if(p->left!=NULL&&p->right!=NULL)
        {
            del_two(c);
        }
        else
        {
	    del_one(p,c);
        }
    }
    else{
	cout<<"Node is not found ";
    }
    
}
void main()
{
    clrscr();
    int ch,n,z;
    node obj;
    do
    {
	cout<<"\n1:insert\n2:inorder\n3:delete\n4:";
        cout<<"Enter any no =";
        cin>>ch;
	switch(ch)
	{
	    case 1:
		    cout<<"Enter any no =";
		    cin>>n;
		    obj.insert(n);
		    break;
	    case 2:
		obj.inorder(root);
		break;
	    case 3:
		cout<<"Enter node to delete=";
		cin>>n;
		obj.del_main(n);
		break;
            case 4:
                exit(0);
        }
    } while (ch!=4);
    getch();
}