#include<iostream>
#include<string.h>
using namespace std;
class student
{
	char name[20];
	char regNo[10];
	char year;
	student *next;
	student *prev;
	public:
		student()
		{
			strcpy(name," ");
			strcpy(regNo," ");
			year=' ';
			next=prev=0;
		}
		void getDetails()
		{
			cout<<"Enter the name of the student \n";
			cin>>name;
			cout<<"\n Enter the register number \n";
            cin>>regNo;
			cout<<"\n Enter the year of student (1/2/3/4) \n";
			cin>>year;
		}
		void printDetails()
		{
			cout<<"Name:"<<name<<endl;
			cout<<"Reg.No.:"<<regNo<<endl;
			cout<<"Year:"<<year<<endl;
		}
		char returnYear()
		{
			return year;
		}
		friend void insertRecord(student *&,student *&);
		friend void displayRecords(student *);
};

void insertRecord(student *& start,student *& rear)
{
	student *node,*newnode;
	if(start==0 && rear==0)
	{
		start=new student;
		start->getDetails();
		start->next=start->prev=0;
		rear=start;
		rear->next=rear->prev=0;
	}
	else
	{
		node=new student;
		node->getDetails();
		node->next=node->prev=0;
		if(node->returnYear()=='1')
		{
			node->prev=rear;
			rear->next=node;
		}
		else
		{
		newnode=start;
		while(newnode->next->returnYear()!='1')
		{
			newnode=newnode->next;
		}
		if(newnode!=rear)
		{
			node->next=newnode->next;
			node->prev=newnode;
			newnode->next->prev=node;
			newnode->next=node;
		}
		else
		{
			node->prev=rear;
			rear->next=node;
			rear->prev=node->prev;
		}
	}
}
}

void displayRecords(student *start)
{
	int i;
	student *node;
	node=start;
	for(i=0;i<10 && node!=0;i++)
	{
		node->printDetails();
		cout<<"\n";
		node=node->next;
	}
}
int main()
{
	char ch;
	int choice;
	student *start,*rear;
	start=rear=0;
	do{
		cout<<"Enter 1 to insert a new record and 2 to display the list of admitted students \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				insertRecord(start,rear);
				break;
			case 2:
				displayRecords(start);
				break;
			default:
				cout<<"Invalid choice! \n";
				
		}
		cout<<"Enter n to exit and any other key to continue \n";
		cin>>ch;
	}while(ch!='n' && ch!='N');
	return 0;
}
