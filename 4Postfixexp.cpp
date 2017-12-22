#include<stdio.h>
#include<iostream>
using namespace std;
#include<math.h>
int arr[5]={1,2,3,4,5};
template<class x>class stack
{
	public:
		x arr[20];
		int top;
		stack()
		{
			top=-1;
		}
		
		void push(x a)
		{
			arr[++top]=a;
		}
		
		x pop()
		{
			return arr[top--];
		}
};
class node
{
	public:
		char ch;
		node* left;
		node* right;
		node(char gh)
		{
			ch=gh;
			left=right=NULL;
		}
		
};

int evaluate(node* rt)
{
	if(rt->left==NULL)
	{
		if(rt->ch>=65&&rt->ch<=90)
		{
			return arr[rt->ch-65];
		}
		else
		  return rt->ch-48;
	}
	
	else
	{
		int a=evaluate(rt->left);
		int b=evaluate(rt->right);
		switch(rt->ch)
		{
			case '+': return a+b;
			case '-': return a-b;
			case '*': return a*b;
			case '/': return a/b;
			case '^': return (int)pow(a,b);
		}
	}
}

void print(node* rt)
{
	if(rt!=NULL)
	{
		print(rt->left);
		print(rt->right);
		cout<<rt->ch;
	}
}


main()
{
	cout<<"enter postfix expression::";
	char t[20];
	fflush(stdin);
	cin>>t;
	
	stack<node*> s1;
	for(int i=0;t[i]!='\0';++i)
	{
		if((t[i]>=65&&t[i]<=90)||(t[i]>=48&&t[i]<=57))
		s1.push(new node(t[i]));
		else
		 {
		 	node* temp=new node(t[i]);
		 	temp->right=s1.pop();
		 	temp->left=s1.pop();
		 	s1.push(temp);
		 }
		
	}
	
	node* start=s1.pop();
	
	print(start);
	cout<<"\n";
	int jo=evaluate(start);
	
	cout<<jo;
	
	
	
}
