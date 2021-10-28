#include <bits/stdc++.h>
using namespace std;
pair<int,int> stairCase(int m, int n, int arr[][4],int key){
    //if element is not present return pair of -1,-1
    if(key<arr[0][0] or key>arr[m-1][n-1]){
        return {-1,-1};
    }

    //staircase search
    int i=0; 
    int j=n-1;
    while(i<m and j>=0){
        if(arr[i][j]==key){
            return{i,j};
        }
        else if(arr[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
}
int main(){
    int arr[][4]={{10,20,30,40},
                    {15,25,35,45},
                    {27,29,37,48},
                    {32,33,39,50}};
    int n=4, m=4;
    pair<int,int> coords= stairCase(m,n,arr,25);
    cout<<coords.first<<" "<<coords.second<<endl;
    return 0;
}