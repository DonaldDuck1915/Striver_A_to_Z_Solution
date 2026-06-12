// #include <bits/stdc++.h>
// using namespace std;

// const int mod = 1000000007;

// class Solution {
// public:

//     int nmbrWays(int i, int j, bool isTrue, string &s) {

//         if (i > j) return 0;

//         if (i == j) {
//             if (isTrue)
//                 return (s[i] == 'T');
//             else
//                 return (s[i] == 'F');
//         }

//         int ways = 0;

//         for (int k = i + 1; k <= j - 1; k += 2) {

//             int LT = nmbrWays(i, k - 1, 1, s);
//             int LF = nmbrWays(i, k - 1, 0, s);

//             int RT = nmbrWays(k + 1, j, 1, s);
//             int RF = nmbrWays(k + 1, j, 0, s);

//             if (s[k] == '&') {

//                 if (isTrue)
//                     ways = (ways + (LT * RT) %mod)%mod;
//                 else
//                     ways =(((ways  + (LT * RF)%mod)%mod  + (LF * RT)%mod )%mod  + (LF * RF)%mod)%mod;
//             }

//             else if (s[k] == '|') {

//                 if (isTrue)
//                     ways = (((ways +(LT * RT) %mod)%mod + (LT * RF)%mod)%mod + (LF * RT)%mod)%mod;
//                 else
//                     ways = (ways + (LF * RF)%mod)%mod;
//             }

//             else if (s[k] == '^') {

//                 if (isTrue)
//                     ways = ((ways + (LT * RF)%mod)%mod + (LF * RT)%mod)%mod;
//                 else
//                     ways =((ways +  (LT * RT) %mod)%mod  + (LF * RF)%mod)%mod;
//             }
//         }

//         return ways;
//     }

//     int evaluateExp(string &s) {
//         int n= s.size();
//         return nmbrWays(0, n-1, 1, s);
//     }
// };

// int main() {

//     Solution sol;

//     string exp = "F|T&T";

//     cout << sol.evaluateExp(exp) << endl;

//     return 0;
// }
























#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

class Solution {
public:

    int nmbrWays(int i, int j, bool isTrue, string &s) {

        if (i > j) return 0;

        if (i == j) {
            if (isTrue)
                return (s[i] == 'T');
            else
                return (s[i] == 'F');
        }

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {

            int LT = nmbrWays(i, k - 1, 1, s);
            int LF = nmbrWays(i, k - 1, 0, s);

            int RT = nmbrWays(k + 1, j, 1, s);
            int RF = nmbrWays(k + 1, j, 0, s);

            if (s[k] == '&') {

                if (isTrue)
                    ways = (ways + (LT * RT) %mod)%mod;
                else
                    ways =(((ways  + (LT * RF)%mod)%mod  + (LF * RT)%mod )%mod  + (LF * RF)%mod)%mod;
            }

            else if (s[k] == '|') {

                if (isTrue)
                    ways = (((ways +(LT * RT) %mod)%mod + (LT * RF)%mod)%mod + (LF * RT)%mod)%mod;
                else
                    ways = (ways + (LF * RF)%mod)%mod;
            }

            else if (s[k] == '^') {

                if (isTrue)
                    ways = ((ways + (LT * RF)%mod)%mod + (LF * RT)%mod)%mod;
                else
                    ways =((ways +  (LT * RT) %mod)%mod  + (LF * RF)%mod)%mod;
            }
        }

        return ways;
    }

    int evaluateExp(string &s) {
        int n= s.size();
        return nmbrWays(0, n-1, 1, s);
    }
};

int main() {

    Solution sol;

    string exp = "F|T&T";

    cout << sol.evaluateExp(exp) << endl;

    return 0;
}