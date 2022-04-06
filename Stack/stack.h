template<typename T>
class Stack
{
    int cs;
    int ms;
    T *arr;
    public:
        Stack(int max_size=1)
        {
            cs=0;
            ms=max_size;
            arr= new T[ms];
        }
        void push(int data)
        {
             if(cs==ms){
                T *oldArr= arr;
                ms=2*ms;
                arr = new T[ms];
                //copy the elements
                for(int i=0; i<ms; i++){
                    arr[i]= oldArr[i];
                }
                delete [] oldArr;
            }
            arr[cs]=d;
            cs++;
        }
         bool empty()
        {
            return arr.size()==0;
        }
        void pop()
        {
            if(cs>0){
                cs--;
            }
        }
       int size(){
            return cs;
        }
        void insertAtBottom(int data)
        {
            //base case
            if(empty())
            {
                return push(data);
            }
            //recursive case
            int temp=top();
            pop();
            insertAtBottom(data);
            push(temp);
        }
        T top()
        {
            int n=arr.size();
            if(!empty())
                return arr[n-1];
            return 0;
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