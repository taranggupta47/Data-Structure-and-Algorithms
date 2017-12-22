#include<iostream>
using namespace std;
int partition(int *a,int start,int end)
{
    int i,temp;
    int pivot=a[end];
    int pindex=start;
    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            temp=a[i];
            a[i]=a[pindex];
            a[pindex]=temp;
            pindex++;
        }
    }
    temp=a[pindex];
    a[pindex]=a[end];
    a[end]=temp;
    return pindex;
}

void quicksort(int *a,int start,int end)
{
    if(start<end)
    {
        int p=partition(a,start,end);
        quicksort(a,start,p-1);
        quicksort(a,p+1,end);
    }
}
int main()
{
    int i,n;
    int a[20];
    cout<<"\nenter number  of elements ";
    cin>>n;
    cout<<"\nenter the array ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"\n Sorted array :";
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<"  ";
    return 0;
}
