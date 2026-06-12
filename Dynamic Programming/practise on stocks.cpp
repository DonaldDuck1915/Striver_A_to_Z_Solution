
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxprof=0;

        int n = prices.size();

        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            
            mini=min(mini, prices[i]);

            maxprof=max(maxprof, prices[i]-mini);
        }
        return maxprof;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;
    return 0;
}






























#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll profit(ll index, int buy, vector<ll> &arr) {
    if (index == arr.size()) {
        return 0;
    }

    ll op1, op2;

    if (buy) {
        // Option 1: Buy today
        op1 = -arr[index] + profit(index + 1, 0, arr);
        // Option 2: Skip today
        op2 = 0 + profit(index + 1, 1, arr);
    } else {
        // Option 1: Sell today   
        op1 = arr[index] + profit(index + 1, 1, arr);
        // Option 2: Skip today
        op2 = 0 + profit(index + 1, 0, arr);
    }

    return max(op1, op2);
}

int main() {
    vector<ll> arr = {17, 21, 22, 11, 9, 15, 6};
    ll ans = profit(0, 1, arr);
    cout << ans;
}






















