#include<iostream>
#include<string.h>
#include<conio.h>
#define MAX_SIZE 100
using namespace std;
class Patient
{
	char name[50];
	int age;
	public:
		Patient()
		{
			strcpy(name," ");
			age=0;
		}
		void getData()
		{
			cout<<"Enter patient's name \n";
			cin>>name;
			cout<<"Enter age of patient \n";
			cin>>age;
		}
		void displayData()
		{
			cout<<"Name:";
			puts(name);
			cout<<"\n";
			cout<<"Age:"<<age<<endl;
		}
		int returnAge()
		{
			return age;
		}
};
class PatientQueue
{
	Patient p[MAX_SIZE];
	int front,rear;
	public:
		PatientQueue()
		{
			front=0;
			rear=-1;
		}
		int isQueueFull()
		{
			if(rear==MAX_SIZE-1)
			return 1;
			else
			return 0;
		}
		int isQueueEmpty()
		{
			if(rear<front)
			return 1;
			else
			return 0;
		}
		void enqueue()
		{
			if(isQueueFull())
			cout<<"Queue is full! \n";
			else
			{
				p[++rear].getData();
				sortQueue();
			}
		}
		void dequeue()
		{
			if(isQueueEmpty())
			cout<<"Queue is empty \n";
			else
			{
				p[front].displayData();
				front++;
			}
		}
		void displayQueue()
		{
			int i;
			for(i=front;i<=rear;i++)
			{
			    p[i].displayData();
				cout<<"\n";
			}
		}
		void sortQueue()
		{
			int maxPos,i,j;
			Patient pDummy;
			for(i=front;i<=rear;i++)
			{
				maxPos=i;
				for(j=i+1;j<=rear;j++)
				{
					if(p[j].returnAge()>p[maxPos].returnAge())
					{
						maxPos=j;
					}
				}
				pDummy=p[maxPos];
				p[maxPos]=p[i];
				p[i]=pDummy;
			}
		}
};

int main()
{
	char ch='y';
	int choice;
	PatientQueue q;
	do{
		cout<<"Enter 1 to enqueue,2 to dequeue and 3 to display \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				q.enqueue();
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.displayQueue();
				break;
			default:
				cout<<"Invalid choice! \n";
		}
		cout<<"Enter n to exit and any other key to continue \n";
		cin>>ch;
	}while(ch!='n' || ch!='n');
	return 0;
}
