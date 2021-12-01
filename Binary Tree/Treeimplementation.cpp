#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        Node * left;
        Node * right;
        Node(int d):data(d),left(NULL),right(NULL){}
};
//build tree pre-order
Node * buildTree()
{   
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node * n= new Node(d);
    n->left=buildTree();
    n->right=buildTree();
    return n;
}
void preOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void inOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(Node * root)
{
    if(root==NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    Node * root = buildTree();
    cout<<"Pre Order: "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    cout<<"In Order: "<<endl;
    inOrderTraversal(root);
    cout<<endl;
    cout<<"Post Order: "<<endl;
    postOrderTraversal(root);
    return 0;
}