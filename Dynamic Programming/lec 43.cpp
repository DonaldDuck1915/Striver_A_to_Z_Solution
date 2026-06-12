#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 10;
    vector<int> v(n);

    iota(v.begin()+4, v.end(), 1);

    for(int x : v) cout << x << " ";
    cout<<endl;


    vector<int> v2(n);

iota(v2.rbegin(), v2.rend(), 0);

for(int x : v2) cout << x << " ";
}