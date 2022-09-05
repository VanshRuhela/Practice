#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> arr1(n);
    for (auto &ele : arr1) cin >> ele;

    vector<ll> arr2(n);
    for (auto &ele : arr2) cin >> ele;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i].first = arr1[i];
        vec[i].second = arr2[i];
    }
    for (int i = 1; i <= n; i++) {
        int j = i - 1;
        if (vec[j].first > vec[j].second) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vec[i % n].second < vec[i - 1].second - 1) {
            if (vec[i - 1].first < vec[i - 1].second) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}