using namespace std;
#include<iostream>
int main()
{
	char ix[100];
	int i,count=0;
	cout<<"Please enter the BALANCED infix expression: ";
	cin.getline(ix,100);
	for(i=0; ix[i]!='\0'; i++)
	{
		if(ix[i]=='^' || ix[i]=='/' || ix[i]=='*' || ix[i]=='+' || ix[i]=='-' || ix[i]=='(')
			count++;
	}
	char stack[count], px[100];
	int p=-1,top=-1;
	for(i=0; ix[i]!='\0'; i++)
	{
		if(isalnum(ix[i]))

		{

			px[++p] = ix[i];

		}

		else if(ix[i] =='(')

			stack[++top]=ix[i];

		else if(ix[i] ==')')

		{

			while(stack[top]!='(')

			{

				px[++p] = stack[top--];

			}

			top--;

		}

		else if(((ix[i] == '^' || ix[i] == '/' || ix[i] == '*' || ix[i] == '-' || ix[i] == '+') && top==-1) || ((ix[i] == '^' || ix[i] == '/' || ix[i] == '*' || ix[i] == '-' || ix[i] == '+') && stack[top]=='('))

			stack[++top]=ix[i];

		else if(ix[i] == '^')

		{

			stack[++top] = ix[i];

		}

		else if(ix[i] == '/' || ix[i] == '*')

		{

			while((stack[top] != '+' && stack[top] != '-') && top!=-1)

			{

				px[++p] = stack[top--];

			}

			stack[++top] = ix[i];

		}

		else if(ix[i] == '+' || ix[i] == '-')

		{

			while(top!=-1)

			{

				px[++p] = stack[top--];

			}

			stack[++top] = ix[i];

		}

	}

	while(top!=-1)

	{

		px[++p] = stack[top--];

	}

	cout<<"\nThe Postfix expression is: \n";

	for(i=0;i<=p;i++)

		cout<<px[i];

	cout<<endl<<endl;

	return 0;
}
