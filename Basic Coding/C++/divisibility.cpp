#include <iostream>
using namespace std;

int main()
{
    int testCases, n, k, value;
    cin >> testCases; // Read the number of test cases

    while (testCases--)
    {
        cin >> n >> k; // Read the values of n and k for the current test case

        bool dp[k] = {false}; // Initialize the dp array with all elements set to false
        dp[0] = true; // Set the initial state where 0 is divisible by k

        for (int i = 0; i < n; i++) // Process each element
        {
            cin >> value; // Read the current element

            bool dpNext[k] = {false}; // Initialize the dpNext array with all elements set to false

            for (int j = 0; j < k; j++) // Iterate through the dp array
            {
                if (dp[j]) // If the current state is divisible by k
                {
                    for (int multiplier : {-1, 1}) // Try multiplying the current element by -1 and 1
                    {
                        int newIndex = (((j + multiplier * value) % k) + k) % k; // Calculate the new index
                        dpNext[newIndex] = true; // Update the dpNext array
                    }
                }
            }

            for (int j = 0; j < k; j++) // Copy the elements of dpNext to dp
            {
                dp[j] = dpNext[j];
            }
        }

        if (dp[0]) // Check if the final state is divisible by k
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }
    return 0;
}
