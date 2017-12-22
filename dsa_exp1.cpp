#include<iostream>
#include<ctype.h>
#define max 100
using namespace std;
class stack
{
	int top;
	int a[max];
	public:
		stack()
		{
			top=-1;
		}
		void push(int x)
		{   
		    if(isStackFull())
		    cout<<"Stack full!";
		    else
			{
			top++;
			a[top]=x;
		    }
		}
		int pop()
		{
			if(isStackEmpty())
			return -1;
			else
			{
			int k=a[top];
			top--;
			return k;
		    }
		
		}
		int isStackEmpty()
		{
			if(top<0)
			return 1;
			else
			return 0;
		}
		int isStackFull()
		{
			if(top==max-1)
			return 1;
			else
			return 0;
		}
		void display()
		{
			for(int i=0;i<=top;i++)
			{
				cout<<a[i];
				cout<<"\n";
			}
		}
};

int main()
{
	stack st;
	int ch,n;
	int c=1,p;
	while(c!=0)
	{
	cout<<"Enter 1 to insert,2 to delete and 3 to display\n";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter element to insert \n";
		cin>>n;
		st.push(n);
		break;
		case 2: p=st.pop();
		if(p==-1)
		cout<<"Stack empty! \n";
		else
		cout<<"Element deleted:"<<p<<endl;
		break;
		case 3: st.display();
		break;
		default: cout<<"Wrong choice!";
	}
	cout<<"Enter 0 to exit and any other key to continue \n";
	cin>>c;
    }
	
	return 0;
}
