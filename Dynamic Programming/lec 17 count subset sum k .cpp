#include <bits/stdc++.h>
using namespace std;

int countSubseq(int ind , int target , vector<int > & arr ){
     if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2; // {} and {0}
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    int not_taken= countSubseq(ind-1,target , arr);
    int taken =0;
    if(arr[ind]<=target)
    taken= countSubseq(ind-1, target-arr[ind],arr);

    return taken + not_taken ;
}

int main() {
    vector<int> arr = {1, 4,0,0,0,5};
    int n = arr.size();
    int target= 5;

    cout << countSubseq(n-1, target , arr);
}














Memoization (Top-Down DP) Version


#include <bits/stdc++.h>
using namespace std;

int countSubseq(int ind , int target , vector<int > & arr, vector<vector<int>> &dp ){
     if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2; // {} and {0}
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];

    int not_taken= countSubseq(ind-1,target , arr,dp);
    int taken =0;
    if(arr[ind]<=target)
    taken= countSubseq(ind-1, target-arr[ind],arr,dp);

    return dp[ind][target]= taken + not_taken ;
}

int main() {
    vector<int> arr = { 1 ,4 ,0,0,0,5};
    int n = arr.size();
    int target= 5;
    vector<vector<int>> dp(n, vector<int>(target +1,-1));

    cout << countSubseq(n-1, target , arr,dp);
}




















#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Handle first element separately
    if (num[0] <= k) dp[0][num[0]] = 1;
    if (num[0] == 0) dp[0][0] = 2; // {} and {0}

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= k; target++) {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }
            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][k];
}

int main() {
    vector<int> arr = { 0,0,1,1,2,3};
    int dif= 1;
    int sum= 0;
    for(auto  it : arr)
    sum+=it;
    int k = (sum  + dif)/2 ;

    cout << "The number of subsets found are " << findWays(arr, k) << "\n";

    return 0;
}























// // not correct

// // ////////////////////////////////////





#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();

    vector<int> prev(k + 1, 0);

   

    if (num[0] == 0) {
        prev[0] = 2;  // {} and {0}
    } else {
         prev[0] = 1;
    }
    if(num[0]!=0 && num[0]<=k)prev[num[0]]=1;



    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(k + 1, 0);
        cur[0] = 1; 

        for (int target = 0; target <= k; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if (num[ind] <= target) {
                taken = prev[target - num[ind]];
            }
            cur[target] = notTaken + taken;
        }

        prev = cur;
    }

    return prev[k];
}

int main() {
    vector<int> arr = { 0,0,1,1,2,3};
    int dif= 1;
    int sum= 0;
    for(auto  it : arr)
    sum+=it;
    int k = (sum  + dif)/2 ;

    cout << "The number of subsets found are " << findWays(arr, k) << "\n";

    return 0;
}










































// Count Partitions with Given Difference


#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();

    vector<int> dp(k + 1, 0);

    dp[0] = 1;  // base case: empty subset

    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            // zero can either be picked or not → doubles all existing counts
            for (int t = 0; t <= k; t++) {
                dp[t] *= 2;
            }
        } else {
            // update in reverse to avoid reusing updated values in the same iteration
            for (int t = k; t >= num[i]; t--) {
                dp[t] += dp[t - num[i]];
            }
        }
    }

    return dp[k];
}

int main() {
    vector<int> arr = { 0,0,1,1,2,3};
    int dif= 1;
    int sum= 0;
    for(auto  it : arr)
    sum+=it;
    int k = (sum  + dif)/2 ;

    cout << "The number of subsets found are " << findWays(arr, k) << "\n";

    return 0;
}
