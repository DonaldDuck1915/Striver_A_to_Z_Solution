// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// private:

//     bool ispalindrome(string &s, int i, int j) {
//         while (i < j) {
//             if (s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     int minCutsHelper(string &s, int i, int n) {

//         if (i == n || ispalindrome(s,i,n-1)) return 0;

//         int min_cost = INT_MAX;

//         for (int j = i; j < n; j++) {

//             if (ispalindrome(s, i, j)) {

//                 int cuts = 1 + minCutsHelper(s, j + 1, n);

//                 min_cost = min(min_cost, cuts);
//             }
//         }

//         return min_cost;
//     }

// public:

//     int minCut(string s) {

//         int n = s.size();

        
//         return minCutsHelper(s, 0, n) ;
//     }
// };

// int main() {

//     string s = "abcd";

//     Solution sol;

//     cout << "Minimum cuts needed: "
//          << sol.minCut(s) << "\n";

//     return 0;
// }
























// memoization




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCutsHelper(string &s, int i, int n ,vector<int> &dp) {

        if (i == n || ispalindrome(s,i,n-1)) return 0;

        if(dp[i]!=-1)return dp[i];

        int min_cost = INT_MAX;

        for (int j = i; j < n; j++) {

            if (ispalindrome(s, i, j)) {

                int cuts = 1 + minCutsHelper(s, j + 1, n, dp);

                min_cost = min(min_cost, cuts);
            }
        }

        return dp[i]=min_cost;
    }

public:

    int minCut(string s) {

        int n = s.size();
        vector<int> dp(n,-1);

        
        return minCutsHelper(s, 0, n, dp) ;
    }
};

int main() {

    string s = "abced";

    Solution sol;

    cout << "Minimum cuts needed: "
         << sol.minCut(s) << "\n";

    return 0;
}

























//  tabulation



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    bool ispalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    
public:

    int minCut(string s) {

        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int  i=n-1;i>=0;i--){
             int min_cost = INT_MAX;
            for (int j = i; j < n; j++) {

                if (ispalindrome(s, i, j)) {

                    int cuts = 1 + dp[j + 1];

                    min_cost = min(min_cost, cuts);
                }
            }
            dp[i]=min_cost;


       
        }

        
        return dp[0] ;
    }
};

int main() {

    string s = "abced";

    Solution sol;

    cout << "Minimum cuts needed: "
         << sol.minCut(s) << "\n";

    return 0;
}