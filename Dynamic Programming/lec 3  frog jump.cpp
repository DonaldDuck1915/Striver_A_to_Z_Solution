#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &height) {
    
    if (n == 0) return 0;

    // Option 1: Jump from (n-1) to n
    int oneStep = frogJump(n - 1, height) + abs(height[n] - height[n - 1]);

    // Option 2: Jump from (n-2) to n (if possible)
    int twoStep = INT_MAX;
    if (n > 1)
        twoStep = frogJump(n - 2, height) + abs(height[n] - height[n - 2]);

    return min(oneStep, twoStep);
}

int main() {
    
    vector<int> height = {30,10,60 , 10 , 60 , 50};  
    int N = height.size();

    cout << "Minimum energy: " << frogJump(N - 1, height) << endl;

    return 0;
}






























#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &height, vector<int> & dp) {
    
    if (n == 0) return 0;
    if(dp[n]!=-1)return dp[n];
    int oneStep = frogJump(n - 1, height,dp) + abs(height[n] - height[n - 1]);
    int twoStep = INT_MAX;
    if (n > 1)
        twoStep = frogJump(n - 2, height,dp) + abs(height[n] - height[n - 2]);

    return dp[n]=min(oneStep, twoStep);
}



int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<"minimum energy  "<< frogJump(n-1,height,dp);
}






























#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &height, vector<int> &dp) {
    dp[0] = 0;  // Base case

    for (int i = 1; i < n; i++) {
        int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);

        int twoStep = INT_MAX;
        if (i > 1) {
            twoStep = dp[i - 2] + abs(height[i] - height[i - 2]);
        }

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n - 1];
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();
    vector<int> dp(n);

    cout << "Minimum energy = " << frogJump(n, height, dp) << endl;

    return 0;
}






































#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &height) {
    
    int twoStep = INT_MAX;
    int prev1=0;
    int prev2=0;
    int cnt=0;
    for (int i = 1; i < n; i++) {
        int oneStep = prev1 + abs(height[i] - height[i - 1]);
        if (i > 1) {
            twoStep = prev2 + abs(height[i] - height[i - 2]);
        }

         cnt= min(oneStep, twoStep);
         prev2=prev1 ;
         prev1 = cnt;
    }

    return cnt;
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();

    cout << "Minimum energy = " << frogJump(n, height) << endl;

    return 0;
}
