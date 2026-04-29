#include <iostream>
#include <vector>
using namespace std;

// Function to check subset sum
bool canSum(vector<int> nums, int target)
{
    vector<bool> dp(target + 1, false);

    dp[0] = true;   // Sum 0 is always possible

    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];

        for (int j = target; j >= num; j--)
        {
            if (dp[j - num])
            {
                dp[j] = true;
            }
        }
    }

    return dp[target];
}

int main()
{
    vector<int> nums;
    int n, target, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        nums.push_back(value);
    }

    cout << "Enter target sum: ";
    cin >> target;

    if (canSum(nums, target))
    {
        cout << "Subset with sum " << target << " exists.";
    }
    else
    {
        cout << "No subset exists.";
    }

    return 0;
}
