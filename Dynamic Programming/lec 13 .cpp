 #include <bits/stdc++.h>
using namespace std;

// Function to find the maximum chocolates that can be collected recursively
int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
   if(j1<0 || j1>m || j2<0 || j2>=m)    return -1e9;

   if(i==n-1){
    if(j1==j2) return grid[i][j1];
    return grid[i][j1]+ grid[i][j2];
   }

   if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

   int maxi=INT_MIN;

   for(int d1=-1;d1<=1;d1++){
    for(int d2=-1;d2<=1;d2++){
        int ans;
        if(j1==j2) ans=grid[i][j1]+ maxChocoUtil(i+1,j1+d1,j2+d2,n,m, grid, dp);
        else { ans=grid[i][j1] + grid[i][j2]+ maxChocoUtil(i+1,j1+d1,j2+d2,n,m, grid, dp);
        }
        maxi=max(ans, maxi);
    }
   }
   return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Create a 3D DP array to store computed results
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}

int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}

// Time Complexity: O(N*M*M) * 9

// Reason: At max, there will be N*M*M calls of recursion to solve a new problem and in every call, two nested loops together run for 9 times.

// Space Complexity: O(N) + O(N*M*M)

// Reason: We are using a recursion stack space: O(N), where N is the path length and an external DP Array of size ‘N*M*M’.



































#include <bits/stdc++.h>
using namespace std;

// Class to solve Ninja and his friends using tabulation
class Solution {
public:
    int maximumChocolates(int n, int m, vector<vector<int>>& grid) {
        // 3D DP table
        vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, 0)));
        
        // Base case: last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
        
        // Fill DP table bottom-up
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e9;
                    int curr = (j1 == j2) ? grid[i][j1] 
                                          : grid[i][j1] + grid[i][j2];
                    // Try all 9 moves
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;
                            if (newJ1 >= 0 && newJ1 < m &&
                                newJ2 >= 0 && newJ2 < m) {
                                maxi = max(maxi, curr + 
                                           dp[i+1][newJ1][newJ2]);
                            } else {
                                maxi = max(maxi, (int)-1e9);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

// Driver code
int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };
    int n = grid.size(), m = grid[0].size();
    Solution obj;
    cout << obj.maximumChocolates(n, m, grid) << endl;
    return 0;
}




































#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {

    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));

    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2){
                front[j1][j2]=grid[n-1][j1];
            }
            else { front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];}
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1 =0 ; j1<m; j1++){
            for(int j2 =0; j2<m; j2++){
                int maxi= INT_MIN;

                for(int  d1 =-1; d1<=1;d1++){
                    for(int d2=-1; d2<=1;d2++){
                        int ans;

                        if(j1==j2) ans= grid[i][j1];
                        else  ans= grid[i][j2]+ grid[i][j1];

                        if(j1+d1<0 || j1+d1>=m || j2+d2<0 || j2+d2>=m){
                            ans+=-1e9;
                        }
                        else ans+= front[j1+d1][j2+d2];
                        maxi = max(maxi , ans);
                    }
                }
                cur[j1][j2]=maxi;
            }
        }
        front=cur;
    }
    return front[0][m-1];
    
}

int main() {
    // Define the grid as a 2D vector
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns

    // Call the maximumChocolates function and print the result
    cout << maximumChocolates(n, m, matrix);

    return 0;
}