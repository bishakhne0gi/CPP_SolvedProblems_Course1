#include<bits/stdc++.h>
using namespace std;
void jS(char id[], int deadline[], int profit[], int n)
{
    char result[10];
    int max_deadline=deadline[0];
    for(int i=1; i<n; i++)
    {
        max_deadline=max(max_deadline,deadline[i]);
    }
    int slot[10];
    for(int i=0; i<=max_deadline; i++)
    {
        slot[i]=-1;
    }
    int maxp=0;
    int countJobs=0;
    for(int i=0; i<n; i++)
    {
        for(int j=deadline[i]; j>=0; j--)
        {
            if(slot[j]==-1)
            {
                result[j]=id[countJobs];
                countJobs++;
                slot[j]=i;
                maxp+=profit[i];
                break;
            }
        }
    }
    cout<<"JOB SEQUENCING: "<<endl;
    for(int i=1; i<=countJobs; i++)
    {
        cout<<result[i]<<"->";
    }
    cout<<endl;
    cout<<"MAX PROFIT: "<<endl;
    cout<<maxp<<endl;
}
int main()
{
    char id[10];
    int deadline[10];
    int profit[10];
     cout<<"Enter the number of ids: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the ids: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>id[i];
    }
    cout<<"Enter the deadlines: "<<endl;
    for(int i=0; i<n; i++)
    {
       cin>>deadline[i];
    }
    cout<<"Enter the profits: "<<endl;
    for(int i=0; i<n; i++)
    {
       cin>>profit[i];
    }
    cout << "IDS: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << id[i] << " ";
    }
    cout << endl;
    cout << "DEADLINES: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << deadline[i] << " ";
    }
    cout << endl;
    cout << "PROFITS: " << endl;
    for (int i = 0; i < n; i++)
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
    jS(id, deadline, profit, n);

    return 0;
}