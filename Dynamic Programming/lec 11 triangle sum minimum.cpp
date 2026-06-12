class Solution {
public:
    int Min(int i , int j ,int n,vector<vector<int>>& triangle){
        if(i==n-1)return triangle[i][j];

        int d1 = triangle[i][j]+ Min(i+1,j,n, triangle);
        int d2 = triangle[i][j]+ Min(i+1,j+1,n, triangle);
        
        return min(d1,d2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return Min(0,0,n,triangle);
    }
};


 
















class Solution {
public:
    int Min(int i , int j ,int n,vector<vector<int>>&dp ,vector<vector<int>>& triangle){
        if(dp[i][j]!=-1)return dp[i][j];

        if(i==n-1)return triangle[i][j];

        int d1 = triangle[i][j]+ Min(i+1,j,n, dp ,triangle);
        int d2 = triangle[i][j]+ Min(i+1,j+1,n,dp,  triangle);
        
        return dp[i][j]=min(d1,d2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return Min(0,0,n,dp,triangle);
    }
};


























#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum path sum in the given triangle using dynamic programming
int minimumPathSum(vector<vector<int> > &triangle, int n) {
    
    vector<vector<int> > dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

int main() {
    // Define the triangle as a 2D vector
    vector<vector<int> > triangle{{1},
                                   {2, 3},
                                   {3, 6, 7},
                                   {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}





















#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];      
            cur[j] = min(down, diagonal);
        }
        front = cur;
    }
    return front[0];
}

int main() {
   
    vector<vector<int>> triangle{{1},
                                  {2, 3},
                                  {3, 6, 7},
                                  {8, 9, 6, 10}};

    // Get the number of rows in the triangle
    int n = triangle.size();

    // Call the minimumPathSum function and print the result
    cout << minimumPathSum(triangle, n);

    return 0;
}