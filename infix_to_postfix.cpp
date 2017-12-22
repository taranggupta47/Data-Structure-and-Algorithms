#include<iostream>
#include<conio.h>
using namespace std;
class stack
{
 public:
  char stack_array[50];
  int top;
  stack()
  {
    top=-1;
  }
  void push(char symbol)
  {
    if(full())
    {
      cout<<"\nStack overflow:\n";
    }
    else
    {
      top=top+1;
      stack_array[top]=symbol;
     }
   }
   char pop()
   {
     if(empty())
       return('#');         // Return value '#' indicates stack is empty
     else
       return(stack_array[top--]);
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
     if(top==49)
       return(1);
     else
       return(0);
   }
};
class Expression
{
  char infix[50];
  char postfix[50];
  public:
    void read()
    {
      cout<<"\nEnter an infix expression:";
      cin>>infix;
    }
    int white_space(char symbol)
    {
      if(symbol==' ' || symbol=='\t' || symbol=='\0')
     return 1;
      else
     return 0;
    }
    void ConvertToPostfix()
    {
      stack s;
      int l,precedence,p;
      char entry1,entry2;
      p=0;
      for(int i=0;infix[i]!='\0';i++)
      {
    entry1=infix[i];
    if(!white_space(entry1))
    {
      switch(entry1)
      {
        case '(':
          s.push(entry1);
          break;
        case ')':
          while((entry2=s.pop())!='(')
          postfix[p++]=entry2;
          break;
        case '+':{}
        	
        
        case '-':{}
        	
        
        case '*':{}
        	
        
        case '/':{}
        	
        
		if(!s.empty())
          {
        precedence=prec(entry1);
        entry2=s.pop();
        while(precedence<=prec(entry2))
        {
           postfix[p++]=entry2;
           if(!s.empty())
              entry2=s.pop();
           else
              break;
        }
        if(precedence>prec(entry2))
           s.push(entry2);
          }
          s.push(entry1);
          break;
        default:
          postfix[p++]=entry1;
          break;
      }
      }
    }
    while(!s.empty())                //while stack is not empty
       postfix[p++]=s.pop();

    postfix[p]='\0';
    cout<<"\nThe postfix expression is: "<<postfix<<endl;
  }
  int prec(char symbol)
  {
    switch(symbol)
    {
      case '/': return(4);break;          // Precedence of / is 4
      case '*': return(3);break;          // Precedence of * is 3
      case '+': return(2);break;          // Precedence of + is 2
      case '-': return(1);break;          // Precedence of - is 1
      case '(': return(0);break;          // Precedence of ( is 0
      default: return(-1);
    }
  }
};
int main()
{
 char choice='y';
 Expression expr;
 while(choice=='y')
 {
   expr.read();
   expr.ConvertToPostfix();
   cout<<"\n\nDo you want to continue ? (y/n): ";
   cin>>choice;
 }
 getch();
 
}
