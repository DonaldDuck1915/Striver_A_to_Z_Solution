// #include <bits/stdc++.h>
// using namespace std;

// using ll= long long ;


// int coin(ll index , ll target ,vector<int> &arr ){

//     if( index==0){
//         if(target%arr[0]==0)return target/arr[0];
//         return 1e9;
//     }


//     int not_taken = 0+ coin(index-1 , target , arr);
//     int taken = 1e9;
//     if(arr[index]<=target ){
//         taken =1+ coin(index , target -arr[index], arr);
//     }
//     return min( taken , not_taken );
// }

// int  main(){
//     ll target = 121;
//     vector<int> arr= { 9, 1,1 ,5,11};
//     int n = arr.size();

//     ll ans= coin (n-1,target , arr);

//     if(ans>1e9)cout<<-1;
//     else{
//         cout<<ans;
//     }

// }


















// #include <bits/stdc++.h>
// using namespace std;

// using ll= long long ;


// int coin(ll index , ll target ,vector<int> &arr , vector<vector<int >> &dp ){
//     if(dp[index][target]!=-1)return dp[index][target];

//     if( index==0){
//         if(target%arr[0]==0)return target/arr[0];
//         return 1e9;
//     }


//     int not_taken = 0+ coin(index-1 , target , arr, dp);
//     int taken = 1e9;
//     if(arr[index]<=target ){
//         taken =1+ coin(index , target -arr[index], arr, dp);
//     }
//     return dp[index][target]=min( taken , not_taken );
// }

// int  main(){
//     ll target = 121;
//     vector<int> arr= { 9, 1,1 ,5,11};
//     int n = arr.size();

//     vector<vector<int >> dp(n , vector<int > (target+1,-1));

//     ll ans= coin (n-1,target , arr, dp);

//     if(ans>1e9)cout<<-1;
//     else{
//         cout<<ans;
//     }

// }














// #include <bits/stdc++.h>
// using namespace std;

// using ll= long long ;


// int coin(ll n , ll target ,vector<int> &arr , vector<vector<int >> &dp ){
    

//     for(int i=0;i<=target;i++){
//         if(i%arr[0]==0)dp[0][i]=i/arr[0];
//         else dp[0][i]=1e9;
//     }

//     for (int i=1;i<n;i++){
//         for( int j=0;j<=target ;j++){
//             int not_taken = 0+ dp[i-1][j];
//             int taken = 1e9;
//             if(arr[i]<=j ){
//                 taken =1+ dp[i][j-arr[i]];
//             }
//             dp[i][j]=min( taken , not_taken );

//         }

//     }
//     return dp[n-1][target];
    
// }

// int  main(){
//     ll target = 121;
//     vector<int> arr= { 9, 1,1 ,5,11};
//     int n = arr.size();

//     vector<vector<int >> dp(n , vector<int > (target+1,-1));

//     ll ans= coin (n,target , arr, dp);

//     if(ans>1e9)cout<<-1;
//     else{
//         cout<<ans;
//     }

// }
















#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int coin(ll index, ll target, vector<int> &arr) {


    vector<ll> dp(target+1,1e9);
    for (int t = 0; t <= target; t++) {
        if (t % arr[0] == 0)
            dp[t] = t / arr[0];
    }

    vector<ll> cur(target+1, 1e9);

    for (int ind = 1; ind <= index; ind++) {
        for (int T = 0; T <= target; T++) {
            ll not_take = dp[T]; // don’t take coin
            ll take = 1e9;
            if (arr[ind] <= T)
                take = 1 + cur[T - arr[ind]]; // take coin (unlimited)

            cur[T] = min(take, not_take);
        }
        dp=cur;
    }

    return dp[target];
}

int main() {
    ll target = 121;
    vector<int> arr = {9, 6, 5, 11};
    int n = arr.size();
    vector<vector<ll>> dp(n, vector<ll>(target + 1, 0));

    ll ans = coin(n - 1, target, arr);

    if (ans >= 1e9) // impossible
        cout << -1;
    else
        cout << ans;

    return 0;
}