// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll profit(ll index, int buy, vector<ll> &arr) {
//     if (index >= arr.size()) {
//         return 0;
//     }

//     ll op1, op2;

//     if (buy) {
//         // Option 1: Buy today
//         op1 = -arr[index] + profit(index + 1, 0, arr);
//         // Option 2: Skip today
//         op2 = 0 + profit(index + 1, 1, arr);
//     } else {
//         // Option 1: Sell today   
//         op1 = arr[index] + profit(index + 2, 1, arr);
//         // Option 2: Skip today
//         op2 = 0 + profit(index + 1, 0, arr);
//     }

//     return max(op1, op2);
// }

// int main() {
//     vector<ll> arr = {3,5, 0, 3,1,4};
//     ll ans = profit(0, 1, arr);
//     cout << ans;
// }



























// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll profit(ll index, int buy, vector<ll> &arr, vector<vector<ll>> &dp) {

//     if (index >= arr.size())   return 0;

//     if (dp[index][buy] != -1)  return dp[index][buy];
    

//     ll op1, op2;

//     if (buy) {
//         // Option 1: Buy today
//         op1 = -arr[index] + profit(index + 1, 0, arr, dp);

//         // Option 2: Skip today
//         op2 = profit(index + 1, 1, arr, dp);
//     }
//     else {
//         // Option 1: Sell today and cooldown for 1 day
//         op1 = arr[index] + profit(index + 2, 1, arr, dp);

//         // Option 2: Skip today
//         op2 = profit(index + 1, 0, arr, dp);
//     }

//     return dp[index][buy] = max(op1, op2);
// }

// int main() {

//     vector<ll> arr = {3, 5, 0, 3, 1, 4};

//     vector<vector<ll>> dp(arr.size(), vector<ll>(2, -1));

//     ll ans = profit(0, 1, arr, dp);

//     cout << ans;

//     return 0;
// }










































// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {

//     vector<ll> arr = {3, 5, 0, 3, 1, 4};

//     int n = arr.size();

//     vector<vector<ll>> dp(n + 2, vector<ll>(2, 0));

//     for (int ind = n - 1; ind >= 0; ind--) {

//         for (int buy = 0; buy <= 1; buy++) {

//             ll op1, op2;

//             if (buy) {

//                 op1 = -arr[ind] + dp[ind + 1][0];
//                 op2 = dp[ind + 1][1];
//             }
//             else {

//                 op1 = arr[ind] + dp[ind + 2][1];
//                 op2 = dp[ind + 1][0];
//             }

//             dp[ind][buy] = max(op1, op2);
//         }
//     }

//     cout << dp[0][1];

//     return 0;
// }




































// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main() {

//     vector<ll> arr = {3, 5, 0, 3, 1, 4};

//     int n = arr.size();

//     vector<ll> front1(2, 0); // ind+1
//     vector<ll> front2(2, 0); // ind+2
//     vector<ll> cur(2, 0);

//     for (int ind = n - 1; ind >= 0; ind--) {

//         for (int buy = 0; buy <= 1; buy++) {

//             ll op1, op2;

//             if (buy) {

//                 op1 = -arr[ind] + front1[0];
//                 op2 = front1[1];
//             }
//             else {

//                 op1 = arr[ind] + front2[1];
//                 op2 = front1[0];
//             }

//             cur[buy] = max(op1, op2);
//         }

//         front2 = front1;
//         front1 = cur;
//     }

//     cout << front1[1];

//     return 0;
// }


















// //////////////////////





















#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll profit(ll index, int buy, vector<ll> &arr, int cap) {

    if (index >= arr.size() || cap == 0)
        return 0;

    ll op1, op2;

    if (buy) {

        op1 = -arr[index] + profit(index + 1, 0, arr, cap);

        op2 = profit(index + 1, 1, arr, cap);
    }
    else {

        op1 = arr[index] + profit(index + 2, 1, arr, cap - 1);

        op2 = profit(index + 1, 0, arr, cap);
    }

    return max(op1, op2);
}

int main() {

    vector<ll> arr = {3,5,0, 0,3,1,10};

    cout << profit(0, 1, arr, 2);

    return 0;
}





















#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll profit(ll index, int buy, vector<ll> &arr,
          int cap, vector<vector<vector<ll>>> &dp) {

    if (index >= arr.size() || cap == 0)
        return 0;

    if (dp[index][buy][cap] != -1)
        return dp[index][buy][cap];

    ll op1, op2;

    if (buy) {

        op1 = -arr[index] +
              profit(index + 1, 0, arr, cap, dp);

        op2 = profit(index + 1, 1, arr, cap, dp);
    }
    else {

        op1 = arr[index] +
              profit(index + 2, 1, arr, cap - 1, dp);

        op2 = profit(index + 1, 0, arr, cap, dp);
    }

    return dp[index][buy][cap] = max(op1, op2);
}

int main() {

    vector<ll> arr = {3,5,0,3,1,4};

    vector<vector<vector<ll>>> dp(
        arr.size(),
        vector<vector<ll>>(2, vector<ll>(3, -1))
    );

    cout << profit(0, 1, arr, 2, dp);
}




































#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    vector<ll> arr = {3,5,0,3,1,4};

    int n = arr.size();

    vector<vector<vector<ll>>> dp(
        n + 2,
        vector<vector<ll>>(2, vector<ll>(3, 0))
    );

    for (int ind = n - 1; ind >= 0; ind--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int cap = 1; cap <= 2; cap++) {

                ll op1, op2;

                if (buy) {

                    op1 = -arr[ind]
                          + dp[ind + 1][0][cap];

                    op2 = dp[ind + 1][1][cap];
                }
                else {

                    op1 = arr[ind]
                          + dp[ind + 2][1][cap - 1];

                    op2 = dp[ind + 1][0][cap];
                }

                dp[ind][buy][cap] = max(op1, op2);
            }
        }
    }

    cout << dp[0][1][2];
}






























#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    vector<ll> arr = {3,5,0,3,1,4};

    int n = arr.size();

    vector<vector<ll>> front1(2, vector<ll>(3, 0));
    vector<vector<ll>> front2(2, vector<ll>(3, 0));
    vector<vector<ll>> cur(2, vector<ll>(3, 0));

   
    for (int ind = n - 1; ind >= 0; ind--) {

        for (int buy = 0; buy <= 1; buy++) {

            for (int cap = 1; cap <= 2; cap++) {

                ll op1, op2;

                if (buy) {

                    op1 = -arr[ind]  + front1[0][cap];

                    op2 = front1[1][cap];
                }
                else {

                    op1 = arr[ind]
                          + front2[1][cap - 1];

                    op2 = front1[0][cap];
                }

                cur[buy][cap] = max(op1, op2);
            }
        }

        front2 = front1;
        front1 = cur;
    }

    cout << front1[1][2];
}