#include <bits/stdc++.h>
using namespace std;
class Stack;
class Node
{
    int data;
    public:
        Node * next;
        Node(int d):data(d),next(NULL){}
        int getData()
        {
            return data;
        }
};
class Stack
{
    Node * head;
    public:
        Stack():head(NULL){}

        void push(int data)
        {
            Node * n = new Node(data);
            n->next=head;
            head=n;
        }
        bool empty()
        {
            return head==NULL;
        }
        int top()
        {
            return head->getData();
        }
        void pop()
        {
            if(head!=NULL)
            {
                Node * temp = head;
                head=head->next;
                delete temp;
            }
        }
        void display()
        {
            Node * temp;
            if(head==NULL)
            {
                cout<<"Stack Underflow!"<<endl;
            }
            else{
                temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->getData()<<endl;
                    temp=temp->next;
                }
            }
        }
};
int main()
{
    Stack s;
    int choice;
    int n;
    do
    {   
        cout<<"Enter the choice: 1.Push 2.Top 3.Pop 4.Display";
        cout<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<" Input: ";
                cin>>n;
                s.push(n);
                break;
            case 2:
                cout<<"Top: ";
                cout<<s.top()<<endl;
                break;
            case 3:
                cout<<"popped: ";
                s.pop();
                break;
            case 4:
                s.display();
                cout<<endl;
                break;
            default:
                cout<<"Thank you!"<<endl;
        }
    }while(choice!=5);
    return 0;
}