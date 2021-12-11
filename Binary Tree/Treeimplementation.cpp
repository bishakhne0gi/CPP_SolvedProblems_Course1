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
    return 0;

}