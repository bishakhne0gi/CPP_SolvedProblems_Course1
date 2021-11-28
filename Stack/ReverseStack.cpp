#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s,int data)
        {
            //base case
            if(s.empty())
            {
                return s.push(data);
            }
            //recursive case
            int temp=s.top();
            s.pop();
            insertAtBottom(s,data);
            s.push(temp);
        }
void reverse(stack<int> &s)
{
    //base case
    if(s.empty())
        return;
    int top=s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s,top);
}
int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    stack<int> s2(s);//copy s into s2
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    reverse(s2);
    cout<<"reverse: "<<endl;
    cout<<endl;
    while(!s2.empty())
    {
        cout<<s2.top()<<endl;
        s2.pop();
    }
    return 0;
}