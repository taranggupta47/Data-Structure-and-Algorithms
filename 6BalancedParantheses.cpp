using namespace std;



#include<iostream>



int main()

{



	char str[100];

	int i, count=0;

	cout<<"Please input the expression: ";



//	cin.getline(str,100);
cin>>str;

	for(i=0; str[i]!='\0'; i++)

	{

		if(str[i]=='[' || str[i]==']' || str[i]=='{' || str[i]=='}' || str[i]=='(' || str[i]==')')

			count++;

	}



	char stack[count],top=-1,flag=1;



	for(i=0;str[i]!='\0';i++)

	{

		if(str[i]=='[' || str[i]==']' || str[i]=='{' || str[i]=='}' || str[i]=='(' || str[i]==')')

		{

			if(str[i]=='(' || str[i]=='{' || str[i]=='[')

				stack[++top]=str[i];

			else if(str[i]==']' && stack[top]=='[')

				top--;

			else if(str[i]=='}' && stack[top]=='{')

				top--;

			else if(str[i]==')' && stack[top]=='(')

				top--;

			else

			{

				cout<<"\n\nUnbalanced Parantheses!\n\n";

				flag=0;

				break;

			}

		}

	}

	if(flag)

		cout<<"\n\nBalanced Parantheses!\n\n";



	return 0;

}



