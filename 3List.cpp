
#include<iostream>

using namespace std;



class list

{

      private:

              int n_terms,i,a[100],pos,temp,ele;   //n_terms is no of terms  i is counter variable  a[100] is the static array



      public:

             void input()

             {

                     cout<<"Enter the number of elements:"<<endl;

                     cin>>n_terms;

                     for(i=0;i<n_terms;i++)

                     {

                                     cout<<"Enter "<<i+1<<"th element:"<<endl;

                                     cin>>a[i];

                     }

             }

             void insert()

             {

                    cout<<"Enter the position of the element to be inserted:"<<endl;

                    cin>>pos;

                    cout<<"Enter the element to be inserted:"<<endl;

                    cin>>ele;

                    for(i=pos-1;i<n_terms+1;i++)

                    {

                     temp=a[i];

                     a[i]=ele;

                     ele=temp;

                    }

                    cout<<"The modified list after insertion is:"<<endl;

                    for(i=0;i<n_terms+1;i++)

                    {

                    cout<<i+1<<"th Element: "<<a[i]<<endl;

                    }

             }

             void delete_ele()

             {

                    cout<<"Enter the position of the element to be deleted:"<<endl;

                    cin>>pos;

                    for(i=pos-1;i<n_terms;i++)

                    {

                    a[i]=a[i+1];

                    }

                    cout<<"The modified list after deletion is:"<<endl;

                    for(i=0;i<n_terms;i++)

                    {

                     cout<<i+1<<"th Element: "<<a[i]<<endl;

                    }

             }

             void search()

             {

                     cout<<"Enter the element to be searched:"<<endl;

                     cin>>ele;

                     pos=0;          //in this function pos is used as a counter variable

                     for(i=0;i<n_terms;i++)

                     {

                      if(a[i]==ele)

                      {

                        pos++;

                        cout<<"Element found!!\nAt position:"<<i+1<<endl;

                      }

                     }

                      if(pos==0)

                        {

                         cout<<"Element not found!!"<<endl;

                        }

             }

             void traverse()

             {

                       cout<<"The final list is:"<<endl;

                       for(i=0;i<n_terms;i++)

                       {

                         cout<<i+1<<"th element: "<<a[i]<<endl;

                       }

             }

};

int main()

{

    int choice,choice2;

    list A1;

    A1.input();

    do

    {

    cout<<"Press\n 1 for insert\n 2 for delete\n 3 for search\n 4 for traverse"<<endl;

    cin>>choice;

    switch(choice)

    {

                  case 1:A1.insert();

                         break;

                  case 2:A1.delete_ele();

                         break;

                  case 3:A1.search();

                         break;

                  case 4:A1.traverse();

                         break;

                  default:cout<<"Invalid entry!"<<endl;

                         break;

    }

    cout<<"Would you like to continue(press 1 to continue):"<<endl;

    cin>>choice2;

    }while(choice2==1);



}



