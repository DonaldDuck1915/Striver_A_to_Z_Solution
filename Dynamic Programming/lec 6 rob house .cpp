
#include <bits/stdc++.h>
using namespace std;

int maxROB(vector<int> &arr, int n) {
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

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1 (arr.begin()+1,arr.end());
    vector<int> arr2 (arr.begin(),arr.end()-1);
    
    
    if(n==1)
       return arr[0];

    long long int ans1 = maxROB(arr1,arr1.size());
    long long int ans2 = maxROB(arr2, arr2.size());
    
    return max(ans1,ans2);
}

int main() {
    vector<int> arr = {1,5,2,1,6};
    int n = arr.size();

    int ans = robStreet(n , arr);
    cout << "Maximum sum of non-adjacent elements: " << ans << endl;
    return 0;
}
