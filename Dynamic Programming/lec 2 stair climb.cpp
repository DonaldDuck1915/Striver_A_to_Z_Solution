#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 1 way to be on the 0th step (do nothing)

    for (int i = 1; i <= n; i++) {
        for (int step = 1; step <= m; step++) {
            if (i - step >= 0)
                dp[i] += dp[i - step];
        }
    }

    return dp[n];
}

int main() {
    int n, m;
    cout << "Enter number of stairs (n): ";
    cin >> n;
    cout << "Enter maximum steps allowed at a time (m): ";
    cin >> m;

    cout << "Total distinct ways to climb " << n << " stairs with steps up to " << m << ": " << climbStairs(n, m) << endl;

    return 0;
}























#include <bits/stdc++.h>
using namespace std;

int countWays(int n, vector<int>& steps) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // One way to stay at step 0

    for (int i = 1; i <= n; i++) {
        for (int step : steps) {
            if (i - step >= 0)
                dp[i] += dp[i - step];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    int k;
    cout << "Enter number of allowed steps: ";
    cin >> k;

    vector<int> steps(k);
    cout << "Enter the allowed step sizes: ";
    for (int i = 0; i < k; i++) {
        cin >> steps[i];
    }

    cout << "Total distinct ways to climb " << n << " stairs: " << countWays(n, steps) << endl;
    return 0;
}



























#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& steps, vector<int>& dp) {
    if (n == 0) return 1;   // one way (do nothing)
    if (n < 0) return 0;    // invalid path

    if (dp[n] != -1) return dp[n];

    int ways = 0;
    for (int step : steps) {
        ways += solve(n - step, steps, dp);
    }

    return dp[n] = ways;
}

int countWays(int n, vector<int>& steps) {
    vector<int> dp(n + 1, -1);
    return solve(n, steps, dp);
}

int main() {
    int n = 4;                        // number of stairs
    vector<int> steps = {1, 2};       // allowed step sizes

    cout << "Total distinct ways to climb " << n << " stairs: "
         << countWays(n, steps) << endl;

    return 0;
}
