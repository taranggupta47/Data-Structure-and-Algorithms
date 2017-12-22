#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
 int a[20],n,ch,l,u,mid,i,flag=0,pos;
 cout<<"\nenter size of array";
    cin>>n;
    cout<<"\nenter the array in ascending order ";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"\nenter the element to be searched ";
    cin>>ch;
    l=0;
    u=n-1;
   while(l<=u)
   {
      mid=(l+u)/2;
      if(ch>a[mid])
      l=mid+1;
      else if(ch<a[mid])
      u=mid-1;
      else
      {
          pos=mid;
          flag=1;
          break;
      }
   }
   if(flag==1)
   cout<<"\nelement found at position "<<pos+1;
   else
   cout<<"\nelement not found ";
   getch();
   return 0;
}





