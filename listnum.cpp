#include<iostream>
#include<conio.h>
using namespace std;
class list
{
      public:
             int a[20],size;
             void input()
             {
                  cout<<"Enter size of list:\n";
                  cin>>size;
                  cout<<"Enter all nos:\n";
                  for(int i=0;i<size;i++)
                  cin>>a[i];
                  
             }
             void insert(int pos,int val)
             {int i;
             size++;
             for(i=size-1;i>=pos-1;i--)
             {if(i==pos-1)
             a[i]=val;
             else
             a[i]=a[i-1];
              }}
              void disp()
              {
              for(int i=0;i<size;i++)
              cout<<a[i]<<endl;
              }
                            
              void delet(int pos)
              {
                                 for(int i=0;i<size-1;i++)
                                 if(i>=pos-1)
                                 a[i]=a[i+1];
                                 else
                                 {}
                                 size--;
                                 }
                                 void search(int num)
                                 {int f=0;
                                      for(int i=0;i<size;i++)
                                      {if(a[i]==num)
                                      {f=1;
                                      cout<<"Number found in :"<<(i+1)<<endl;
                                      }
                                      }
                                      if(f==0)
                                      cout<<"Number not found\n";
                                      }
                       };
                       int main()
                       {
                           list l;
                           int x,e;
                           l.input();
                           cout<<"\nEnter the position to be inserted ";
                           cin>>x;
                           cout<<"\nEnter the element to be inserted";
                           cin>>e;
                           l.insert(x,e);
                           cout<<"After insertion:\n";
                           l.disp();
                           l.delet(5);
                           cout<<"After deletion:\n";
                           l.disp();
                           l.search(5);
                           getch();
                           return 0;
                           }
                  
             
