#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{
    int n,arr[100],i,j,k;
    clrscr();
    cout<<"Enter how many element you want to sort=";
    cin>>n;
    cout<<"Enter "<<n<<" numbers=";
    for(i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    for (j=0;j<=n-1;j++)
    {
        for(i=j+1;i<=n-1;i++)
        {
            if(arr[i]<arr[j])
            {
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
        }
    }
    cout<<"Sorted array=\n";
    for ( i = 0; i <=n-1; i++)
    {
	cout<<"\t"<<arr[i];
    }
    getch();
}