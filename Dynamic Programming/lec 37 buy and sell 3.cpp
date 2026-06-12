#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll profit(ll index, int buy, vector<ll> &arr , int cap ) {
    if (cap==0 || index==arr.size())return 0;
   
    

    ll op1, op2;

    if (buy) {
        // Option 1: Buy today
        op1 = -arr[index] + profit(index + 1, 0, arr, cap);
        // Option 2: Skip today
        op2 = 0 + profit(index + 1, 1, arr, cap);
    } else {
        // Option 1: Sell today   
        op1 = arr[index] + profit(index + 1, 1, arr , cap-1);
        // Option 2: Skip today
        op2 = 0 + profit(index + 1, 0, arr , cap);
    }

    return max(op1, op2);
}

int main() {
    vector<ll> arr = {3,5, 0,0, 3,1,4};
    ll ans = profit(0, 1, arr , 3);
    cout << ans;
}









     



















#include <bits/stdc++.h>
using namespace std;

class StockProfit {
public:
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap,
               vector<vector<vector<int>>>& dp) {

        if (ind == n || cap == 0)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;

        if (buy == 0) { // Can buy
            profit = max(
                getAns(Arr, n, ind + 1, 0, cap, dp),
                -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp)
            );
        }
        else { // Can sell
            profit = max(
                getAns(Arr, n, ind + 1, 1, cap, dp),
                Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp)
            );
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices, int n) {
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );

        return getAns(prices, n, 0, 0, 2, dp);
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    StockProfit obj;

    cout << "The maximum profit that can be generated is "
         << obj.maxProfit(prices, n);

    return 0;
}













































#include <bits/stdc++.h>
using namespace std;

class StockProfit {
public:
    int maxProfit(vector<int>& Arr, int n) {
        // DP table: dp[index][buy][cap]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        int op1 =INT_MIN, op2 =INT_MIN;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 1) { // Can buy
                        op1 = dp[ind + 1][1][cap];
                        op2= -Arr[ind] + dp[ind + 1][0][cap];

                        dp[ind][buy][cap] =max(op1,op2);
                    }
                    else { // Can sell
                        op1= dp[ind + 1][0][cap];
                        op2= Arr[ind] + dp[ind + 1][1][cap - 1];

                        dp[ind][buy][cap] =max(op1,op2);
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    StockProfit obj;

    cout << "The maximum profit that can be generated is "
         << obj.maxProfit(prices, n);

    return 0;
}






















































#include <bits/stdc++.h>
using namespace std;

class StockProfit {
public:
    int maxProfit(vector<int>& Arr, int n) {
        


        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        int op1 =INT_MIN, op2 =INT_MIN;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {

                    if (buy == 1) { // Can buy
                        op1 = ahead[1][cap];
                        op2= -Arr[ind] + ahead[0][cap];

                        cur[buy][cap] =max(op1,op2);
                    }
                    else { // Can sell
                        op1= ahead[0][cap];
                        op2= Arr[ind] + ahead[1][cap - 1];
                        
                        cur[buy][cap] =max(op1,op2);
                    }
                }
            }
            ahead=cur;
        }

        return ahead[1][2];
    }
};

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    StockProfit obj;

    cout << "The maximum profit that can be generated is "
         << obj.maxProfit(prices, n);

    return 0;
}


























