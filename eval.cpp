#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
using namespace std;
class eval
{
      public:
double s[10];
  int top;
  eval()
  {
  top=-1;
  }
  void push(double it)
  {
    if(full())
    cout<<"\nStack overflow:\n";
    else
    {
      top=top+1;
      s[top]=it;
     }
   }
   double pop()
   {
     if(empty())
       return 0.0;        
            else
       {return(s[top--]);
       }
   }
   int empty()
   {
     if(top==-1)
       return(1);
     else
       return(0);
   }
   int full()
   {
     if(top==9)
       return(1);
    else 
    return(0);
   }
      double oper(char sym,double op1,double op2)
      {
             if(sym=='+')
             return op1+op2;
             else if(sym=='-')
             return op1-op2;
             else if(sym=='/')
             return op1/op2;
             else if(sym=='*')
             return op1*op2;
             else if(sym=='^')
             return (pow(op1,op2));
             }
             
      double evaluat(char ex[30])
             {char c;double op1,op2,val;int i=0,l=strlen(ex);
             while(i<l)
             {
             c=ex[i];
             if(isdigit(c))
             push((double)(c-48));
              else
              {
              op2=pop();
              op1=pop();
              val=oper(c,op1,op2);
              push(val);
              }
              i++;
              }
              return(pop());
             }
      };
                           int main()
                           {
                               eval ob;
                               char exp[20];
                               cout<<"Enter valid postfix expression:\n";
                               cin>>exp;
                               cout<<ob.evaluat(exp)<<endl;
             getch();
             return 0;
             }
             
