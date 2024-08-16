#include<iostream.h>
#include<conio.h>
#define true 1
#define false 0
int adj[10][10],visited[20],n,edge;
void bfs(int );
void main()
{
	clrscr();
	int sc,de,i,v;
	cout<<"Vertex=";
	cin>>n;
	cout<<"edges =";
	cin>>edge;
	for(i=1;i<=edge;i++)
	{
		cout<<i<<" source=";
		cin>>sc;
		cout<<i<<" destination =";
		cin>>de;
		if(sc>n||de>n||sc<=0||de<=0)
		{
			cout<<"Invalid ";
			i--;
		}
		else
		{
			adj[sc][de]=1;
		}
	}
	cout<<"Enter vertex =";
	cin>>v;
	bfs(v);
	getch();
}
void bfs(int v)
{
	int i,queue[10],front,rear;
	front=rear=-1;
	++rear;
	queue[rear]=v;
	while(rear!=front)
	{
		++front;
		v=queue[front];
		if(visited[v]==false)
		{
		   cout<<"\t"<<v;
		   visited[v]=true;
		   for(i=1;i<=n;i++)
		   {
		      if(visited[i]==false&&adj[v][i]==1)
		      {
			++rear;
			queue[rear]=i;
		      }
		   }
		}
	}
}