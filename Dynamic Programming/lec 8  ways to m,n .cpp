

#include <bits/stdc++.h>
using namespace std;

// Recursive function to count ways to reach cell (m, n)
int countWays(int m, int n) {
    // Base case: reached the starting point (0,0)
    if (m == 0 && n == 0) 
        return 1;

    // Out of bounds (invalid path)
    if (m < 0 || n < 0) 
        return 0;

    // Move left (decrease column) and up (decrease row)
    return countWays(m, n - 1) + countWays(m - 1, n);
}

int main() {
    int m = 3; // rows
    int n = 2; // columns

    // We want ways to reach (m, n) from (0,0)
    cout << "Number of ways to reach (" << m << ", " << n << "): " 
         << countWays(m-1, n-1) << endl;

    return 0;
}

























#include <bits/stdc++.h>
using namespace std;

// Recursive function to count the number of ways to reach (i, j) from (0, 0)
// in a grid of size m x n
int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    
    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    return dp[i][j] = up + left;
}

int countWays(int m, int n) {
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Call the utility function with the bottom-right cell as the starting point.
    return countWaysUtil(m - 1, n - 1, dp);
}

int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}























#include <bits/stdc++.h>
using namespace std;

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1)
// from the top-left cell (0, 0) in a grid of size m x n
int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
    
    for(int i = 0; i<m; i++){
        for(int j=0; j<n;j++){
            if(i==0 && j==0){
                dp[i][j]=1;
                continue;
            }
            int left=0;
            int up=0;
            if(i>0){
                up= dp[i-1][j];
            }
            if(j>0){
                left=dp[i][j-1];
            }
            dp[i][j]=up+left;
        }
    }
    return dp[m-1][n-1];
}
     

int countWays(int m, int n) {
    
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return countWaysUtil(m, n, dp);
}

int main() {
    int m = 3;
    int n = 2;

    // Call the countWays function and print the result.
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}























#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int m, int n) {
    vector<int> prev(n, 0);

    for (int i = 0; i < m; i++) {
        vector<int> current(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                current[j] = 1; // base case: starting point
            } else {
                int up = 0, left = 0;
                if (i > 0) up = prev[j];
                if (j > 0) left = current[j-1];
                current[j] = up + left;
            }
        }
        prev = current;
    }
    return prev[n-1];
}

// Wrapper function
int countWays(int m, int n) {
    return countWaysUtil(m, n);
}

int main() {
    int m = 10;
    int n = 10;

    cout << "Number of ways to reach (" << m-1 << ", " << n-1 << "): " 
         << countWays(m, n) << endl;

    return 0;
}
