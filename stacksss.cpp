
#include<iostream>
#include<conio.h>
using namespace std;
template<class T>
class Stack 
{

private:
   int MAX;
   int top;
   T* items;

public:
	Stack(){
		MAX =10;
		top = -1;
		items = new T[MAX];
	}

	~Stack(){ delete [] items; }

	void push(T c){
		if(full()){
			cout << "Stack Full!" << endl;
			exit(1);
		}

		items[++top] = c;
	}

	T pop(){
		if(empty()){
			cout << "Stack Empty!" << endl;
			exit(1);
		}

		return items[top--];
	}

	int empty(){ return top == -1; }

	int full(){ return top+1 == MAX; }
	void display()
	{
		cout<<"Stack as follows:\n";
		for(int i=top;i>=0;i--)
		cout<<items[i]<<endl;}
};
int main()
{
Stack <char> ob;
ob.push('c');
ob.push('a');
ob.push(6);
ob.push('v');
ob.display();
char p1=ob.pop();
ob.display();
getch();
return 0;
}

