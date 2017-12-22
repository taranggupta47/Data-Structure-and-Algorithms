#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node* newnode(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
node* min(node *root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}
node* insert(node* root,int x)
{
    if(root==NULL)
            root=newnode(x);
    else if(x<=root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);

        return root;
}
bool search(node* root,int x)
{
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    else if(x<root->data)
        return search(root->left,x);
    else
        return search(root->right,x);
    return false;
}
node* del(node *root,int x)
{
    if(root==NULL)
        return root;
    else if(x<root->data)
        del(root->left,x);
    else if(x>root->data)
        del(root->right,x);
    else
    {
        if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                root=NULL;
            }
        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
           node *temp=root;
            root=root->left;
            delete temp;
        }
        else
        {
            node *temp=min(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    node *root=NULL;
    int c,x;
    do{
    cout<<"\nenter 1 to insert data ";
    cout<<"\nenter 2 to delete node ";
    cout<<"\nenter 3 to search ";
    cout<<"\nenter 4 to exit ";
    cout<<"\nenter your choice ";
    cin>>c;
    switch(c){
                case 1:cout<<"\nenter data ";
                        cin>>x;root=insert(root,x);
                        break;
                case 2:cout<<"\nenter data to be deleted ";
                        cin>>x;
                        root=del(root,x);
                        break;
                case 3:cout<<"\nenter data to be searched ";cin>>x;
                        if(search(root,x)==true)
                            cout<<"\ndata found ";
                        else
                            cout<<"\ndata  not found ";
                        break;
             }
    }while(c!=4);
    return 0;
}
