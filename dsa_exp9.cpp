#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct student
{
	char name[30];
	char regNo[10];
	int phone;
	int age;
	student *next;
};
class List
{
	student *node,*first,*newnode;
	public:
		List()
		{
			first=NULL;
		}
		void createList();
		void insertion();
		void deletion();
		void display();
		int verifyAge(int ageC);
};

int List::verifyAge(int ageC)
{
	int cnt=0;
	student *temp=first;
	while(temp!=NULL)
	{
		if(temp->age==ageC)
		cnt++;
		temp=temp->next;
	}
	if(cnt>5)
	return 1;
	else if(cnt>4)
	return 2;
	else
	return 0;
	
}

void List::createList()
{
	int ch;
	do
	{
		newnode=new student;
		if(first==NULL)
		first=newnode;
		else
		node->next=newnode;
		newnode->next=NULL;
		cout<<"Enter the list details \n";
		cout<<"\n Name:";
		cin>>newnode->name;
		cout<<"\n Reg. No.:";
		cin>>newnode->regNo;
		cout<<"\n Phone no:";
		cin>>newnode->phone;
		cout<<"\n Age:";
		cin>>newnode->age;
		if(verifyAge(newnode->age)==1)
		{
			node->next=NULL;
			cout<<"Insertion failed since max. number of students with same age cannot exceed 5 \n";
			delete newnode;
		}
		else
		{
			node=newnode;
		}
		cout<<"To add another node press 1 \n";
		cin>>ch;
	}while(ch==1);
}

void List::insertion()
{
	int pos;
	cout<<"Enter the position where the record must be inserted \n";
	cin>>pos;
	newnode=new student;
	//node->next=newnode;
	node->next=NULL;
	//node=newnode;
	cout<<"Enter the details \n";
	cout<<"Name:";
	cin>>newnode->name;
	cout<<"Reg.No.:";
	cin>>newnode->regNo;
	cout<<"Phone no.:";
	cin>>newnode->phone;
	cout<<"Age:";
	cin>>newnode->age;
	if(verifyAge(newnode->age))
	{
		cout<<"Insertion failed since max no. of students with same age can not be more than 5 \n";
		delete newnode;
	}
	else
	{
		int i=0;
		student *temp=first;
		while(i<pos-2 && temp!=NULL)
		{
			temp=temp->next;
			i++;
			
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	}
	void List::deletion()
	{
		int pos,i=0;
		cout<<"Enter the position where the record must be deleted \n";
		cin>>pos;
		student *temp=first;
		student *tempTwo;
		while(i<pos-2 && temp!=NULL)
		{
			temp=temp->next;
			i++;
		}
		tempTwo=temp->next;
		temp->next=(temp->next)->next;
		delete tempTwo;
	}
	void List::display()
	{
		student *temp=first;
		while(temp!=NULL)
		{
			cout<<"Name:"<<temp->name<<endl;
			cout<<"Reg.No."<<temp->regNo<<endl;
			cout<<"Phone no."<<temp->phone<<endl;
			cout<<"Age:"<<temp->age<<endl;
			temp=temp->next;
		}
	}

int main()
{
	List listone;
	listone.createList();
	int ch;
	for(;;)
	{
		cout<<"Enter 1 to insert a list record,2 to delete a record ,3 to display and 4 to exit \n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				listone.insertion();
				break;
			case 2:
				listone.deletion();
				break;
			case 3:
				listone.display();
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"Enter a valid choice \n";
				
		}
	}
	return 0;
}
