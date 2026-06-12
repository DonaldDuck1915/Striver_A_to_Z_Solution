#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack (ll index  , ll w_l , vector<ll> &weigh, vector<ll>& val){

    if(index ==0){
        if(weigh[0]<=w_l)
        return (w_l/weigh[0]) * val[0];
        return 0;
    }

    ll not_pick = 0 + knapsack(index-1,w_l, weigh, val);

    ll pick = INT_MIN;
    if(weigh[index]<=w_l){
        pick = val[index] + knapsack(index, w_l-weigh[index], weigh , val);
    }

    return max(pick , not_pick);
}

int main(){
    vector<ll> weigh= {2,4,6};
    vector<ll> val= {5, 11, 13};
    ll weight_limit = 6;
    ll n=weigh.size();
    ll ans=  knapsack(n-1, weight_limit , weigh , val );
    cout<<ans;
}























#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack (ll index  , ll w_l , vector<ll> &weigh, vector<ll>& val, vector<vector<ll>> &dp){

    if(index ==0){
        if(weigh[0]<=w_l)
        return (w_l/weigh[0]) * val[0];
        return 0;
    }

     if(dp[index][w_l]!= -1)
        return dp[index][w_l];

    ll not_pick = 0 + knapsack(index-1,w_l, weigh, val,dp);

    ll pick = INT_MIN;
    if(weigh[index]<=w_l){
        pick = val[index] + knapsack(index, w_l-weigh[index], weigh , val, dp);
    }

    return dp[index][w_l] =max(pick , not_pick);
}

int main(){
    vector<ll> weigh= {2,4,6};
    vector<ll> val= {5, 11, 13};
    ll weight_limit = 10;
    ll n=weigh.size();
    vector<vector<ll>> dp(n, vector<ll>(weight_limit+1,-1));
    ll ans=  knapsack(n-1, weight_limit , weigh , val , dp);
    cout<<ans;
}





















#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack ( ll w_l , vector<ll> &weigh, vector<ll>& val){

    ll n = weigh.size();
    vector<vector<ll>> dp(n, vector<ll>(w_l+1,0));

    for(ll W=weigh[0] ;W <=w_l ; W++ ){
        dp[0][W]= (W/weigh[0]) * val[0];
    }

    for(ll index= 1; index<n;index++){
        for(ll w= 0; w<=w_l; w++){

            ll not_pick = 0 + dp[index-1][w];

            ll pick = LLONG_MIN;
            if(weigh[index]<=w){
                pick = val[index] + dp[index][w-weigh[index]] ;
            }

           dp[index][w] =max(pick , not_pick);

        }

    }
    return dp[n-1][w_l];

}

int main(){
    vector<ll> weigh= {2,4,6};
    vector<ll> val= {5, 11, 13};
    ll weight_limit = 10;
    ll n=weigh.size();
    
    ll ans=  knapsack( weight_limit , weigh , val );
    cout<<ans;
}














#include <bits/stdc++.h>
using namespace std;

using ll= long long ;

ll knapsack ( ll w_l , vector<ll> &weigh, vector<ll>& val){

    ll n = weigh.size();
    vector<ll> prev(w_l+1,0);

    for(ll W=weigh[0] ;W <=w_l ; W++ ){
        prev[W]= (W/weigh[0]) * val[0];
    }

    for(ll index= 1; index<n;index++){
        vector<ll> cur(w_l+1,0);
        for(ll w= 0; w<=w_l; w++){

            ll not_pick = 0 + prev[w];

            ll pick = LLONG_MIN;
            if(weigh[index]<=w){
                pick = val[index] + cur[w-weigh[index]] ;
            }

           cur[w] =max(pick , not_pick);

        }
        prev = cur;
    }
    return prev[w_l];

}

int main(){
    vector<ll> weigh= {2,4,6};
    vector<ll> val= {5, 11, 13};
    ll weight_limit = 10;
    ll n=weigh.size();
    
    ll ans=  knapsack( weight_limit , weigh , val );
    cout<<ans;
}
