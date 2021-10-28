#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the size of NxM matrix: "<<endl;
    cin>>m>>n;

    vector<vector<int>> A(n,vector<int>(m,0));
    
    //input elements of the vector
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }

    //Output of the vector
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }

    //Auxiliary Matrix
    vector<vector<int>> M(n,vector<int>(m,0));
    M[0][0]=A[0][0];
    for(int i=1;i<m;i++)
    {

            M[i][0]=A[i][0]+M[i-1][0];
    }

   

    for(int i=1;i<n;i++)
    {       
            M[0][i]=A[0][i]+M[0][i-1];
        
    }

   

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)

        {

                M[i][j]= A[i][j]+M[i-1][j] + M[i][j-1] - M[i-1][j-1];

        }

    }

   

    for(int i=0;i<m;i++)

    {

        for(int j=0;j<n;j++)

        {

            cout<<M[i][j]<<"\t";

        }

        cout<<endl;

    }
    int tli, tlj, bri,brj;
    cout<<"Enter the top left row and column coords:  "<<endl;
    cin>>tli>>tlj;
    cout<<"Enter the bottom left row and column coords:  "<<endl;
    cin>>bri>>brj;
    int ans=0;
    if(tli==0 and tlj==0){
        ans=M[bri][brj];
        }

    else if(tli==0 and tlj!=0){
        ans=M[bri][brj]-M[bri][tlj-1];
    }
     else if(tli!=0 and tlj==0){
        ans=M[bri][brj]-M[tli-1][brj];
    }
    else if(tli!=0 and tlj!=0){
        ans=M[bri][brj]-(M[bri][tlj-1]+M[tli-1][brj]-M[tli-1][tlj-1]);
    }
    cout<<ans<<endl;
    return 0;
}