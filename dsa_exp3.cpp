#include<iostream>
#define max 100
using namespace std;
class list
{   
public:
    int n;
	int a[max];
	list()
	{
		cout<<"Enter the number of elements in the list \n";
		cin>>n;
	}
	
		void input()
		{
			int i;
			for(i=0;i<n;i++)
			{
			 cin>>a[i];	
			}
			
		}
		void insert(int x,int pos)
		{
			int i;
			for(i=n;i>=pos-1;i--)
			{
				a[i+1]=a[i];
			}
			a[pos-1]=x;
			n++;
		}
		int del(int pos)
		{
			int i;
			for(i=pos;i<=n-1;i++)
			{
				a[i-1]=a[i];
			}
		return a[pos-1];
			n--;
		}
		void search(int x)
		{
			int i,loc,flag=0;
			for(i=0;i<=n;i++)
			{
				if(a[i]==x)
				{
					loc=i;
					flag=1;
					break;
				}
			}
				if(flag==1)
				cout<<"Element found at position:"<<loc+1<<endl;
				else
				cout<<"Element not found \n";
			
		}
        void traverse()
        {
        	int i;
        	for(i=0;i<n;i++)
        	{
        		cout<<a[i];
        		cout<<"\n";
        	}
        }
    
};

int main()
{
	list l;
	int c=1,ch,num,p,d;
	cout<<"Enter elements in the list \n";
	l.input();
	while(c!=0)
	{
		cout<<"Enter 1 to insert,2 to delete,3 to search and 4 to traverse \n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter element to insert \n";
				cin>>num;
				cout<<"Enter position where to insert \n";
				cin>>p;
				l.insert(num,p);
				break;
			case 2:
				cout<<"Enter position to delete \n";
				cin>>p;
				d=l.del(p);
				cout<<"Element deleted:"<<d<<endl;
				break;
			case 3:
				cout<<"Enter the element to be searched \n";
				cin>>num;
				l.search(num);
				break;
			case 4:
				l.traverse();
				break;
			default: 
			cout<<"Wrong choice!";
		}
		cout<<"Enter 0 to exit and any other key to continue \n";
		cin>>c;
	}
	return 0;
}
