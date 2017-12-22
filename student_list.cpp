#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<string.h>
using namespace std;
struct node
{
    int rno,age;char name[20],phno[10];
    struct node *next;
}*start;
class list
{
    public:
        node* create_node(char *,char *,int,int);
        void insert_start();
        void insert_pos();
        void insert_last(); 
        void delete_pos();
        void display();
        void search();
       list() 
        {
            start = NULL;
        }
};
int main()
{
    int ch, pos, i,nodes, element;
    list sl;
    start = NULL;
    while (1)
    {
        cout<<"1.Insert Student Details at beginning"<<endl;
        cout<<"2.Insert Student Details at last"<<endl;
        cout<<"3.Insert Student Details at position"<<endl;
        cout<<"4.Delete a Particular Student's details"<<endl;
        cout<<"5.Display Linked List"<<endl;
        cout<<"6.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Inserting Node at Beginning: "<<endl;
            sl.insert_start();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting Node at Last: "<<endl;
            sl.insert_last();
            cout<<endl;
            break;
        case 3:
            cout<<"Inserting Node at a given position:"<<endl;
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            cout<<"Delete a particular node: "<<endl;
            sl.delete_pos();
            break;
        case 5:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;
            break;
        case 6:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Invalid"<<endl;
        }
    }
}

node *list::create_node(char n[],char p[],int r,int a)
{
    struct node *temp, *s;
    temp = new node; 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        strcpy(temp->name , n);
        strcpy(temp->phno , p);
        temp->rno = r;
        temp->age = a;
        temp->next = NULL;     
        return temp;
    }
}
 

void list::insert_start()
{
    int r,a;char n[20],p1[10];
    cout<<"Enter name,roll no,age and phone number:\n ";
    cin>>n>>r>>a>>p1;
    struct node *temp, *p;
    temp = create_node(n,p1,r,a);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;          
    } 
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    cout<<"Element Inserted at beginning"<<endl;
}
 

void list::insert_last()
{
    int r,a;char n[20],p[10];
    cout<<"Enter name,roll no,age and phone number: ";
    cin>>n>>r>>a>>p;
   struct node *temp, *s;
    temp = create_node(n,p,r,a);
    s = start;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    temp->next = NULL;
    s->next = temp;
    cout<<"Element Inserted at last"<<endl;  
}

void list::insert_pos()
{
    int pos, counter = 0; 
    int r,a;char n[20],p[10];
    cout<<"Enter name,roll no,age and phone number: ";
    cin>>n>>r>>a>>p;
   
    struct node *temp, *s, *ptr;
    temp = create_node(n,p,r,a);
    cout<<"Enter the postion at which node to be inserted: ";
    cin>>pos;
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        cout<<"No such pos"<<endl;
    }
}
 


void list::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the position of value to be deleted: ";
    cin>>pos;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;  
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            cout<<"Position out of range"<<endl;
        }
        free(s);
        cout<<"Element Deleted"<<endl;
    }
}
 

void list::display()
{
    struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Students as follows: "<<endl;
    while (temp != NULL)
    {
        cout<<"Name->"<<temp->name<<endl;
        cout<<"Roll no.->"<<temp->rno<<endl;
        cout<<"Age->"<<temp->age<<endl;
        cout<<"Phone Number->"<<temp->phno<<endl;
        cout<<endl;
        temp = temp->next;
    }
}



