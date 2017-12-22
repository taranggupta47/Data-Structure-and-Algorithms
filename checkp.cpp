#include<string.h>
#include<iostream>
#include<conio.h>
using namespace std;
class Stack 
{

public:
   int MAX;
   int top;
   char items[100];


	Stack(){
		MAX =10;
		top = -1;
		
	}
	void push(char c){
		if(full()){
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	char pop(){
		if(empty()){
			cout << "Stack Empty!" << endl;
			exit(1);
		}

		return items[top--];
	}

	int empty(){ return top == -1; }

	int full(){ return top+1 == MAX; }
};
int main()
{
	
	int balance=0,size;char ch='\0';
	char a[10];
	Stack ob;
	cout<<"Enter the expression\n";
cin>>a;
size=strlen(a);
	for(int i=0;i<size;i++)
	{
		ch='\0';
		//cout<<a[i]<<endl;
		switch(a[i])
		{
		case '{':ob.push(a[i]);break;	
		case '[':ob.push(a[i]);break;
		case '(':ob.push(a[i]);break;
		case '}':
			ch=ob.pop();
			if(ch=='{'&&balance==0)
			balance=0;
			else 
			balance++;
			break;
		case ']': ch=ob.pop();
			if(ch=='['&&balance==0)
			balance=0;
			else 
			balance++;
			break;
		case ')': ch=ob.pop();
			if(ch=='('&&balance==0)
			balance=0;
			else 
			balance++;
			break;
			default:
			cout<<"Wrong i/p";
		}
		
	}
	if(balance==0&&ob.empty()==1)
	cout<<"Valid\n";
	else
	cout<<"Invalid\n";
	getch();
	return 0;
}
