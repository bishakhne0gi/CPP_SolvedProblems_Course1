#include <bits/stdc++.h>
using namespace std;
// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1 
class Node
{
    public:
        int data;
        Node * left;
        Node * right;
        Node(int d):data(d),left(NULL),right(NULL){}
};
class Pair
{
    public:
        int height;
        int diameter;
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
void levelOrderPrint(Node * root)
{
    queue <Node * > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node * temp = q.front();
        if(temp==NULL)
        {
            cout<<endl;
            q.pop();
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

    }
    return;
}
int height(Node * root)
{
    if(root==NULL)
        return 0;
    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}
int diam(Node * root)
{
    if(root==NULL)
        return 0;
    int d1=height(root->left)+ height(root->right);
    int d2=diam(root->left);
    int d3=diam(root->right);
    return max(d1,max(d2,d3));
}
Pair optDiam(Node *root)
{
    Pair p;
    if(root==NULL)
    {
        p.height=p.diameter=0;
        return p;
    }
    Pair Left=optDiam(root->left);
    Pair Right=optDiam(root->right);
    p.height=max(Left.height,Right.height)+1;

    int d1=Left.height+Right.height;
    int d2=Left.diameter;
    int d3=Right.diameter;
    
    p.diameter=max(d1,max(d2,d3));
    return p;


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
    cout<<endl;
    cout<<"Level Order: "<<endl;
    levelOrderPrint(root);
    cout<<endl;
    cout<<"Height of the binary tree: "<<height(root)<<endl;
    cout<<endl;
    cout<<"Diameter is: "<<diam(root)<<endl;
    cout<<endl;
    cout<<"Optimised Diameter is: "<<optDiam(root).diameter<<endl;
    return 0;

}