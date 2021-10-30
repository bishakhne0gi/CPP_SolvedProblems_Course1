template<typename T>
class Vector{
    //Data Members
    int cs;//current size
    int ms;//maximum size
    T *arr;//dynamic array variable(T type pointer variable)
    public:
        //parameterized constructor
        Vector(int max_size=1){
            cs=0;
            ms=max_size;
            arr= new T[ms];
        }
        void pushBack(int d){
            //Two Cases
            // Create a new array and delete the old one, double the capacity
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
        //delete element from the end of the array
        void popBack(){
            if(cs>=0){
                cs--;
            }
        }
        //first element of the array
        T front(){
            return arr[0];
        }
        //last element of the array
        T back(){
            return arr[cs-1];
        }
        //size taken by the array
        int size(){
            return cs;
        }
        //maximum capacity of array
        int capacity(){
            return ms;
        }
        //operator overloading
        T operator[](int i){
            return arr[i];
        }
};