#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> num;
    num.push(20);
    num.push(19);
    num.push(18);
    while(!num.empty())
    {
        cout<<num.top()<<endl;
        num.pop();
    }
    return 0;
}