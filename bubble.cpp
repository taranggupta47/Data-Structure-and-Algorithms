#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
  int a[20],n,i,j,temp;
  cout<<"\nenter size of array";
    cin>>n;
    cout<<"\nenter the array ";
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    {
                    for(j=0;j<n-1-i;j++)
                    {
                                    if(a[j]>a[j+1])
                                    {
                                                   temp=a[j+1];
                                                   a[j+1]=a[j];
                                                   a[j]=temp;
                                    }
                    }
    }
    cout<<"\narray in ascending order is \n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    getch();
    return 0;
}
