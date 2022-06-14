#include <bits/stdc++.h>
#define V 100
using namespace std;
int counter = 0;
void print(int n, int chessboard[V])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (chessboard[i] == j)
                cout<<"Q ";
            else
                cout<<"_ ";
        }
        cout <<endl;
    }
}

bool safePlace(int k, int i, int chessboard[V])
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (chessboard[j] == i || abs(j - k) == abs(chessboard[j] - i))
        {
            //if present in same in col or not
            return false;
        }
    }
    return true;
}

void nQueen(int k, int n, int chessboard[V])
{
    for (int i = 1; i <= n; i++)
    { // column traversal
        if (safePlace(k, i, chessboard)==true)
        {// k is the row
            chessboard[k] = i;
            if (k == n)
            {
                counter++;
                cout << "\n solution :" << counter << " " << endl;
                print(n, chessboard);
            }
            else
            {
                nQueen(k + 1, n, chessboard);
            }
        }
    }
}

int main()
{
    cout << "enters the rows of the chessboard : ";
    int n;
    cin >> n;
    int chessBoard[V];
    nQueen(1, n, chessBoard);
}