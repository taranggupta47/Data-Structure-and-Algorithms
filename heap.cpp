#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
void crhp(int *brr,int p)
{
	for(int i=p;i>=2;--i)
	{
		if(brr[i]>brr[i/2])
		{
			int temp=brr[i/2];
			brr[i/2]=brr[i];
			brr[i]=temp;
			i=p+1;
			
		}
	}
}
int main()
{ int n=5;
	int brr[]={0,1,999,23,94,64};
	for(int i=n;i>=2;--i)
	{
		crhp(brr,i);
		int temp=brr[1];
		brr[1]=brr[i];
		brr[i]=temp;
	}
	for(int i=1;i<=n;++i)
	cout<<brr[i]<<"\n";
	getch();
}
