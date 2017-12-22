#include<iostream>
using namespace std;
void ins(int *a,int n)
{
    int i,temp,val;
    for(i=0;i<n;i++)
    {
        val=a[i];
        temp=i;
        while(temp>0&&a[temp-1]>val)
        {
            a[temp]=a[temp-1];
            temp=temp-1;
        }
        a[temp]=val;
    }
}
int main()
{
    int a[20],i,n;
    cout<<"how many elements ? ";
    cin>>n;
    cout<<"\nenter array ";
    for(i=0;i<n;i++)
        cin>>a[i];
    ins(a,n);
    cout<<"\nsorted array : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
    return 0;
}
