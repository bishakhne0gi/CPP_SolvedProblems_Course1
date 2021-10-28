#include <iostream>
using namespace std;
void print( int arr[50][50],int m, int n){

    int num=1;
    //variables
    int startRow=0;
    int endRow=m-1;
    int startCol=0;
    int endCol=n-1;
    //outer loop traversing
    while( startRow<=endRow && startCol<=endCol ){
        //Start Row
        for(int col=startCol; col<=endCol; col++){
            arr[startRow][col]= num++;
        }
        //End Column
        for(int row=startRow+1; row<=endRow; row++){
            
           
            arr[row][endCol]= num++;
            
        }
        //EndRow
        for(int col=endCol-1; col>=startCol; col--){
            if(startRow==endRow ){
                break;
            }
           
            arr[endRow][col]= num++;
        }
        //Start Column
        for(int row=endRow-1; row>=startRow+1; row--){
              if(startCol==endCol){
                break;
            }
            arr[row][startCol]= num++;
        }

        //to point to inner elements
        startRow++;
        endRow--;
        startCol++;
        
        endCol--;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
        
    }
}
int main(){
    cout<<"Enter the number of rows and columns: ";
    int n;
    int m;
    cin>>m>>n;
    int arr[50][50];
    print(arr,m, n);
    
    return 0;
}