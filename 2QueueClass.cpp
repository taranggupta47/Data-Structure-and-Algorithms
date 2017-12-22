#include<iostream>
#define max 100
using namespace std;
class queue
{
	int front;
	int rear;
	int a[max];
	public:
		queue()
		{
			front=0;
			rear=-1;
		}
		void enqueue(int x)
		{
			if(isQueueFull())
			cout<<"Queue full! \n";
			else
			{
				rear++;
				a[rear]=x;
			}
		}
		int dequeue()
		{
			if(isQueueEmpty())
		    return -1;
		    else
		    {
		    	int k=a[front];
		    	front++;
		    	return k;
		    }
			
		}
		int getQueueSize()
		{
			int count=0;
			for(int i=front;i<=rear;i++)
			{
				count++;
			}
			return count;
		}
		int isQueueFull()
		{
			if(rear==max-1)
			return 1;
			else
			return 0;
		}
		int isQueueEmpty()
		{
			if(rear<0)
			return 1;
			else
			return 0;
		}
		void display()
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<a[i];
				cout<<"\n";
			}
		}
		
};

int main()
{
	queue q;
	int ch,n,c=1,p,s;
	while(c!=0)
	{
	cout<<"Enter\n1 to enqueue\n2 to dequeue\n3 to get queue size\n4 to display \n";
	cin>>ch;

		switch(ch)
		{
			case 1:
				cout<<"Enter element to enqueue \n";
				cin>>n;
				q.enqueue(n);
				break;
			case 2:
				p=q.dequeue();
				if(p==-1)
				cout<<"Queue empty! \n";
				else
				cout<<"Element deleted:"<<p<<endl;
				break;
			case 3:
				s=q.getQueueSize();
				cout<<"Queue size:"<<s<<endl;
				break;
			case 4: q.display();
			    break;
			default: cout<<"Wrong choice! \n";
		}
		cout<<"Enter 0 to exit and any other key to continue \n";
		cin>>c;
	}
	return 0;
}
