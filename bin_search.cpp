#include<iostream>
#include<conio.h>
using namespace std;
int a[20],n;
void inp()
{
     cout<<"Enter size:\n";
     cin>>n;
     cout<<"Enter elements:\n";
     for(int i=0;i<n;i++)
     cin>>a[i];
     }
void binary(int s)
{
int lo=0,hi=n-1,mid=(lo+hi)/2,f=0;
while(lo<=hi)
{  mid=(lo+hi)/2;
if(a[mid]<s)
lo=mid+1;
if(a[mid]>s)
hi=mid-1;
else if(a[mid]==s)
{cout<<"Number found\n";f=1;break;}
}
if(f==0)
cout<<"Number not found\n";
}
int main()
{
    int se;
    inp();
    cout<<"Enter number to be searched:\n";
    cin>>se;
    binary(se);
    
    getch();
    return 0;
}
