#include<bits/stdc++.h>
using namespace std;


int maxSUM(vector<int> & arr, int n  ){

    if (n==0)return arr[0];
    if(n<0)return 0;

    int pick = arr[n] + maxSUM(arr, n-2);
    int non_pick= 0 + maxSUM(arr, n-1);

    return max(pick , non_pick);
}
int main(){

    vector<int> arr={1,2,3,1,3,5,8,1,9};
    int n = arr.size();

    int ans= maxSUM(arr,n-1);
    cout<<"maximmum sumof non adjacent elements : "<<ans<<endl;
    return 0;
}


























#include<bits/stdc++.h>
using namespace std;


int maxSUM(vector<int> & arr, vector<int> &dp, int n  ){

      if (n < 0) return 0;                 // no elements left
    if (n == 0) return arr[0];           // only one element
    if (dp[n] != -1) return dp[n];       // already computed

    int pick= arr[n]+ maxSUM(arr,dp,n-2);
    int non_pick= 0+ maxSUM(arr,dp,n-1);

    return dp[n]=max(pick,non_pick);
}

int main(){

    vector<int> arr={1,2,3,1,3,5,8,1,9};
    int n = arr.size();
    vector<int> dp(n,-1);

    int ans= maxSUM(arr,dp,n-1);
    cout<<"maximmum sumof non adjacent elements : "<<ans<<endl;
    return 0;
}


































#include<bits/stdc++.h>
using namespace std;
int  maxSUM(vector<int> & arr, vector<int> &dp, int n){
    dp[0]=arr[0];
    
    for(int i=1;i<n;i++){
        int pick=arr[i];
        
        if(i>1){
            pick+=dp[i-2];
        }
        int non_pick= dp[i-1];
        dp[i]=max(pick, non_pick);
    }
    return dp[n-1];
}


int main(){

    vector<int> arr={1,2,3,1,3,5,8,1,9};
    int n = arr.size();
    vector<int> dp(n);

    int ans= maxSUM(arr,dp,n);
    cout<<"maximmum sumof non adjacent elements : "<<ans<<endl;
    return 0;
}






































#include <bits/stdc++.h>
using namespace std;

int maxSUM(vector<int> &arr, int n) {
    if (n == 0) return arr[0];  // only one element

    int prev1 = arr[0];  // max sum till index 0
    int prev2 = 0;       // nothing before index 0
    int curr = prev1;

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1) pick += prev2;

        int non_pick = prev1;

        curr = max(pick, non_pick);

        // shift for next iteration
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    vector<int> arr = {1,2,3,1,3,5,8,1,9};
    int n = arr.size();

    int ans = maxSUM(arr, n);
    cout << "Maximum sum of non-adjacent elements: " << ans << endl;
    return 0;
}
