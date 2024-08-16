#include<iostream.h>
#include<conio.h>
#include<process.h>
class node
{
 public:
  int info;
  node *left,*right;
  void insert(int);
  void search(int);
  int count_Node(node*);
  int  count_Leaf(node*);
  void preorder(node*);
  void inorder(node*);
  node* create();
  void max(node*);
  void min(node*);
  void postorder(node*);
  void del_Leaf(node*,node*);
  void del_one(node*,node*);
  void del_two(node*);
  void del_main(int);
}*root;
node* node::create()
{
  node *z;
  z=new node;
  return z;
}
void node::insert(int n)
{
  node *p;
  node *q=create();
	q->info=n;
	q->left=NULL;
	q->right=NULL;
  if(root==NULL)
  {
    root=q;
  }
  else
  {
   p=root;
    while(p!=NULL)
    {
       if(q->info<p->info)
       {
	 if(p->left==NULL)
	 {
	   p->left=q;
	   break;
	 }
	 else
	 {
	   p=p->left;
	 }
       }
       else if(q->info>p->info)
       {
	 if(p->right==NULL)
	 {
	   p->right=q;
	   break;
	 }
	 else
	 {
	   p=p->right;
	 }
       }

       else
       {
	 cout<<"\nDo not Repeat The Node";
	 break;
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
void node::search(int srch)
{
  int t=0;
  node *p=root;
  while(p!=NULL)
  {
    if(p->info==srch)
    {
      t=1;
      break;
    }
    else if(srch<p->info)
    {
      p=p->left;
    }
    else if(srch>p->info)
    {
     p=p->right;
    }
  }
  if(t==1)
    cout<<"\nNode if Found";
  else
    cout<<"\nNode is NOT Found";
}
int node::count_Node(node *p)
{
  if(p==NULL)
    return 0;
  else if(p->left==NULL && p->right==NULL)
    return 1;
  else
    return count_Node(p->left)+count_Node(p->right)+1;
}
int node::count_Leaf(node *p)
{
  if(p==NULL)
   return 0;
  else if(p->left==NULL&&p->right==NULL)
   return 1;
  else
    return count_Leaf(p->left)+count_Leaf(p->right);
}
void node::max(node *p)
{
  while(p->right!=NULL)
  {
    p=p->right;
  }
  cout<<"\nMax Element: "<<p->info;
}
void node::min(node *p)
{
  while(p->left!=NULL)
  {
    p=p->left;
  }
  cout<<"\nMin Element: "<<p->info;
}
void node::del_Leaf(node *parent,node *child)
{
  if(parent->left==child)
  {
    parent->left=NULL;
  }
  else
  {
    parent->right=NULL;
  }
  delete(child);
}
void node::del_one(node *parent,node *child)
{
  if(parent->left==child)
  {
    if(child->right!=NULL)
    {
      parent->left=child->right;
    }
    else
    {
      parent->left=child->left;
    }
  }
  else if(parent->right==child)
  {
    if(child->right!=NULL)
    {
      parent->right=child->right;
    }
    else
    {
     parent->right=child->left;
    }
  }
 delete(child);
}
void node::del_two(node *child)
{
  node *parent=root;
  node *lft=child->left;
  while(lft->right!=NULL)
  {
    parent=lft;
    lft=lft->left;
  }
  if(parent==root)
  {
    parent=child;
  }
  parent->info=lft->info;
  if(lft->left==NULL && lft->right==NULL)
  {
    del_Leaf(parent,lft);
  }
  else
  {
    del_one(parent,lft);
  }
}
void node::del_main(int n)
{
  int cnt=0;
  node *c=root,*p=root;
  while(p!=NULL)
  {
     if(p->info==n)
     {
       cnt=1;
       break;
     }
     else if(p->info<n)
     {
       c=p;
       p=p->right;
     }
     else if(p->info>n)
     {
       c=p;
      p=p->left;
     }
  }
  if(cnt==1)
  {
    if(p->left==NULL && p->right==NULL)
    {
      del_Leaf(c,p);
    }
    else if(p->left!=NULL && p->right!=NULL)
    {
     del_two(p);
    }
    else
    {
      del_one(c,p);
    }
  }
  else
  {
   cout<<"\nNode Not Found";
  }
}
void main()
{
  int n,ch;
  node k;
  clrscr();
  do
  {
    cout<<"\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Count_Node\n7.Count_Leaf\n8.Exit\n9.Max\n10.Min\n11.Delete";
    cout<<"\nEnter Your Choic:";
    cin>>ch;
    switch(ch)
    {
      case 1:
	   cout<<"\nEnter The No: " ;
	   cin>>n;
	   k.insert(n);
	   break;
      case 2:
	   k.preorder(root);
	   break;
      case 3:
	   k.inorder(root);
	   break;
      case 4:
	   k.postorder(root);
	   break;
      case 5:
	   cout<<"\nEnter The Search element: ";
	   cin>>n;
	   k.search(n);
	   break;
      case 6:
	   n=k.count_Node(root);
	   cout<<"\nTotal Nodes: "<<n;
	   break;
      case 7:
	   n=k.count_Leaf(root);
	   cout<<"\nTotal Leaves: "<<n;
	   break;

      case 9:
	   k.max(root);
	   break;
      case 10:
	   k.min(root);
	   break;
      case 11:
	   cout<<"\nEnter The Node To Delete: " ;
	   cin>>n;
	   k.del_main(n);
	   break;
      case 8:
	   exit(5);

    }
  }while(ch!=8);
  getch();
}