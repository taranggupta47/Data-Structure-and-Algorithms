#include<iostream>
#include<string.h>
#include<ctype.h>
#define max 100
using namespace std;
class str
{
	char a[max];
	public:
		str()
		{
			cout<<"Enter a string \n";
			cin>>a;
		}
	/*	void input()
		{
			int i;
			for(i=0;a[i]!='\0';i++)
			a[i]=getchar();
		} */
	    int getStringLength()
		{
			int i,count=0;
			for(i=0;a[i]!='\0';i++)
			count++;
			return count;
		}
		
		
void deletePartofString()
{

int len1,len2,i,cntr1,cntr2,flag=0;
      char str2[50];
     
      printf("Enter the substring to be deleted:\n");
      scanf("%s",str2);
     len1=strlen(a);
      len2=strlen(str2);
      for(i=0;len2<=len1-i;i++)
      {
            for(cntr1=i,cntr2=0;cntr2<=len2&&a[cntr1]==str2[cntr2];cntr1++,cntr2++);
            if(len2<=cntr2)
            {
                  flag=1;
                  break;
            }
      }
      if(flag==0)
      printf("%s substring is not present in string %s so cannot be deleted",str2,a);
      else
      {
            for(;(i+len2+1)<=len1;i++)
            a[i]=a[len2+i];
            a[i]='\0';
      }
      printf("\nSubstring %s has been deleted and resultant string is :  %s",str2,a);		
			
} 
		
void searchPartofString(char s[])
{
				
	int count1=0,count2=0,i,j,flag;
	while (a[count1]!='\0')
		count1++;

	while (s[count2]!='\0')
		count2++;

	for(i=0;i<=count1-count2;i++)
	{
		for(j=i;j<i+count2;j++)
		{
			flag=1;
			if (a[j]!=s[j-i])
			{
				flag=0;
			   break;
			}
		}
		if (flag==1)
			break;
	}
	if (flag==1)
		cout<<"SEARCH SUCCESSFUL!";
	else
		cout<<"SEARCH UNSUCCESSFUL!";

		}		
		
		
		void InsertCharacterinString(char l,int x)
		{
			int i,len=0;
			for(i=x-1;a[i]!='\0';i++)
			{
		      len++;
			}
			for(i=len;i>=x-1;i--)
			{
				a[i+1]=a[i];
			}
			a[x-1]=l;
		}
		
		void stringReverse()
		{
			int len=0;
			for(int i=0;a[i]!='\0';i++)
			len++;
			for(int i=len-1;i>=0;i--)
			cout<<a[i];
		}
		void display()
		{
			for(int i=0;a[i]!='\0';i++)
			cout<<a[i];
		}
};

int main()
{
	str w;
	int ch,c,p,sl;
	char ss[10];
	char cs;
	while(c!=0)
	{
	cout<<"Enter 1 to get the string length,2 to search a particular string,3 to delete a part of string, \n 4 to insert a character in string, 5 to reverse string and 6 to display string \n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		    sl=w.getStringLength();
		    cout<<"String length:"<<sl<<endl;
		    break;
		case 2:
			cout<<"Enter a string to be searched \n";
			cin>>ss;
			w.searchPartofString(ss);
			break;
		case 3:
		
			w.deletePartofString();
			break;
		case 4:
			cout<<"Enter the character to be inserted \n";
			cin>>cs;
			cout<<"Enter the position \n";
			cin>>p;
			w.InsertCharacterinString(cs,p);
			break;
		case 5:
			w.stringReverse();
			break;
		case 6:
			w.display();
			break;
		default: 
		    cout<<"Wrong choice!";
			
	}
	cout<<"\n Enter 0 to exit and any other key to continue \n";
	cin>>c;
}
return 0;
}
