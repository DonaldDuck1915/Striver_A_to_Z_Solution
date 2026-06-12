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
    vector<ll> arr = {3,5, 0,0, 3,1,4};
    ll ans = profit(0, 1, arr);
    cout << ans;
}





























// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll profit(ll index, int buy, vector<ll> &arr, vector<vector<ll>> dp) {
//     if (index == arr.size()) {
//         return 0;
//     }
//     if(dp[index][buy]!=-1)return dp[index][buy];

//     ll op1, op2;

//     if (buy) {
//         // Option 1: Buy today
//         op1 = -arr[index] + profit(index + 1, 0, arr,dp);
//         // Option 2: Skip today
//         op2 = 0 + profit(index + 1, 1, arr,dp);
//     } else {
//         // Option 1: Sell today
//         op1 = arr[index] + profit(index + 1, 1, arr, dp);
//         // Option 2: Skip today
//         op2 = 0 + profit(index + 1, 0, arr ,dp);
//     }

//     return dp[index][buy] = max(op1, op2);
// }

// int main() {
//     vector<ll> arr = {17, 21, 22, 11, 9, 15, 6};
//     vector<vector<ll>> dp(arr.size(),vector<ll> (2,-1));
//     ll ans = profit(0, 1, arr ,dp);
//     cout << ans;
// }






















// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll profit(vector<ll> &arr) {
//     ll n = arr.size();

//     vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

//     dp[n][0] = dp[n][1] = 0;

//     for (int index = n - 1; index >= 0; index--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             ll op1, op2;
//             if (buy) {
//                 // Option 1: Buy today
//                 op1 = -arr[index] + dp[index + 1][0];
//                 // Option 2: Skip today
//                 op2 = 0 + dp[index + 1][1];
//             } else {
//                 // Option 1: Sell today
//                 op1 = arr[index] + dp[index + 1][1];
//                 // Option 2: Skip today
//                 op2 = 0 + dp[index + 1][0];
//             }
//             dp[index][buy] = max(op1, op2);
//         }
//     }

//     return dp[0][1]; // ✅ must start with buy allowed
// }

// int main() {
//     vector<ll> arr = {17, 21, 22, 11, 9, 15, 6};
//     cout << profit(arr);
// }












































// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll profit(vector<ll> &arr) {
//     ll n = arr.size();

//     vector<ll> ahead(2,0),cur(2,0);

    

//     for (int index = n - 1; index >= 0; index--) {
//         for (int buy = 0; buy <= 1; buy++) {
//             ll op1, op2;
//             if (buy) {
//                 // Option 1: Buy today
//                 op1 = -arr[index] + ahead[0];
//                 // Option 2: Skip today
//                 op2 = 0 + ahead[1];
//             } else {
//                 // Option 1: Sell today
//                 op1 = arr[index] + ahead[1];
//                 // Option 2: Skip today
//                 op2 = 0 + ahead[0];
//             }
//             cur[buy] = max(op1, op2);
//         }
//         ahead=cur;
//     }

//     return ahead[1]; 
// }

// int main() {
//     vector<ll> arr = {17, 21, 22, 11, 9, 15, 6};
//     cout << profit(arr);
// }