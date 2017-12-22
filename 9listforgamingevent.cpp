using namespace std;

#include<iostream>
#include<conio.h>
#include<stdlib.h>

struct student
{
	char name[30],regNo[10],phNo[10];
	int age;
	student *next;
};

class List
{
	student *node,*first,*newnode;
	public:
		List()
		{
			first = NULL;
		}
		void createList();
		void insertion();
		void deletion();
		void display();
		int verifyAge(int ageC);
};

int List::verifyAge(int ageC)
{
	int cnt = 0;
	student *temp = first;
	while(temp!=NULL)
	{
		if(temp->age ==  ageC)
			cnt++;
		temp = temp->next;
	}
	if(cnt>5)
		return 1;
	else if (cnt>4)
		return 2;
	else
		return 0;
}

void List::createList()
{
	int ch;
	do
	{
		newnode = new student;
		if(first == NULL)
			first = newnode;
		else
			node->next = newnode;
		newnode->next = NULL;
		cout<<"\nEnter the list details: ";
		cout<<"\nName: ";

		cin.getline(newnode->name,30,'\n');
		cout<<"Registration No: ";
		cin.getline(newnode->regNo,10,'\n');
		cout<<"Phone No: ";
		cin.getline(newnode->phNo,10,'\n');
		cout<<"Age: ";
		cin>>newnode->age;
		if (verifyAge(newnode->age) == 1)
		{
			node->next = NULL;
			cout<<"\nInsertion FAILED since maximum number of students with same age cannot exceed 5\n";
			delete newnode;
		}
		else
			node = newnode;
		cout<<"To add another node press '1' : ";
		cin>>ch;
	}while(ch==1);
}

void List::insertion()
{
	int pos;
	cout<<"Enter the position where the record must be inserted: ";
	cin>>pos;
	newnode = new student;
	//node->next = newnode;
	newnode->next = NULL;
	//node = newnode;
	cout<<"\nEnter the details: ";
	cout<<"\nName: ";
	cin.getline(newnode->name,30,'\n');
	cout<<"Registration No: ";
	cin.getline(newnode->regNo,10,'\n');
	cout<<"Phone No: ";
	cin.getline(newnode->phNo,10,'\n');
	cout<<"Age: ";
	cin>>newnode->age;
	if (verifyAge(newnode->age))
	{
		cout<<"\nInsertion FAILED since maximum number of students with same age cannot exceed 5\n";
		delete newnode;
	}
	else
	{
		int i=0;
		student *temp = first;
		while(i<pos-2 && temp!=NULL)
		{
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

void List::deletion()
{
	int pos,i=0;
	cout<<"Enter the position where the record must be deleted: ";
	cin>>pos;
	student *temp = first,*tempTwo;
	while(i<pos-2 && temp!=NULL)
	{
		temp = temp->next;
		i++;
	}
	tempTwo = temp->next;
	temp->next = (temp->next)->next;
	delete tempTwo;
}

void List::display()
{
	student *temp = first;
	while(temp!=NULL)
	{
		cout<<"\nStudent Name: "<<temp->name;
		cout<<"\nRegistration No: "<<temp->regNo;
		cout<<"\nPhone Number: "<<temp->phNo;
		cout<<"\nAge: "<<temp->age<<'\n';
		temp = temp->next;
	}
}

int main()
{
	List listOne;
	listOne.createList();
	for(;;)
	{
		cout<<"\nPress:\n1-To insert a list record\n2-To delete a list record\n3-To display the lists\n4-To Exit\nYour Choice: ";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:
				listOne.insertion();
				break;
			case 2:
				listOne.deletion();
				break;
			case 3:
				listOne.display();
				break;
			case 4:
				exit(1);
				break;
			default:
				cout<<"\nPlease enter a valid choice";
		}
	}
	getch();
}
