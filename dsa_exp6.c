#include<conio.h>
#include<stdio.h>
#include<string.h>
#define maxsize 100
void main()
{
	int st[maxsize];
	int top=-1;
	char ch[50];
	
	printf("Enter the expression \n");
	gets(ch);
	
	int flag=0,i=0;
	while(ch[i]!='\0')
	{
	/*	if(ch[i]!='['||ch[i]!='{'||ch[i]!='('||ch[i]!=']'||ch[i]!='}'||ch[i]!=')')
		{
			flag=1;
			break;
		} */
		if(ch[i]=='['||ch[i]=='{'||ch[i]=='(')
		{
			top++;
			st[top]=ch[i];
			
		}
		else if(ch[i]==']'||ch[i]=='}'||ch[i]==')')
		{
			top--;
		}
		i++;
	}
		if(top==-1)
		printf("Balanced \n");
		else
		printf("Not balanced \n");
	//	if(flag==1)
	//	printf("Error!");
		
		 getch();
}
