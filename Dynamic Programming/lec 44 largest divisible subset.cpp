// // length of longest divisible  subset

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int longestDivisibleSubset(vector<int>& nums) {

//         int n = nums.size();

//         if(n == 0) return 0;

//         vector<int> dp(n, 1);

//         int maxi = 1;

//         for(int index = 0; index < n; index++) {

//             for(int prev = 0; prev < index; prev++) {

//                 if(nums[index]%nums[prev]==0) {
//                     dp[index] = max(dp[index], dp[prev] + 1);
//                 }
//             }

//             maxi = max(maxi, dp[index]);
//         }
//         return maxi;
//     }
// };

// int main() {

//     vector<int> nums = {1, 2 ,4, 7,  6, 8, 16, 64, 20};
//     sort(nums.begin(),nums.end());

//     Solution sol;

//     cout << "Length of LDS = "
//          << sol.longestDivisibleSubset(nums) << '\n';

//     return 0;
// }



























#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestdivisiblesubset(vector<int>& arr, vector<int> & hp) {
        int n=  arr.size();
        if(n<=1)return arr;

        int  maxi=1;
        vector<int> dp(n,1);
        int  lastindex=0;
        for(int i=0;i<n;i++){
            hp[i]=i;
            for(int  prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && dp[prev]+1>dp[i]){
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

    vector<int> nums = {1, 2 ,4, 7,  6, 8, 16, 64, 20};
    int n=  nums.size();
    sort(nums.begin(),nums.end());

    Solution sol;
    vector<int> hp(n);

  
    vector<int> ans= sol.longestdivisiblesubset(nums, hp) ;
    for(auto it : ans)cout<<it<<" ";
    cout<<endl;


    return 0;
}

















