#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nmbroflongestincreasingSUBSEQ(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);


        int maxi = 1;
        for(int index = 1; index < n; index++) {

            for(int prev = 0; prev < index; prev++) {

                if(nums[prev] < nums[index] &&  dp[index]< dp[prev] + 1) {
                    dp[index] = (dp[prev] + 1);
                    cnt[index]=cnt[prev];
                }
                else if(nums[prev] < nums[index] &&  dp[index]== dp[prev] + 1){
                    cnt[index]+=cnt[prev];
                }
            }
            maxi = max(maxi, dp[index]);
        }

        int countt=0;

        for( int i=0;i<n;i++){
            if(dp[i]==maxi){
                countt+=cnt[i];
            }
        }

        return countt;
    }
};

int main() {

    vector<int> nums = {6,7,8,1,2,3};

    Solution sol;

    cout << "number  of LIS = "
         << sol.nmbroflongestincreasingSUBSEQ(nums) << '\n';

    return 0;
}
