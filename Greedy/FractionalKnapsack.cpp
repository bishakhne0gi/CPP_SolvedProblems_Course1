#include <bits/stdc++.h>
using namespace std;
double fractionalKnapsack(int w, double profit[], double weight[], double ratio[], int n)
{
    double current_weight = 0.0;
    double final_profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (current_weight + weight[i] <= w)
        {
            current_weight = current_weight + weight[i];
            final_profit = final_profit + profit[i];
        }
        else
        {
            double left = w - current_weight;
            final_profit = final_profit + (ratio[i] * left);
            break;
        }
    }
    return final_profit;
}
int main()
{
    double profit[7];
    // double profit[] = {10, 5, 15, 7, 6, 18, 3};
    double weight[7];
    // double weight[] = {2, 3, 5, 7, 1, 4, 1};
    int n = 7, w = 15;
    double ratio[7];
    double temp_profit = 0.0, temp_weight = 0.0, temp_ratio = 0.0;
    cout<<"Enter the profits: "<<endl;
    for(int i=0; i<n; i++)
    {
        int z;
        cin>>z;
        profit[i]=z;
    }

    cout<<"Enter the weights: "<<endl;
    for(int i=0; i<n; i++)
    {
        int z;
        cin>>z;
        weight[i]=z;
    }

    cout << "PROFITS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;
    cout << "WEIGHTS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << weight[i] << " ";
    }
    cout << endl;
    // Profit per weight ratio
    for (int i = 0; i < 7; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }
    cout << "RATIO OF PROFIT PER WEIGHT: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << ratio[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp_ratio = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp_ratio;

                temp_profit = profit[j];
                profit[j] = profit[i];
                profit[i] = temp_profit;

                temp_weight = weight[j];
                weight[j] = weight[i];
                weight[i] = temp_weight;
            }
        }
    }
    cout<<endl;
    cout<<endl;
    cout << "After Sorting in decreasing order: " << endl;

    cout << "PROFITS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << profit[i] << " ";
    }
    cout << endl;
    cout << "WEIGHTS: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << weight[i] << " ";
    }
    cout << endl;
    cout << "RATIO OF PROFIT PER WEIGHT: " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << ratio[i] << " ";
    }
    cout << endl;


    cout << "Final Maximum Profit: " << endl;
    cout << fractionalKnapsack(w, profit, weight, ratio, n) << endl;
    return 0;
}