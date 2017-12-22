#include<iostream>
#include<conio.h>
using namespace std;//USING NAMESPACE STD;
const int MAX=5;
struct data
		  {
		   int p,o;char val[20];
		  }d[MAX];

	class pqueue
	{
		  int front,rear;
		public:
		  pqueue()
		 {
			front=rear=-1;
		 }
		 void insert(data d1);
		 void deletion();
		 void display();
	};
	void pqueue :: insert(data d1)
	{
		if(rear==MAX-1)
		   cout<<"Priority Queue is Full";
		else
		{
		   rear++;
		   d[rear]=d1;
		   if(front==-1)
			  front=0;
		   data temp;
		   for(int i=front;i<=rear;i++)
			 for(int j=i+1;j<=rear;j++)
			 {
				 if(d[i].p < d[j].p)
				 {
					temp=d[i];
					d[i]=d[j];
					d[j]=temp;
				 }
				 else
				 {
					 if(d[i].p==d[j].p)
					 {
						 if(d[i].o > d[j].o)
						 {
							  temp=d[i];
							  d[i]=d[j];
							  d[j]=temp;
						 }
					 }
				 }
			 }
		}
	}
	void pqueue :: deletion()
	{
		data d1;
		if(front==-1)
		   cout<<"Priority Queue is Empty";
		else
		{
		   d1=d[front];
		   if(front==rear)
			  front=rear=-1;
		   else
			  front++;
		}
		cout<<d1.val<<endl;
	}
	void pqueue :: display()
	{
		 if(front==-1)
			 cout<<"Priority Queue is Empty";
		 else
		 {
			for(int i=front;i<=rear;i++)
			{
				cout<<"Person Number :"<<i+1<<endl;
				cout<<endl;
				cout<<"Name = "<<d[i].val<<endl;
				cout<<"Age = "<<d[i].p<<endl;
				cout<<"Order = "<<d[i].o<<endl;
				cout<<endl;
			}
		 }
	}
	int main()
	{
	  pqueue p1;

	  data d1;
	  char op;
	  do
	  {
		int ch;

		//clrscr();
		cout<<"----------Menu-------------\n";
		cout<<"1.Insertion 2.Deletion 3.Display 4.Exit\n";
		cout<<"Enter your Choice<1..4> ?\n";
		cin>>ch;
		switch(ch)
		{
		   case 1 :  cout<<"Enter Name ?\n";
					 cin>>d1.val;
					 cout<<"Enter age?\n";
					 cin>>d1.p;
					 cout<<"Enter Order ?\n";
					 cin>>d1.o;
					 p1.insert(d1);
					 break;
		   case 2 :  p1.deletion();
					 
					 break;
		   case 3 :  p1.display();
					 break;
		  }
		  cout<<"Do You Want to Continue <Y/N> ?\n";
		  cin>>op;
		}while(op=='Y' || op=='y');
		getch();
	  return 0;
	  }







