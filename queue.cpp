#include<iostream> 
#include<conio.h>
using namespace std; 
class queue { 
public : int *a,f,r,size; 
queue()
 { f=0; r=-1;
  cout<<"\nEnter size of the Queue\n";
   cin>>size; 
   a = new int [size];
  } int isempty(); 
  int isfull();
   void enqueue(); 
   void dequeue(); 
   void display();
    }; 
	int queue :: isempty() { if(r==-1) return 1;
	else
	 return 0; } 
	int queue :: isfull() { if(r==(size-1)) return 1; return 0; } 
	void queue :: enqueue() 
	{ if(isfull()) 
	{ cout<<"\n Queue Overflow\n";
	  } 
	else { 
	cout<<"\nEnter an Element\n"; 
	r++;
	cin>>a[r];
	cout<<"Inserted successfully\n"; }
	 } 
	 void queue ::dequeue() 
	 { 
	 if(f>r) 
	 { cout<<"\nQueue Underflow\n"; 
	  f=0;r=-1;}
	  else
	{cout<<"Element deleted:\t"<<a[f];
	f++;}

	   }
	    void queue :: display()
	    { if(f>r)
		 { cout<<"\nQueue is empty -- No element to display\n"; 
		  } 
		 else 
		 { for(int i=f;i<=r;i++)
		  cout<<""<<a[i]<<" ";
		   }
		}
		 int main()
		  {
		   int i=0,s; 
		   queue q; 
		   while(i!=1)
		    { cout<<"\n*********M E N U*********\n";
			 cout<<"\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
			  cout<<"Enter option\n"; 
			  cin>>s; 
			  switch(s) 
			  { case 1: q.enqueue(); break; 
			  case 2: q.dequeue(); break; 
			  case 3: q.display(); break; 
			  case 4: i=1; break; 
			  default : cout<<"\nEnter correct option\n"; break; } 
			  } 
			  getch();
			  return 0;
   
   }
