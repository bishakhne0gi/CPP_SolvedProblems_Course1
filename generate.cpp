#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int result = nums.size();
    int i = 0;

    for (int num : nums)
    {
        result ^= num;
        result ^= i;
        i++;
    }

    return result;
}

int main()
{
    srand(time(0)); // Seed the random number generator with current time

    ofstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    int numTestCases = 10; // Change the number of test cases as needed

    inputFile << numTestCases << endl;

    for (int t = 0; t < numTestCases; t++)
    {
        int n = rand() % 10 + 1; // Generate a random 'n' between 1 and 10
        inputFile << n << endl;

        vector<int> nums(n);

        for (int i = 0; i < n; i++)
        {
            int num = rand() % 10000; // Generate random integers between 0 and 99
            inputFile << num << " ";
            nums[i] = num;
        }

        inputFile << endl;

        int ans = missingNumber(nums);

        // Write the answer to the output file
        outputFile << ans << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Test cases generated and saved to 'input.txt'." << endl;

    return 0;
}
