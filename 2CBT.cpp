#include<stdio.h>
#include<iostream>
using namespace std;
char last;
template<class x,class y>class que
{
	public:
		x arr[20];
		int f,r;
		que()
		{
			f=r=-1;
		}
		
		que(int a)
		{
			y temp;
			f=r=-1;
			for(int i=0;i<20;++i)
			arr[i]=temp;
		}
		
		void enq(x a)
		{
			if(f==-1)
			f=r=0;
			else
			++r;
			arr[r]=a;
		}
		
		x deq()
		{ y te;
		x temp=te;
			if(f==r)
			{
				temp=arr[f];
				f=r=-1;
			}
			else
			   temp=arr[f++];
			   return temp;
			
		}
		
		x rd()
		{
			return arr[f];
		}
};
class node
{
	public:
		char ch;
		node* left;
		node* right;
		node(char tt)
		{
			ch=tt;
			left=right=NULL;
		}
};


class cbt
{
	public:
		node* start;
		cbt()
		{
			start=NULL;
		}
		
		void add(node*& rt,char hy)
		{
			if(rt==NULL)
			 rt=new node(hy);
			else
			 {
			 	que<node*,node*> q1;
			 	
			 	q1.enq(rt);
			 	while(q1.f!=-1)
			 	{
			 		node* temp=q1.deq();
			 		if(temp->left==NULL)
			 		{
			 			temp->left=new node(hy);
			 			break;
			 			
			 		}
			 		else if(temp->right==NULL)
			 		{
			 			temp->right=new node(hy);
			 			break;
			 		}
			 		else
			 		{
			 			q1.enq(temp->left);
			 			q1.enq(temp->right);
			 		}
			 	}
			 }
				
			}
			
		node* search(node* rt,char ff)	
		{
			node* temp;
		que<node*,node*> q2;
		
		q2.enq(rt);
			while(q2.f!=-1)
			 	{
			 		 temp=q2.deq();
			 		 if(temp->ch==ff)
			 		 break;
			 		 
			 		 else
			 		 {
			 		 	if(temp->left!=NULL)
			 		 	q2.enq(temp->left);
			 		 	if(temp->right!=NULL)
			 		 	q2.enq(temp->right);
			 		 	
			 		 }
			 	}
			 	
			 	return temp;
		}
		void de(node*& rt,char ff)
		{
			if(rt->ch==ff)
			rt=NULL;
			else
			{
				if(rt->left!=NULL)
				de(rt->left,ff);
				if(rt->right!=NULL)
				de(rt->right,ff);
			}
		}	
			
		void del(node* rt,char pp)
		{
		node* temp=search(rt,pp);
		 que<node*,node*> q1;
		 last=rt->ch;
		 q1.enq(rt);
		 while(q1.f!=-1)
		 {
		 	node* uio=q1.deq();
		 	if(uio->left==NULL)break;
		 	else
		 	{
		 		last=uio->left->ch;
		 		q1.enq(uio->left);
		 		if(uio->right==NULL)break;
		 		else
		 		{
		 			last=uio->right->ch;
		 			q1.enq(uio->right);
		 		}
		 	}
		 	
		 }
		de(start,last);
		temp->ch=last;
		
				
		}	
		
		void preorder(node* rt)
		{
			if(rt==NULL)
			;
			else
			{
				cout<<rt->ch<<"    ";
				preorder(rt->left);
				preorder(rt->right);
			}
		}
		
};

main()
{
	cbt c1;int op;
	
	do
	{
		cout<<"enter 1 to add , 2 to delete , 3 to print , 4 to exit::";
		
		cin>>op;
		
		switch(op)
		{
			case 1:cout<<"enter character to be added::";
			       char ty;
			       cin>>ty;
			       
			       c1.add(c1.start,ty);
			       break;
			       
			case 2:cout<<"enter character to  be  deleted::";
			       char rt;
			       cin>>rt;
			       c1.del(c1.start,rt);
			       break;
			       
			case 3:cout<<"tree ::\n";
			       c1.preorder(c1.start);
			       cout<<"\n";
				   break;
				   
				   
				           
			              
		}
	}while(op!=4);
}

