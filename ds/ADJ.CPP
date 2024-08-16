#include<iostream.h>
#include<conio.h>
int adj[10][10];
void main()
{
   clrscr();
   int n,i,j,edges,sc,de;
   cout<<"Enter no of vertex =";
   cin>>n;
   cout<<"Enter no of edges =";
   cin>>edges;
   for(i=1;i<=edges;i++)
   {
	cout<<"Enter "<<i<<" source vertex=";
	cin>>sc;
	cout<<"Enter "<<i<<" destination vertex =";
	cin>>de;
	if(sc<0||de<0||sc>n||de>n)
	{
	     cout<<"Enter valid edge";
	     i--;
	}
	else
	{
	    adj[sc][de]=1;
	    adj[de][sc]=1;
	}
   }
   cout<<"Adjacency matrix =\n";
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