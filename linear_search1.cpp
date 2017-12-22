#include<iostream>
using namespace std;
#include<conio.h>
void linear_search()
{
     int a[30],i,x,n,f=0;
     cout<<"enter the size:";
     cin>>n;
     cout<<"enter elements:\t";
     for(i=0;i<n;i++)
     cin>>a[i];
     cout<<"\nenter the element to be searched:\t";
     cin>>x;
     for(i=0;i<n;i++)
     {
                     if(x==a[i])
                     {
                                cout<<"element found\n";
                                cout<<"position of the element is\t"<<i+1;
                               f=1;
                                }
                                if(f=0)
                                cout<<"number not found:";
                                }
}                                

main()
{
 linear_search();
 getch();
 return 0;
}
