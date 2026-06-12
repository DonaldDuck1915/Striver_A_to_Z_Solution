#include <bits/stdc++.h>
using namespace std;

void findSubsequences(int ind, vector<int> &arr, int target, 
                      vector<int> &current, vector<vector<int>> &result) {
    if (ind == arr.size()) {
        if (target == 0) result.push_back(current);
        return;
    }

    // Choice 1: Take this element (if it doesn’t exceed target)
    if (arr[ind] <= target) {
        current.push_back(arr[ind]);
        findSubsequences(ind + 1, arr, target - arr[ind], current, result);
        current.pop_back();
    }

    findSubsequences(ind + 1, arr, target, current, result);
}

vector<vector<int>> partitionSubsets(vector<int> &arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if (totalSum % 2 != 0) return {}; 

    int target = totalSum / 2;
    vector<int> current;
    vector<vector<int>> result;

    findSubsequences(0, arr, target, current, result);
    return result;
}

int main() {
    vector<int> arr = {9,6,3 };

    vector<vector<int>> subsets = partitionSubsets(arr);

    if (subsets.empty()) {
        cout << "No partition possible\n";
    } else {
        cout << "Valid subsets (each can form half of the partition):\n";
        for (auto &subset : subsets) {
            cout << "{ ";
            for (int x : subset) cout << x << " ";
            cout << "}\n";
        }
    }

    return 0;
}
