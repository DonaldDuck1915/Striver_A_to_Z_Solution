#include <bits/stdc++.h>
using namespace std;

// Recursive function to compute minimum path sum
int countWays(int m, int n, vector<vector<int>>& grid) {
    // Out of bounds
    if (m < 0 || n < 0) 
        return INT_MAX;

    // Base case: starting cell
    if (m == 0 && n == 0) 
        return grid[0][0];

 int up = INT_MAX, left = INT_MAX;
    if (m > 0) up = grid[m][n] + countWays(m-1, n, grid);
    if (n > 0) left = grid[m][n] + countWays(m, n - 1, grid);

    

    return  min(left, up);
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    cout << "Minimum path sum: " 
         << countWays(m-1, n-1, grid) << endl;

    return 0;
}




























#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) return matrix[0][0];
    if (i < 0 || j < 0) return INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];

    int up = INT_MAX, left = INT_MAX;
    if (i > 0) up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    if (j > 0) left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    return dp[i][j] = min(up, left);
}

int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minSumPathUtil(n - 1, m - 1, matrix, dp);
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}




























#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += 1e9; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += 1e9; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
























#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum sum path from (0, 0) to (n-1, m-1) in the matrix
int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0); 

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); 
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; 
            else {
                
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; 
                else
                    up += 1e9; 
                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; 
                else
                    left += 1e9; 
                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        prev = temp; 
    }

    return prev[m - 1];
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}
