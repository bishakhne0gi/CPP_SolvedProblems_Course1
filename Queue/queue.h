template <typename T>
class Queue
{
    T *arr;
    int cs;
    int ms;
    int front;
    int rear;

public:
    Queue(int default_size = 5)
    {
        ms = default_size;
        arr = new T[ms];
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
    T frontFun()
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