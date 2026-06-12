#include <bits/stdc++.h>
using namespace std;

using ll= long long ;


int coin(ll index , ll target ,vector<int> &arr ){

    if(index==0){
        if(target%arr[0]== 0)return target / arr[0];
        return 1e9;
    }

    ll  not_take= 0+ coin(index-1, target , arr);
    ll take = 1e9;
    if(arr[index]<=target )
    take = 1 + coin(index, target - arr[index], arr);

    return min(take , not_take);
}

int  main(){
    ll target = 121;
    vector<int> arr= { 9, 1,1 ,5,11};
    int n = arr.size();

    ll ans= coin (n-1,target , arr);

    if(ans>1e9)cout<<-1;
    else{
        cout<<ans;
    }

}
























#include <bits/stdc++.h>
using namespace std;

using ll= long long ;


int coin(ll index , ll target ,vector<int> &arr,  vector<vector<ll>>& dp ){

    if(index==0){
        if(target%arr[0]== 0)return target / arr[0];
        return 1e9;
    }
    if(dp[index][target]!=-1)return dp[index][target];

    ll  not_take= 0+ coin(index-1, target , arr, dp);
    ll take = 1e9;
    if(arr[index]<=target )
    take = 1 + coin(index, target - arr[index], arr, dp);

    return dp[index][target]= min(take , not_take);
}

int  main(){
    ll target = 11;
    vector<int> arr= { 9, 6,5,1};
    int n = arr.size();
    vector<vector<ll>> dp (n, vector<ll> (target+1,-1));

    ll ans= coin (n-1,target , arr, dp);

    if(ans>1e9)cout<<-1;
    else{
        cout<<ans;
    }

}



























#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int coin(ll index, ll target, vector<int> &arr, vector<vector<ll>> &dp) {
    // Base case: first coin
    for (int t = 0; t <= target; t++) {
        if (t % arr[0] == 0)
            dp[0][t] = t / arr[0];
        else
            dp[0][t] = 1e9; // large value = impossible
    }

    // Fill DP table
    for (int ind = 1; ind <= index; ind++) {
        for (int T = 0; T <= target; T++) {
            ll not_take = dp[ind - 1][T]; // don’t take coin
            ll take = 1e9;
            if (arr[ind] <= T)
                take = 1 + dp[ind][T - arr[ind]]; // take coin (unlimited)

            dp[ind][T] = min(take, not_take);
        }
    }

    return dp[index][target];
}

int main() {
    ll target = 11;
    vector<int> arr = {9, 6, 5, 1};
    int n = arr.size();
    vector<vector<ll>> dp(n, vector<ll>(target + 1, 0));

    ll ans = coin(n - 1, target, arr, dp);

    if (ans >= 1e9) // impossible
        cout << -1;
    else
        cout << ans;

    return 0;
}








































#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int coin(ll index, ll target, vector<int> &arr) {
    vector<ll> prev(target+1,0);
    vector<ll> cur(target+1,0);

    for (int t = 0; t <= target; t++) {
        if (t % arr[0] == 0)
            prev[t] = t / arr[0];
        else
            prev[t] = 1e9; 
    }

    for (int ind = 1; ind <= index; ind++) {
        for (int T = 0; T <= target; T++) {
            ll not_take = prev[T]; // don’t take coin
            
            ll take = 1e9;
            if (arr[ind] <= T)
                take = 1 + cur[T - arr[ind]]; // take coin (unlimited)

            cur[T] = min(take, not_take);
        }
        prev= cur;
    }

    return prev[target];
}

int main() {
    ll target = 11;
    vector<int> arr = {9, 6, 5, 1};
    int n = arr.size();
    vector<vector<ll>> dp(n, vector<ll>(target + 1, 0));

    ll ans = coin(n - 1, target, arr);

    if (ans >= 1e9) // impossible
        cout << -1;
    else
        cout << ans;

    return 0;
}
