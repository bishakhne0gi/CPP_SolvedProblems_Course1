#include <bits/stdc++.h>
using namespace std;
class Stack
{
    vector<int> arr;
    public:
        void push(int data)
        {
            arr.push_back(data);
        }
        void pop()
        {
            arr.pop_back();

        }
        int top()
        {
            int n=arr.size();
            return arr[n-1];
        }
        bool empty()
        {
            return arr.size()==0;
        }
        void display()
        {
            int i=arr.size()-1;
            while(i>=0)
            {
              cout<<arr[i]<<endl;
              i--;
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