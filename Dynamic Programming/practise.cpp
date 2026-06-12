#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum chocolates recursively
int maxChocoUtil(int i, int j1, int j2,int n, int m,
                 vector<vector<int>> &grid) {

    // Out of bounds
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    // Base case: last row
    if(i == n - 1) {

        // Both robots at same cell
        if(j1 == j2)
            return grid[i][j1];

        // Different cells
        return grid[i][j1] + grid[i][j2];
    }

    int maxi = INT_MIN;

    // Explore all 9 possible moves
    for(int d1 = -1; d1 <= 1; d1++) {

        for(int d2 = -1; d2 <= 1; d2++) {

            int ans;

            // Same cell
            if(j1 == j2)
                ans = grid[i][j1] +
                      maxChocoUtil(i + 1,
                                   j1 + d1,
                                   j2 + d2,
                                   n, m, grid);

            // Different cells
            else
                ans = grid[i][j1] + grid[i][j2] +
                      maxChocoUtil(i + 1,
                                   j1 + d1,
                                   j2 + d2,
                                   n, m, grid);

            maxi = max(maxi, ans);
        }
    }

    return maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {

    return maxChocoUtil(0, 0, m - 1, n, m, grid);
}

int main() {

    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << maximumChocolates(n, m, matrix);

    return 0;
}