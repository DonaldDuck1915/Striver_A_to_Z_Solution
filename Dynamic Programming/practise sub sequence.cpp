#include <bits/stdc++.h>
using namespace std;


bool subsetSumUtil(int ind, int target, vector<int>& arr) {

    if(target==0)return true ;
    if(ind==0)return arr[0]==target  ;

    bool not_taken=subsetSumUtil(ind-1,target  , arr);
    bool  taken =false;

    if(arr[ind]<=target){
        taken = subsetSumUtil(ind-1 ,target-arr[ind],arr);
    }
    return taken || not_taken ;
    
}

// Function to check if subset with sum 'k' exists
bool subsetSumToK(int n, int k, vector<int>& arr) {
    return subsetSumUtil(n - 1, k, arr);
}

int main() {
    vector<int> arr = {1, 2, 3, 6};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}


























#include <bits/stdc++.h>
using namespace std;


bool subsetSumUtil(int ind, int target, vector<int>& arr , vector<vector<int>> &dp) {

    if(target==0)return true ;
    if(ind==0)return arr[0]==target  ;
    if(dp[ind][target]!=-1)return dp[ind][target];

    bool not_taken=subsetSumUtil(ind-1,target  , arr ,dp);
    bool  taken =false;

    if(arr[ind]<=target){
        taken = subsetSumUtil(ind-1 ,target-arr[ind],arr  ,dp);
    }
    return dp[ind][target]= taken || not_taken ;
    
}

// Function to check if subset with sum 'k' exists
bool subsetSumToK(int n, int k, vector<int>& arr) {

    vector<vector<int>> dp(n , vector<int >(k+1,-1));
    return subsetSumUtil(n - 1, k, arr  ,dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 6};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}





















#include <bits/stdc++.h>
using namespace std;


bool subsetSumUtil(int n, int target, vector<int>& arr , vector<vector<int>> &dp) {


    for(int i =0;i< n;i++){
        dp[i][0]=true ;
    }
    if(arr[0] <= target)dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int j =1;j<=target;j++){

            bool not_taken=dp[i-1][target];
            bool  taken =false;

            if(arr[i]<=target){
                taken = dp[i-1][target-arr[i]];
            }
            dp[i][target]= taken || not_taken ;

        }
    }
    return dp[n-1][target];

    
    
}

// Function to check if subset with sum 'k' exists
bool subsetSumToK(int n, int k, vector<int>& arr) {

    vector<vector<int>> dp(n , vector<int >(k+1,-1));
    return subsetSumUtil(n , k, arr  ,dp);
}

int main() {
    vector<int> arr = {1, 2, 3, 6};
    int k = 4;
    int n = arr.size();

    if (subsetSumToK(n, k, arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}











#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {

    vector<int> arr = {1,2,3,4};

    int sum = accumulate(arr.begin(), arr.end(), 0);

    cout << sum;
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
    vector<int> arr = {3, 6 , 7 , 11};
    int n = arr.size();
    int sum=0;

    sum= accumulate(arr.begin(), arr.end(), 0);

    vector<bool> prev=subsetSumToK(n, sum, arr);
    int mini=INT_MAX;
    for (int i= 0 ; i<=sum/2 ;i++){
        cout<<prev[i]<<" ";
        if (prev[i]){
            mini=min(mini, abs(abs(sum -i)-abs(i)));
        }
    }
    cout<<endl;
    cout<<mini;
    cout<<endl;

    bool ok=0 ;
    cout<<boolalpha<<true;


    
}
