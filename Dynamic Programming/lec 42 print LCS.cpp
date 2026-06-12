// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {

//         int n = nums.size();

//         if(n == 0) return 0;

//         vector<int> dp(n, 1);

//         int maxi = 1;

//         for(int index = 1; index < n; index++) {

//             for(int prev = 0; prev < index; prev++) {

//                 if(nums[prev] < nums[index]) {
//                     dp[index] = max(dp[index], dp[prev] + 1);
//                 }
//             }

//             maxi = max(maxi, dp[index]);
//         }

//         return maxi;
//     }
// };

// int main() {

//     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

//     Solution sol;

//     cout << "Length of LIS = "
//          << sol.lengthOfLIS(nums) << '\n';

//     return 0;
// }



























#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lengthOfLIS(vector<int>& arr, vector<int> & hp) {
        int n=  arr.size();
        if(n<=1)return arr;

        int  maxi=1;
        vector<int> dp(n,1);
        int  lastindex=0;
        for(int i=0;i<n;i++){
            hp[i]=i;
            for(int  prev=0;prev<i;prev++){
                if(arr[prev]<arr[i] && dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                    hp[i]=prev;
                }

            }
            if(maxi<dp[i]){
                maxi=dp[i];
                lastindex=i;
            }
        }
        vector<int >  temp;
        temp.push_back(arr[lastindex]);
        while(hp[lastindex]!=lastindex){
            lastindex=hp[lastindex];
            temp.push_back(arr[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

int main() {

    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18, 200};
    // vector<int> nums = {};
    int n=  nums.size();

    Solution sol;
    vector<int> hp(n);

  
    vector<int> ans= sol.lengthOfLIS(nums, hp) ;
    for(auto it : ans)cout<<it<<" ";
    cout<<endl;


    return 0;
}