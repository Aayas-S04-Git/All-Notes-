#include<iostream.h>
#include<conio.h>
int adj[10][10];
int visited[20];
void bfs(int );
int n,edge;
#define true 1
#define false 2
void main()
{
    clrscr();
int n,edges,v,sc,de,i,j;
    cout<<"Enter no of vertex =";
    cin>>n;
    cout<<"Enter no of edges ";
    cin>>edges;
    for(i=1;i<=edges;i++)
    {
        cout<<"Enter "<<i<<" source vertex =";
        cin>>sc;
        cout<<"Enter "<<i<<" destintion vertex =";
        cin>>de;
        if(sc>n||de>n||sc<=0||de<=0)
        {
            cout<<"Invalid edge";
            i--;
        }
        else
        {
            adj[sc][de]=1;
        }
    }
    cout<<"ENter vertex to traverse =";
    cin>>v;
    bfs(v);
    getch();   
}
void bfs(int v)
{
    int queue[10],front,rear,i;
    rear=front=-1;
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