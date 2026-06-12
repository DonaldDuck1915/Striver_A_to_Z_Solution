#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG_INF = -1e9;

ll maxCoin(ll index, ll target, vector<int>& arr) {

    // Base case
    if (index == 0) {
        if (target % arr[0] == 0)
            return target / arr[0];   // maximum coins using arr[0]
        return NEG_INF;               // impossible
    }

    // Option 1: do not take current coin
    ll not_take = maxCoin(index - 1, target, arr);

    // Option 2: take current coin (unbounded)
    ll take = NEG_INF;
    if (arr[index] <= target)
        take = 1 + maxCoin(index, target - arr[index], arr);

    return max(take, not_take);
}

int main() {
    ll target = 121;
    vector<int> arr = {9, 1, 1, 5, 11};
    int n = arr.size();

    ll ans = maxCoin(n - 1, target, arr);

    if (ans < 0)
        cout << -1;
    else
        cout << ans;

    return 0;
}
