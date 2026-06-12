#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int idx, vector<int>& arr, vector<int>& ds) {
    if (idx == arr.size()) {
        for (int x : ds)
            cout << x << " ";
        cout << "\n";
        return;
    }

    // Take the current element
    ds.push_back(arr[idx]);
    printSubsequences(idx + 1, arr, ds);

    // Not take the current element
    ds.pop_back();
    printSubsequences(idx + 1, arr, ds);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ds;

    printSubsequences(0, arr, ds);

    return 0;
}



















// #include <bits/stdc++.h>
// using namespace std;

// int countSubsequences(int idx, int n) {
//     if (idx == n) return 1;

//     int take = countSubsequences(idx + 1, n);
//     int notTake = countSubsequences(idx + 1, n);

//     return take + notTake;
// }

// int main() {
//     vector<int> v = {1, 2, 3};

//     cout << countSubsequences(0, v.size()) << endl;

//     return 0;
// }

















#include <bits/stdc++.h>
using namespace std;

int ans = 0;

bool isIncreasing(vector<int>& ds) {
    for (int i = 1; i < ds.size(); i++) {
        if (ds[i] <= ds[i - 1])
            return false;
    }
    return true;
}

void solve(int idx, vector<int>& arr, vector<int>& ds) {
    if (idx == arr.size()) {
        if (isIncreasing(ds))
            ans = max(ans, (int)ds.size());
        return;
    }

    // Take
    ds.push_back(arr[idx]);
    solve(idx + 1, arr, ds);

    // Not take
    ds.pop_back();
    solve(idx + 1, arr, ds);
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};

    vector<int> ds;
    solve(0, arr, ds);

    cout << "Length of LIS = " << ans << endl;
}