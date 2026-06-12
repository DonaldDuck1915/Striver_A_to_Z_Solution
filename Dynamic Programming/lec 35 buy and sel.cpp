#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum profit using brute force
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                
                int profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << obj.maxProfit(prices) << endl;  // Output: 5

    return 0;
}

































#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize minimum price to a very large number
        int minPrice = INT_MAX;

        // Initialize max profit to 0
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            // If current price is less than the minimum seen so far, update minPrice
            if (prices[i] < minPrice)
                minPrice = prices[i];

            
            int profit = prices[i] - minPrice;

            // Update maxProfit if the profit today is better than before
            if (profit > maxProfit)
                maxProfit = profit;
        }

        // Return the best profit found
        return maxProfit;
    }
};

int main() {
    Solution obj;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << obj.maxProfit(prices) << endl;
    return 0;
}


































#include <bits/stdc++.h>
using namespace std;
using ll= long long;
ll profit ( vector<ll> &arr){

    ll l=0;
    ll n= arr.size();
    ll prof=0;

    for(int i=0; i<n-1;i++){
        if(arr[l]<=arr[i+1]){
          prof=max(prof,arr[i+1]-arr[l]);
        }
        else{
            l=i+1;
        }
    }
    return prof;
}

int main(){
    vector<ll> arr ={7,1,5,3,6,4};
    
    ll ans = profit(arr);
    cout<<ans;

}





































#include <bits/stdc++.h>
using namespace std;
using ll= long long;
ll profit ( vector<ll> &arr){

    ll n= arr.size();
    ll mini=arr[0];
    ll maxprofit=0;

    for(int i= 1;i<n;i++){
        maxprofit= max(maxprofit ,  arr[i]-mini);
        mini= min(mini, arr[i]);
    }
    return maxprofit;

}

int main(){
    vector<ll> arr ={7,1,5,3,6,4};
    
    ll ans = profit(arr);
    cout<<ans;

}