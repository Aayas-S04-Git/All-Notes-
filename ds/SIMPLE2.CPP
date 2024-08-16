#include<conio.h>
#include<iostream.h>
void main()
{
      int i,j,k,a[100],n;
      clrscr();
      cout<<"Entre how many number you want to insert =";
      cin>>n;
      cout<<"Enter "<<n<<" Number =";
      for(i=0;i<=n-1;i++)
      {
	  cin>>a[i];
      }
      for(j=0;j<=n-1;j++)
      {
	for(i=j+1;i<=n-1;i++)
	{
	     if(a[i]<=a[j])
	     {
		  k=a[i];
		  a[i]=a[j];
		  a[j]=k;
	     }
	}
      }
      cout<<"Sorted array=\n";
      for(i=0;i<=n-1;i++)
      {
		cout<<"\t"<<a[i];
      }
      getch();
}
