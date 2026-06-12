#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& ds){
    if(n==1 || n==0)return 1;

    if(ds[n]!=-1)return ds[n];

    return ds[n]=f(n-1,ds)+f(n-2,ds);
}

int main(){
    int n= 9;
    vector<int> ds(n+1,-1);
    int fu=f(n,ds);
    cout<<fu;
}






















// Tabulation is a ‘bottom-up’ approach where we start from the base case and reach the final answer that we want.


Steps to convert Recursive Solution to Tabulation one.

Declare a dp[] array of size n+1.
First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n=5;
  vector<int> dp(n+1,-1);
  dp[0]= 0;
  dp[1]= 1;

  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}
// Time Complexity: O(N)
// Reason: We are running a simple iterative loop
// Space Complexity: O(N)
// Reason: We are using an external array of size ‘n+1’.


























#include <bits/stdc++.h>

using namespace std;


int main() {

  int n=5;
  
  int prev2 = 0;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return 0;
}
Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(1)
Reason: We are not using any extra space