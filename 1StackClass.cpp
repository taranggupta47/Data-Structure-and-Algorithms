using namespace std;



#include<iostream>

#include<conio.h>
#include<stdio.h>





#define MAX_SIZE 100



class Stack

{

      int a[MAX_SIZE];

      int n;

      int top;

public:

       Stack()

       {

              top=-1;

              n=0;

       }

       int isStackEmpty()

       {

           if(top==-1)

                      return 1;

           else

                      return 0;

       }

       int isStackFull()

       {

           if(top==MAX_SIZE-1)

                              return 1;

           else

                              return 0;

       }

       void push(int item)

       {

            if(isStackFull())

                           cout<<"\nOVERFLOW! Can't Push Item!";

            else

            {

                top++;

                a[top]=item;

                n++;

            }

       }

       void pop()

       {

            if(isStackEmpty())

                            cout<<"\nUNDERFLOW! Stack Is Empty!";

            else

            {

                cout<<"\nThe Element Being Popped Is: "<<a[top];

                top--;

                n--;

            }

       }

       void display()

       {

            int i;

            if(isStackEmpty())

                              cout<<"\nStack Is Empty!";

            else

            {

                for(i=0;i<n;i++)

                {

                                cout<<a[i]<<"\t";

                }

            }

       }

};



int main()

{

    char ch;

    int choice,item;

    Stack s;

    do

    {

          

          cout<<"MENU--";

          cout<<"\n\n1. Push An Item To Stack.";

          cout<<"\n2. Pop An Item From Stack.";

          cout<<"\n3. Check If Stack Is Empty.";

          cout<<"\n4. Check If Stack Is Full.";

          cout<<"\n5. View Stack Contents.";

          cout<<"\n\nWhat Do You Want To Do? :";

          cin>>choice;

          switch(choice)

          {

                        case 1: cout<<"\n\nPlease Enter The Number To Be Pushed: ";

                                cin>>item;

                                s.push(item);

                                break;

                        case 2: s.pop();

                                break;

                        case 3: item=s.isStackEmpty();

                                if(item)

                                        cout<<"\n\nStack Is Empty.";

                                else

                                        cout<<"\n\nStack Is NOT Empty.";

                                break;

                        case 4: item=s.isStackFull();

                                if(item)

                                        cout<<"\n\nStack Is Full.";

                                else

                                        cout<<"\n\nStack Is NOT Full.";

                                break;

                        case 5: s.display();

                                break;

                        default:cout<<"\n\nINVALID CHOICE!";

          }

          cout<<"\n\nWould You Like To Perform Another Operation?[Y/N]: ";

          cin>>ch;

    }while(ch!='n' && ch!='N');

    getch();

    return 0;                              

}

