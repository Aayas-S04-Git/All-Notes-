#include<iostream.h>
#include<conio.h>
int adj[10][10];
void main()
{
    clrscr();
    int i,j,n,edges,sc,de,wt;
    cout<<"Enter no of vertices =";
    cin>>n;
    cout<<"Enter no of edges=";
    cin>>edges;
    for(i=1;i<=edges;i++)
    {
	cout<<"Enter "<<i<<" source vertex =";
	cin>>sc;
	cout<<"Enter "<<i<<" destination vertex=";
	cin>>de;
	cout<<"Enter weight of"<<i<<" edge";
	cin>>wt;
	if(sc<0||de<0||sc>n||de>n)
	{
	    cout<<"Enter valid edges";
	    i--;
	}
	else
	{
	    adj[sc][de]=wt;
	}
    }
    cout<<"Adjacency of weighjted=\n";
    for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	{
	  cout<<"\t"<<adj[i][j];
	}
	cout<<"\n";
    }
    getch();
}