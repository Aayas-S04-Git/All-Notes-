#include<iostream.h>
#include<conio.h>
int adj[10][10];
void main()
{
    clrscr();
    int n,edge,de,sc,i,j;
    cout<<"Enter number of vertices =";
    cin>>n;
    cout<<"Enter number of edges =";
    cin>>edge;
    for(i=1;i<=edge;i++)
    {
        cout<<"\nEnter "<<i<<" No of source vertex =";
        cin>>sc;
        cout<<"|nEnter "<<i<<" No of destination vertex =";
        cin>>de;
        if(sc<=0||de<=0||de>n||sc>n)
        {
            cout<<"Invalid edge";
            i--;
        }
        else
        {
	    adj[sc][de]=1;
        }
    }
    cout<<"\nAdjacency matrix for directed graph =\n";
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