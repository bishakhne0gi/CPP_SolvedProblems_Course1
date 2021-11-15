#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void helper(int k, vector<int> &v, int i){
    if(i==v.size()){
        return;
    }
    if(v[i]==k){
        vec.push_back(i);
        
    }
    helper(k,v,i+1);
    return;
}
vector<int> findAllOccurences(int k, vector<int> &v){
       vec.clear();
       helper(k,v,0);
       return vec;
}
void print(){
    for(auto x:vec){
        cout<<x<<endl;
    }
}
int main(){
    vector<int> v= {1,2,3,5,4,3,6};
    int k=3;
    findAllOccurences(k,v);
    print();
    return 0;
}