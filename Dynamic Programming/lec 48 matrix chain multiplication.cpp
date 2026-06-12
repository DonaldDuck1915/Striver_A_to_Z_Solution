// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find the minimum multiplication cost
//     int matrixChainOrder(vector<int>& arr, int i, int j) {
//       if(i==j)return 0;
//       int mini=1e9;
//       for(int k=i;k<j;k++){
//         int steps=arr[i-1]*arr[k]*arr[j]+matrixChainOrder(arr,i,k)+matrixChainOrder(arr,k+1,j);
//         mini=min(mini,steps);
//       }
//       return mini;
//     }
// };

// // Driver code
// int main() {
//     Solution sol;
//     vector<int> arr = {40, 20, 30, 10, 30}; 
//     int n = arr.size();

//     cout << "Minimum number of multiplications is: "
//          << sol.matrixChainOrder(arr, 1, n - 1) << endl;

//     return 0;
// }

























// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to find the minimum multiplication cost
    // int matrixChainOrder(vector<int>& arr,vector<vector<int>> &dp, int i, int j) {
    //   if(i==j)return 0;
    //   if(dp[i][j]!=-1)return dp[i][j];
    //   int mini=1e9;
    //   for(int k=i;k<j;k++){
    //     int steps=arr[i-1]*arr[k]*arr[j]+
    //                 matrixChainOrder(arr,dp,i,k)
    //                 +matrixChainOrder(arr,dp,k+1,j);
    //     mini=min(mini,steps);
    //   }
    //   return dp[i][j]=mini;
    // }
// };

// // Driver code
// int main() {
//     Solution sol;
//     vector<int> arr = {40, 20, 30, 10, 30}; 
//     int n = arr.size();
//     vector<vector<int>> dp(n,vector<int>(n,-1));

//     cout << "Minimum number of multiplications is: "
//          << sol.matrixChainOrder(arr, dp,1, n - 1) << endl;

//     return 0;
// }

















#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum multiplication cost
    int matrixChainOrder(vector<int>& arr,vector<vector<int>> &dp) {

        int n=arr.size();

        for(int i=1;i<n;i++)dp[i][i]=0;
        

        for(int i=n-1;i>=1; i--){
            for(int j=i+1;j<n;j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                    
                }
                dp[i][j]=mini;

            }
        }
        return dp[1][n-1];


      
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> arr = {10, 15, 20, 25}; 
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    cout << "Minimum number of multiplications is: "
         << sol.matrixChainOrder(arr, dp) << endl;

    return 0;
}
