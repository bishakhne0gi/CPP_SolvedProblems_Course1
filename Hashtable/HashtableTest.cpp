#include<iostream>
#include "Hashtable.h"
using namespace std;
int main()
{
    Hashtable<int> h;
    h.insert("a",10);
    h.insert("b",20);
    h.insert("c",30);
    h.insert("d",40);
    h.insert("e",50);
    h.insert("f",60);
    h.insert("g",70);
    h.insert("h",80);
    h.print();
 
    string key;
    cin>>key;
    int *price= h.search(key);
    if(price!=NULL)
    {
        cout<<"Price of key is: "<<*price<<endl;
    }
    else{
        cout<<"Fruit not found."<<endl;
    }
       return 0;
}