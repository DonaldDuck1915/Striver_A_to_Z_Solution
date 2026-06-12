#include <bits/stdc++.h>
using namespace std;

// Recursive function to check if subset sum equals target
bool subsetSumUtil(int ind, int target, vector<int>& arr) {
    // Base cases
    if (target == 0) return true;            // We found a subset
    if (ind == 0) return arr[0] == target;   // Only one element to consider

    // Choice 1: Do not take current element
    bool notTaken = subsetSumUtil(ind - 1, target, arr);

    // Choice 2: Take current element (if it does not exceed target)
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr);

    return notTaken || taken;
}

// Function to check if subset with sum 'k' exists
bool subsetSumToK(int n, int k, vector<int>& arr) {
    return subsetSumUtil(n - 1, k, arr);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}

// Time complexity = O(2^N)
// space complexity O(n);




// //////////////////////













// Memorization Approach




#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // If the target sum is 0, we have found a subset
    if (target == 0)
        return true;

    // If we have reached the first element in 'arr'
    if (ind == 0)
        return arr[0] == target;

    
    if (dp[ind][target] != -1)
        return dp[ind][target];
                    
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
bool subsetSumToK(int n, int k, vector<int>& arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}



























 

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // dp[i][t] = true if we can make sum 't' using first (i+1) elements
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {

            bool notTaken = dp[ind - 1][target]; 
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]]; 
            }
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}


























// space  optimise  approach 

#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int>& arr) {
    // dp[target] = true if we can form sum = target
    vector<bool> dp(k + 1, false);

    // Base case: sum 0 is always possible
    dp[0] = true;

    // Base case: first element alone can form sum arr[0]
    if (arr[0] <= k) dp[arr[0]] = true;

    // Process rest of the elements
    for (int ind = 1; ind < n; ind++) {
        // We must traverse backward to avoid reusing same element multiple times
        vector<bool> curr = dp;
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[target - arr[ind]];
            curr[target] = notTaken || taken;
        }
        dp = curr;
    }

    return dp[k];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}




































































#include <bits/stdc++.h>
using namespace std;

// Function to check if there is a subset of 'arr' with a sum equal to 'k'
vector<bool> subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);

    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        vector<bool> cur(k + 1, false);
            cur[0] = true;

        for (int target = 1; target <= k; target++) {
        
            bool notTaken = prev[target];          
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }
    return prev;
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    int n = arr.size();
    int sum=0;

    sum= accumulate(arr.begin(), arr.end(), 0);

    vector<bool> prev=subsetSumToK(n, sum, arr);
    int mini=INT_MAX;
    for (int i= 0 ; i<=sum/2 ;i++){
        if (prev[i]){
            mini=min(mini, abs(abs(sum -i)-abs(i)));
        }
    }
    cout<<mini;


    
}








#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr) {
    int n = arr.size();

    int total_min = 0, total_max = 0;
    for (int x : arr) {
        if (x < 0) total_min += x;
        else total_max += x;
    }

    int range = total_max - total_min + 1;
    int offset = -total_min;

    vector<vector<bool>> dp(n + 1, vector<bool>(range, false));
    dp[0][offset] = true; // sum = 0 achievable with no elements

    // Fill DP
    for (int i = 1; i <= n; i++) {
        for (int s = total_min; s <= total_max; s++) {
            if (dp[i - 1][s + offset]) {
                // not take
                dp[i][s + offset] = true;
                // take
                dp[i][s + arr[i - 1] + offset] = true;
            }
        }
    }

    int total_sum = accumulate(arr.begin(), arr.end(), 0);
    int mini = INT_MAX;

    for (int s = total_min; s <= total_max; s++) {
        if (dp[n][s + offset]) {
            int s1 = s;
            int s2 = total_sum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}

int main() {
    vector<int> arr = {2, -1, 0, 4, -2, -9};
    cout << minSubsetSumDifference(arr) << endl;
    return 0;
}
