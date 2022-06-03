#include <bits/stdc++.h>
using namespace std;

void jobSequencing(char id[], int deadline[], int profit[], int n)
{
    char result[7];
    int maximum_deadline=deadline[0];
    for(int i=1; i<7; i++)
    {
        maximum_deadline=max(maximum_deadline,deadline[i]);
    }

    int slot[maximum_deadline+1];
    for(int i=0; i<=maximum_deadline; i++)
        slot[i]=-1;
    int maxProfit=0;
    int countJob=0;
    for(int i=0; i<n; i++)
    {
        for(int j=deadline[i]; j>0; j--)
        {
            if(slot[j]==-1)
            {
                result[j]=id[countJob];
                countJob++;
                slot[j]=i;
                maxProfit+=profit[i];
                break;
            }
        }
    }
    cout<<endl;
    cout<<"JOB SEQUENCING: "<<endl;
    for(int i=1; i<=countJob; i++)
    {
        cout<<result[i]<<"->";
    }
    cout<<endl;
    cout<<"MAX PROFIT: "<<endl;
    cout<<maxProfit<<endl;
}
int main()
{
    // int deadline[7];
    char id[]={'A','B','C','D','E','F','G'};
    int deadline[]={1,3,4,3,2,1,2};
    // int profit[7];
    int profit[]={3,5,20,18,1,6,30};
    int n=7;

    // cout<<"Enter the deadlines: "<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     int z;
    //     cin>>z;
    //     deadline[i]=z;
    // }

    // cout<<"Enter the profits: "<<endl;
    // for(int i=0; i<n; i++)
    // {
    //     int z;
    //     cin>>z;
    //     profit[i]=z;
    // }



    cout << "IDS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << id[i] << " ";
    }
    cout << endl;
    cout << "DEADLINES: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << deadline[i] << " ";
    }
    cout << endl;
    cout << "PROFITS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;


    char temp_id;
    int temp_profit=0, temp_deadline=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                temp_id = id[j];
                id[j] = id[i];
                id[i] = temp_id;

                temp_profit = profit[j];
                profit[j] = profit[i];
                profit[i] = temp_profit;

                temp_deadline = deadline[j];
                deadline[j] = deadline[i];
                deadline[i] = temp_deadline;
            }
        }
    }
    cout<<endl;

    cout<<"AFTER SORTING THE PROFITS: "<<endl;

    cout << "IDS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << id[i] << " ";
    }
    cout << endl;
    cout << "DEADLINES: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << deadline[i] << " ";
    }
    cout << endl;
    cout << "PROFITS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;
    jobSequencing(id, deadline, profit, n);
    return 0;
}