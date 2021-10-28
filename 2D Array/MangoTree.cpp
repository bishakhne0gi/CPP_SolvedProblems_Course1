#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of NxN matrix: "<<endl;
    cin>>n;

    vector<vector<char>> A(n,vector<char>(n,0));
    
    //input elements of the vector
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>A[i][j];
        }
    }

    //Output of the vector
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }

    //Auxiliary Matrix
    vector<vector<int>> M(n,vector<int>(n,0));

      for(int i=0;i<n;i++)

    {

        if(A[i][0]=='#')

            M[i][0]=1;

        else

            M[i][0]=0;

           

        if(i!=0)

            M[i][0]+=M[i-1][0];

       

    }

   

    for(int i=0;i<n;i++)

    {

        if(A[0][i]=='#')

            M[0][i]=1;

        else

            M[0][i]=0;

           

        if(i!=0)

            M[0][i]+=M[0][i-1];

       

    }

   

    for(int i=1;i<n;i++)

    {

        for(int j=1;j<n;j++)

        {

            if(A[i][j]=='#')

                M[i][j]= 1+M[i-1][j] + M[i][j-1] - M[i-1][j-1];

            else

                M[i][j]= 0 + M[i-1][j] + M[i][j-1] - M[i-1][j-1];

        }

    }

   

    for(int i=0;i<n;i++)

    {

        for(int j=0;j<n;j++)

        {

            cout<<M[i][j]<<" ";

        }

        cout<<endl;

    }

    int ans=0;

   

   

    for(int i=0;i<n-1;i++)

    {

        int s1=1,s2=0,s3=0,s4=0;

        int minimum=0;

        for(int j=0;j<n-1;j++)

        {

           

            s1=M[i][j];

            s2=M[i][n-1]-M[i][j];

            s3=M[n-1][j]-M[i][j];

            s4=M[n-1][n-1]-(s1+s2+s3);

           

            minimum=min({s1,s2,s3,s4});

            ans=max(ans,minimum);

        }

       

    }

   

    cout<<"max of min is: "<<ans;

    return 0;
}