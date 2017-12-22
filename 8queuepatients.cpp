using namespace std;
#include<iostream>
#include<process.h>
#include<string.h>
#define MAX_SIZE 100
class Patient

{

	char name[100];

	int age;

public:

	Patient()

	{

		strcpy(name,"");

		age=0;

	}

	void getData()

	{

		cout<<"Please enter the patient's name: ";



		cin>>name;

		cout<<"Please enter the patient's age: ";

		cin>>age;

	}

	void displayData()

	{

		cout<<"\nThe name of the patient is: "<<name;

		cout<<"\nThe patient's age is: "<<age;

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

		if(front>rear)

			return 1;

		else

			return 0;

	}

	void Enqueue()

	{

		if(isQueueFull())

			cout<<"\nOVERFLOW! Enqueue NOT Possible.";

		else

		{

			p[++rear].getData();

			sortQueue();

		}

	}

	void Dequeue()

	{

		if(isQueueEmpty())

			cout<<"\nUNDERFLOW! Dequeue NOT Possible.";

		else

		{

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

			maxPos = i;

			for(j=i+1;j<=rear;j++)

			{

				if(p[j].returnAge()>p[maxPos].returnAge())

				{

					maxPos = j;

				}

			}

			pDummy = p[maxPos];

			p[maxPos] = p[i];

			p[i] = pDummy;

		}

	}

};



int main()

{

	char ch;

	int choice;

	PatientQueue q;

	do

	{

		cout<<"MENU--\n\n";

		cout<<"1. Enqueue.\n";

		cout<<"2. Dequeue.\n";

		cout<<"3. View Queue.\n";

		cout<<"4. Exit Program.";

		cout<<"\n\nWhat would you like to do? :";

		cin>>choice;

		switch(choice)

		{

			case 1: q.Enqueue();

					break;

			case 2: q.Dequeue();

					break;

			case 3: q.displayQueue();

					break;

			case 4:

					break;

			default:cout<<"\nINVALID CHOICE!";

		}

		cout<<"\nWould you like to perform another operation?[Y/N] : ";

		cin>>ch;

	}while(ch!='n' && ch!='N');

	return 0;

}



