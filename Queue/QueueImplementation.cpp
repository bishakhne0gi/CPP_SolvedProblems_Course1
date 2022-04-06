#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int cs;
    int ms;
    int front;
    int rear;

public:
    Queue(int default_size = 5)
    {
        ms = default_size;
        arr = new int[ms];
        cs = 0;
        front = 0;
        rear = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }
    bool empty()
    {
        return cs == 0;
    }
    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }
    int frontFun()
    {
        if (!empty())
            return arr[front];
        return 0;
    }
    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % ms;
            cs--;
        }
    }
};
int main()
{
    Queue q;
    int choice;
    do
    {
        cout << "Enter the choice: " << endl;
        cout << "1.Push 2.Pop 3.Front 4.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int d;
            cout << "Enter the element: " << endl;
            cin >> d;
            q.push(d);
            break;
        case 2:
            q.pop();
            break;
        case 3:
            cout << "Front Element: ";
            cout << q.frontFun() << endl;
            break;
        default:
            cout << "Enter correct choice" << endl;
        }
    } while (choice != 4);
    return 0;
}