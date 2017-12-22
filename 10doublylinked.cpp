#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
struct node
{
    char name[20],p[20],r[20];
    struct node *next;
    struct node *prev;
}*start;
 
class list
{
    public:
        void create_list(char *,char *,char *);
        void add_begin(char *,char *,char *);
        void delete_element(char *);
        void display_dlist();
        
        list()
        {
            start = NULL;  
        }
};
 

int main()
{
	char name[20],r[20],p[20];
	int choice, element, position;
    list dl;
    while (1)
    {       
        cout<<"1.First Year"<<endl;
        cout<<"2.Second Year"<<endl;
        cout<<"3.Delete"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the Name,Reg no. and Phone no.: ";
            cin>>name>>r>>p;
            dl.create_list(name,r,p);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the Name,Reg no. and Phone no.: ";
            cin>>name>>r>>p;
            dl.add_begin(name,r,p);
            cout<<endl;
            break;
        
        case 3:
            if (start == NULL)
            {                      
                cout<<"List empty,nothing to delete"<<endl;   
                break;
            }
            cout<<"Enter the Name for deletion: ";
            cin>>name;
            dl.delete_element(name);
            cout<<endl;
            break;
        case 4:
            dl.display_dlist();
            cout<<endl;
            break;
        case 5:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
 

void list::create_list(char n1[],char p1[],char r1[])//basically adds element after the first start
{
    struct node *s, *temp;
    temp = new(struct node); 
    strcpy(temp->name , n1);
    strcpy(temp->p , p1);
    strcpy(temp->r , r1);
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 

void list::add_begin(char n1[],char p1[],char r1[])//adds elements previous to the first start
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    strcpy(temp->name , n1);
    strcpy(temp->p , p1);
    strcpy(temp->r , r1);
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
 

void list::delete_element(char value[])
{
    struct node *tmp, *q;
     
    if (strcmp(start->name, value)==0)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
       
        if (strcmp(q->next->name , value)==0)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    
    if (strcmp(q->next->name , value)==0)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}
 
void list::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The students is :"<<endl;
    while (q != NULL)
    {
        cout<<"Name:\t"<<q->name<<endl;
        cout<<"Roll no:\t"<<q->r<<endl;
        cout<<"Phone Number:\t"<<q->p<<endl;
        cout<<endl;
		q = q->next;
    }}
 

