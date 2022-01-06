#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int key;
        Node * left;
        Node * right;
        Node(int d): key(d), left(NULL), right(NULL){}


};
Node * buildTree(Node * root, int key)
{
    //base case
    if(root==NULL)
        return new Node(key);
    if(key<root->key)
        root->left=buildTree(root->left, key);
    else
        root->right=buildTree(root->right, key);
    return root;
}
void inOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    
    inOrderTravesal(root->left);
    cout<<root->key<<" ";
    inOrderTravesal(root->right);

}
void preOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    cout<<root->key<<" ";
    preOrderTravesal(root->left);
    
    preOrderTravesal(root->right);

}
void postOrderTravesal(Node * root)
{
    if(root==NULL)
        return;
    
    postOrderTravesal(root->left);
    
    postOrderTravesal(root->right);
    cout<<root->key<<" ";

}
bool search(Node * root, int key)
{
    if(root==NULL)
        return false;
    if(root->key==key)
    {
        return true;
    }
    if(key<root->key)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}
Node * findMin(Node * root)
{
    while(root->left !=NULL)
        root=root->left;
    return root;
}
Node * remove(Node * root, int key)
{
    if(root== NULL)
        return NULL;
    else if(key<root->key)
        root->left=remove(root->left,key);
    else if(key>root->key)
         root->left=remove(root->left,key);
    else
    {
        //when current node matches with the key
        //case 1: with no children
        if(root->left == NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //case 2: with one children
        else if(root->left == NULL)
        {
            Node * temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node * temp=root;
            root=root->left;
            delete temp;
        }
        //case 3: with 2 children
        else{
            Node * temp= findMin(root->right);
            root->key=temp->key;
            root->right=remove(root->right,temp->key);
        }


    }
    return root;    

}
int main()
{
    Node * root= NULL;
    vector<int> arr= {8,3,10,1,6,14,4,7,13};
    for(int x: arr)
    {
        root=buildTree(root,x);
    }
    cout<<"In Order: "<<endl;
    inOrderTravesal(root);
    cout<<endl;
    cout<<"Pre Order: "<<endl;
    preOrderTravesal(root);
    cout<<endl;
    cout<<"Post Order: "<<endl;
    postOrderTravesal(root);
    cout<<endl;
    cout<<"Search: "<<endl;
    cout<<search(root,6);
    cout<<endl;
    cout<<"Deletion: "<<endl;
    cout<<"Enter the key: "<<endl;
    int key;
    cin>>key;
    root=remove(root,key);
    cout<<"In Order: "<<endl;
    inOrderTravesal(root);
    return 0;

}