// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
// #define ll long long
// #define all(x) (x).begin(), (x).end()
// class  solution{
//     public :
//     int minimumCutCost(vector<ll> &cuts, ll i, ll j){

//         if(i>j)return 0;
//         ll mini=INT_MAX;
//         for(ll k=i;k<=j;k++){
//             ll cost =cuts[j+1]-cuts[i-1] 
//                     + minimumCutCost(cuts , i,k-1)
//                     +minimumCutCost(cuts,k+1,j);
//             mini=min(mini,cost);
//         }
//         return mini;
//     }
// };



// int main() {
//     fastio
//     solution sol;
//     vector<ll> cuts{3,4,5,1};
//      ll  c=cuts.size();
//     cuts.insert(cuts.begin(), 0);
    
//     ll  n=7;
//     cuts.push_back(n);

//     sort(all(cuts));
   

//     cout<< sol.minimumCutCost(cuts,1,c);


    

//     return 0;
// }























// #include <bits/stdc++.h>
// using namespace std;

// #define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
// #define ll long long
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     ll minimumCutCost(vector<ll>& cuts, ll i, ll j,
//                       vector<vector<ll>>& dp) {

//         if (i > j) return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

        // ll mini = LLONG_MAX;

        // for (ll k = i; k <= j; k++) {

        //     ll cost = cuts[j + 1] - cuts[i - 1]
        //             + minimumCutCost(cuts, i, k - 1, dp)
        //             + minimumCutCost(cuts, k + 1, j, dp);

        //     mini = min(mini, cost);
        // }

        // return dp[i][j] = mini;
//     }
// };

// int main() {
//     fastio

//     Solution sol;

//     vector<ll> cuts{3, 4, 5, 1};

//     ll c = cuts.size();

//     cuts.insert(cuts.begin(), 0);

//     ll n = 7;
//     cuts.push_back(n);

//     sort(all(cuts));

//     vector<vector<ll>> dp(c + 1, vector<ll>(c + 1, -1));

//     cout << sol.minimumCutCost(cuts, 1, c, dp);

//     return 0;
// }

























#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    ll minimumCutCost(vector<ll>& cuts, ll i, ll j,ll c,
                      vector<vector<ll>>& dp) {

        for(ll i=c;i>=1;i--){
            for(ll j=i;j<=c;j++){

                        ll mini = LLONG_MAX;

                        for (ll k = i; k <= j; k++) {

                            ll cost = cuts[j + 1] - cuts[i - 1]
                                        + dp[i][k-1]+dp[k+1][j];

                            mini = min(mini, cost);
                        }

                        dp[i][j] = mini;

            }
        }
        return dp[1][c];
    }
};

int main() {
    fastio

    Solution sol;

    vector<ll> cuts{3, 4, 5, 1};

    ll c = cuts.size();

    cuts.insert(cuts.begin(), 0);

    ll n = 7;
    cuts.push_back(n);

    sort(all(cuts));

    vector<vector<ll>> dp(c + 2, vector<ll>(c + 2, 0));

    cout << sol.minimumCutCost(cuts, 1, c, c,dp);

    return 0;
}