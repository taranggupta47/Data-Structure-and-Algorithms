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
node* insert(node *root,int x)
{
    if(root==NULL)
        root=newnode(x);
    else if(x<=root->data)
        root->left=insert(root->left,x);
    else
        root->right=insert(root->right,x);
        return root;
}
void preorder(node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
void inorder(node *root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
int main()
{
    node *root=NULL;
    int c,x;
    do{
    cout<<"\nenter 1 to insert data ";
    cout<<"\nenter 2 for preorder traversal ";
    cout<<"\nenter 3 for postorder traversal ";
    cout<<"\nenter 4 for inorder traversal ";
    cout<<"\nenter 5 to exit ";
    cout<<"\nenter your choice ";
    cin>>c;
    switch(c){
                case 1:cout<<"\nenter data ";cin>>x;root=insert(root,x);break;
                case 2:preorder(root);break;
                case 3:postorder(root);break;
                case 4:inorder(root);break;
             }
    }while(c!=5);
    return 0;
}
