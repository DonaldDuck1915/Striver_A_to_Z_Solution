
//  recursion way

#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

ll LIS(ll ind, ll prev, vector<ll>& arr) {

    if (ind == arr.size()) return 0;

    ll take = 0;

    if (prev == -1 || arr[ind] > arr[prev]) {
        take = 1 + LIS(ind + 1, ind, arr);
    }

    ll notTake = LIS(ind + 1, prev, arr);

    return max(take, notTake);
}

int main() {
    fastio

    vector<ll> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of LIS = " << LIS(0, -1, arr) << '\n';

    return 0;
}


































#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

ll solve(ll ind, ll prev, vector<ll>& arr, vector<vector<ll>>& dp) {

    if (ind == arr.size()) return 0;

    if (dp[ind][prev + 1] != -1)return dp[ind][prev + 1];

    ll take = 0;

    if (prev == -1 || arr[ind] > arr[prev]) {
        take = 1 + solve(ind + 1, ind, arr, dp);
    }

    ll notTake = solve(ind + 1, prev, arr, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int main() {
    fastio

    vector<ll> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    ll n = arr.size();

    vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));

    cout << "Length of LIS = "
         << solve(0, -1, arr, dp) << '\n';

    return 0;
}































// memorization  




#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

ll solve(ll ind, ll prev, vector<ll>& arr, vector<vector<ll>>& dp) {



    if (ind == arr.size()) return 0;

    if (dp[ind][prev + 1] != -1)return dp[ind][prev + 1];

    ll take = 0;

    if (prev == -1 || arr[ind] > arr[prev]) {
        take = 1 + solve(ind + 1, ind, arr, dp);
    }

    ll notTake = solve(ind + 1, prev, arr, dp);

    return dp[ind][prev + 1] = max(take, notTake);
}

int main() {
    fastio

    vector<ll> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    ll n = arr.size();

    vector<vector<ll>> dp(n, vector<ll>(n + 1, -1));

    cout << "Length of LIS = "
         << solve(0, -1, arr, dp) << '\n';

    return 0;
}





























//  Tabulation 




#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

int main() {
    fastio

    vector<ll> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    ll n = arr.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));

    for (ll ind = n - 1; ind >= 0; ind--) {

        for (ll prev = ind - 1; prev >= -1; prev--) {

                
        ll take = 0;

        if (prev == -1 || arr[ind] > arr[prev]) {
            take = 1 + dp[ind+1][ind+1] ;
        }

        ll notTake = dp[ind+1][prev+1];

        dp[ind][prev+1]=max(take ,notTake);

        }
    }

    cout << "Length of LIS = " << dp[0][0] << '\n';

    return 0;
}







































//  space optimisation


#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

int main() {
    fastio

    vector<ll> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    ll n = arr.size();


    vector<ll> ahead(n+1,0);
    vector<ll> cur(n+1,0);

    for (ll ind = n - 1; ind >= 0; ind--) {

        for (ll prev = ind - 1; prev >= -1; prev--) {

                
        ll take = 0;

        if (prev == -1 || arr[ind] > arr[prev]) {
            take = 1 + ahead[ind+1] ;
        }

        ll notTake = ahead[prev+1];

        cur[prev+1]=max(take ,notTake);

        }
        ahead =cur;
    }

    cout << "Length of LIS = " << ahead[0] << '\n';

    return 0;
}