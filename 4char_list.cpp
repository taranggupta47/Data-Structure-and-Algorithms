#include<iostream>

#include<conio.h>

using namespace std;

class clist

{

      public:

             char a[20],s[20];

             void input()

             {

                  cout<<"Enter string:\n";

                  cin>>a;

             }

             int get_len(char ab[20])

             {int i;

                  for(i=0;ab[i]!='\0';i++);

                  return i;

                  } 

            void rev()

            {int l=get_len(a);

             for(int i=l-1;i>=0;i--)

             cout<<a[i];

             cout<<endl;

             }

      void search_part()

             {

             int f=0,k=0;           

             cout<<"Enter part of string to be searched:\n";

             cin>>s;

             int l1=get_len(s);

             int l2=get_len(a);

             for(int i=0;i<l2;i++)

             {
			 f=0;

             for(int j=0;j<l1;j++)

             {
			 if(a[i+j]==s[j])

             f++;
			 }

             if(f==l1)

             {
			 cout<<"Found\n";

             k=1;

             break;

             }

             }

             if(k==0)

             cout<<"not found";

             }

      void del_part()

      {

             int f=0,k=0,u;char t[20];           

             cout<<"Enter part of string to be deleted:\n";

             cin>>s;

             int l1=get_len(s);

             int l2=get_len(a);

             for(int i=0;i<l2;i++)

             {
			 f=0;

             for(int j=0;j<l1;j++)

             {if(a[i+j]==s[j])

             f++;}

             if(f==l1)

             {

             u=i;     

             break;

             }

             }

             for(int i=0;i<l2;i++)

             {

             if(i>=u)

             a[i]=a[i+l1];

             

             }

             

             l2=l2-l1;

             for(int i=0;i<l2;i++)

             cout<<a[i];

             cout<<endl;

             }

                  

             };

             int main()

             {

                 clist ob;

                 ob.input();

                 ob.rev();

                 ob.search_part();

                 ob.del_part();

                 getch();

                 return 0;

                 }           

