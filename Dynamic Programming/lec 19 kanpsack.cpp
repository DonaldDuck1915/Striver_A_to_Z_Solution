
#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack (ll index  , ll w_l , vector<ll> &weigh, vector<ll>& val){

    if(index ==0){
        if(weigh[0]<=w_l)
        return val[0];
        return 0;
    }

    ll not_pick = 0 + knapsack(index-1,w_l, weigh, val);

    ll pick = INT_MIN;
    if(weigh[index]<=w_l){
        pick = val[index] + knapsack(index-1, w_l-weigh[index], weigh , val);
    }

    return max(pick , not_pick);
}

int main(){
    vector<ll> weigh= {5,2,5};
    vector<ll> val= {30, 40 , 60};
    ll weight_limit = 6;
    ll n=weigh.size();
    ll ans=  knapsack(n-1, weight_limit , weigh , val );
    cout<<ans;
}


























#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack (ll index  , ll w_l , vector<ll> &weigh, vector<ll>& val , vector<vector<ll>> &dp){

    if(index ==0){
        if(weigh[0]<=w_l)
        return val[0];
        return 0;
    }

    if(dp[index][w_l]!= -1){
        return dp[index][w_l];
    }

    ll not_pick = 0 + knapsack(index-1,w_l, weigh, val, dp);

    ll pick = INT_MIN;
    if(weigh[index]<=w_l){
        pick = val[index] + knapsack(index-1, w_l-weigh[index], weigh , val , dp);
    }

    return dp[index][w_l] = max(pick , not_pick);
}

int main(){
    vector<ll> weigh= {3,2,5};
    vector<ll> val= {30, 40 , 60};
    ll weight_limit = 6;
    ll n=weigh.size();

    vector<vector<ll>> dp(n, vector<ll>(weight_limit+1,-1));
    ll ans=  knapsack(n-1, weight_limit , weigh , val , dp);
    cout<<ans;
}





























#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll knapsack(ll w_l, vector<ll>& weigh, vector<ll>& val) {
    ll n = weigh.size();

    // DP table: dp[i][w] = max value using first i items with capacity w
    vector<vector<ll>> dp(n, vector<ll>(w_l + 1, 0));

    // Base case: fill first row
    for (ll W = weigh[0]; W <= w_l; W++) {
        dp[0][W] = val[0];
    }

    // Fill DP table
    for (ll ind = 1; ind < n; ind++) {
        for (ll w = 0; w <= w_l; w++) {

            ll not_pick = dp[ind - 1][w];
            ll pick = LLONG_MIN;

            if (weigh[ind] <= w) {
                pick = val[ind] + dp[ind - 1][w - weigh[ind]];
            }

            dp[ind][w] = max(pick, not_pick);
        }
    }

    return dp[n - 1][w_l];
}

int main() {
    vector<ll> weigh = {3, 2, 5};
    vector<ll> val = {30, 40, 60};
    ll weight_limit = 6;

    ll ans = knapsack(weight_limit, weigh, val);
    cout << ans << "\n";  // Expected output: 90

    return 0;
}





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());

        return helper(0,0, student, cookie);
    }

private:
    int helper(int s, int c, vector<int>& student, vector<int>& cookie) {
        int cnt=0;
        while (student.size()-1>=s && cookie.size()-1>=c){
            if(student[s]<=cookie[c]){
                cnt++;
                s++;
            }
            c++;
           
        }
        return cnt;
        
        
    }
};

int main() {
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 3};

    Solution solver;
    cout << "Maximum number of content students: "
         << solver.findContentChildren(student, cookie);

    return 0;
}
