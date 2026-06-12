// #include <bits/stdc++.h>
// using namespace std;

// // Recursive function to calculate the maximum coins obtained
// int maxCoinsHelper(int i, int j, vector<int> &arr) {

//     if(i>j)return 0;

//     int coins =INT_MIN;
//     for(int k=i;k<=j;k++){
//         int coi=arr[i-1]* arr[k]*arr[j+1]+
//                     maxCoinsHelper(i,k-1,arr)+
//                     maxCoinsHelper(k+1,j,arr);
//         coins=max(coi,coins);
//     }
//     return coins;
   
// }

// // Function to calculate the maximum coins obtained
// int maxCoins(vector<int> &nums) {
//     int n = nums.size();
    
//     // Add 1 to the beginning and end of the nums array
//     nums.insert(nums.begin(), 1);
//     nums.push_back(1);
    
//     // Call the helper function to compute the maximum coins
//     return maxCoinsHelper(1, n, nums);
// }

// int main() {
//     vector<int> nums = {3, 1, 5, 8};
//     int maxCoinsResult = maxCoins(nums);
//     cout << "Maximum coins obtained: " << maxCoinsResult << "\n";
    
//     return 0;
// }



























// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int maxCoinsHelper(int i, int j, vector<int>& arr,
//                        vector<vector<int>>& dp) {

//         if (i > j) return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int coins = 0;

//         for (int k = i; k <= j; k++) {

//             int curr =
//                 arr[i - 1] * arr[k] * arr[j + 1]
//                 + maxCoinsHelper(i, k - 1, arr, dp)
//                 + maxCoinsHelper(k + 1, j, arr, dp);

//             coins = max(coins, curr);
//         }

//         return dp[i][j] = coins;
//     }

//     int maxCoins(vector<int>& nums) {

//         int n = nums.size();

//         nums.insert(nums.begin(), 1);
//         nums.push_back(1);

//         vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

//         return maxCoinsHelper(1, n, nums, dp);
//     }
// };

// int main() {

//     vector<int> nums = {3, 1, 5, 8};

//     Solution sol;

//     cout << sol.maxCoins(nums);

//     return 0;
// }






















#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {

            for (int j = i; j <= n; j++) {

                int coins = 0;

                for (int k = i; k <= j; k++) {

                    int curr =
                        nums[i - 1] * nums[k] * nums[j + 1]
                        + dp[i][k - 1]
                        + dp[k + 1][j];

                    coins = max(coins, curr);
                }

                dp[i][j] = coins;
            }
        }

        return dp[1][n];
    }
};

int main() {

    vector<int> nums = {3, 1, 5, 8};

    Solution sol;

    cout << sol.maxCoins(nums);

    return 0;
}

