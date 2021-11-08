#include <bits/stdc++.h>
using namespace std;
int getIthBit(int n, int i){
    int mask=(1<<i);
    return(n & mask)>0 ? 1: 0;
}
int clearIthBit(int n, int i){
    int mask=~(1<<i);
    n=n & mask;
    return n;
}
void setIthBit(int &n, int i){
    int mask=1<<i;
    n=n|mask;
    cout<<n<<endl;
}
void updateIthBit(int &n, int i, int v){
    clearIthBit(n,i);
    int mask = (v<<i);
    n=n|mask;
    cout<<n<<endl;
}
void clearLastIthBit(int &n, int i){
    int mask = ((-1)<<i);
    n=n & mask;
    cout<<n<<endl;
}
 
int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int choice;
    int i,j;
    do{
        
        cout<<"1.GetIthBit 2.ClearIthBit 3.SetIthBit 4.UpdateIthBit 5.clearLastIthBit ";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the position: ";
                cin>>i;
                cout<< getIthBit(n,i)<<endl;
                break;
            case 2:
                cout<<"Enter the position: ";
                cin>>i;
                cout<< clearIthBit(n,i)<<endl;
                break;
            case 3:
                cout<<"Enter the position: ";
                cin>>i;
                setIthBit(n,i);
                break;
            case 4:
                cout<<"Enter the position: ";
                cin>>i;
                cout<<"Enter the number to be entered(0/1): ";
                cin>>j;
                updateIthBit(n,i,j);
                break;
            case 5:
                cout<<"Enter the position: ";
                cin>>i;
                clearLastIthBit(n,i);
                break;
            default:
                cout<<"Enter correct choice"<<endl;

        }
    }while(choice !=6);
    return 0;
}