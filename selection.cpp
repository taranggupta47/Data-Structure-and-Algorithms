#include<iostream>
#include<conio.h>
using namespace std;
void sel(int *a,int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
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
    sel(a,n);
    cout<<"\nsorted array : ";
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
    return 0;
    getch();
}
