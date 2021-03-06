#include <iostream>
using namespace std;
class Vector{
    //Data Members
    int cs;//current size
    int ms;//maximum size
    int *arr;//dynamic array variable(integer pointer variable)
    public:
        //parameterized constructor
        Vector(int max_size=1){
            cs=0;
            ms=max_size;
            arr= new int[ms];
        }
        bool empty()
        {
            return cs==0;
        }
        void pushBack(int d){
            //Two Cases
            // Create a new array and delete the old one, double the capacity
            if(cs==ms){
                int *oldArr= arr;
                ms=2*ms;
                arr = new int[ms];
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
            if(cs>0){
                cs--;
            }
        }
        //first element of the array
        int front(){
            if(!empty())
                return arr[0];
            return 0;    

        }
        //last element of the array
        int back(){
             if(!empty())
                return arr[cs-1];
            return 0; 
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
        int operator[](int i){
            return arr[i];
        }
};
int main(){
    Vector v;
    int choice;
    do{
        cout<<"Enter the choice: "<<endl;
         cout<<"1.Push 2.Pop 3.Size 4.Capacity 5.Print 6.Front Element 7.Back Element 8.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1: 
                    int d;
                    cout<<"Enter the element: "<<endl;
                    cin>>d;
                    v.pushBack(d);
                    break;
            case 2:
                    v.popBack();
                    break;
            case 3:
                    cout<<"Size: "<<v.size()<<endl;
                    break;
            case 4:
                    cout<<"Capacity: "<<v.capacity()<<endl;
                    break;
            case 5:
                    for(int i=0; i<v.size(); i++){
                        cout<<v[i]<<" "<<endl;
                    }
                    break;
            case 6:
                    cout<<"Front element: "<<v.front()<<endl;
                    break;
            case 7:
                     cout<<"Last element: "<<v.back()<<endl;
                    break;
            default:
                    cout<<"Enter correct choice"<<endl;
        }
    }while(choice!=8);
    return 0;
}