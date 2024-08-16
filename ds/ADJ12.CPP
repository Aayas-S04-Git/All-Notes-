#include<iostream.h>
#include<conio.h>
int adj[10][10];
void main()
{
     clrscr();
     int n,edge,sc,de,i,j;
     cout<<"Enter no of vertices =";
     cin>>n;
     cout<<"Enter no of edges=";
     cin>>edge;
     for(i=1;i<=n;i++)
     {
	cout<<"Enter "<<i<<" source vertex=";
	cin>>sc;
	cout<<"Enter "<<i<<" Destination vertex =";
	cin>>de;
	if(sc>n||de>n||sc<=0||de<=0)
	{
		cout<<"Invalid edge";
		i--;
	}
	else
	{
	     adj[i][j]=1;
	}
     }
     for(i=1;i<=n;i++)
     {
	 for(j=1;j<=n;j++)
	 {
	     cout<<"   "<<adj[i][j];
	 }
	 cout<<"\n";
     }
     getch();
}