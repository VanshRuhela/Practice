#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define re(i, a, n) for (int i = a; i <= n; ++i)
#define repr(i, a, n) for (int i = a; i >= n; --i)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define pb push_back
#define f first
#define s second
using namespace std;

vector<int> helper(unordered_map<int, vector<int>>& mp , int n) {
    vector<int> ans(n + 2, 0);
    for (auto x : mp) {
        int tot = 1;
        auto y = x.second;
        for (int i = 1; i < y.size(); i++) {
            bool flag = true;
            if ((y[i] - y[i - 1] - 1) % 2 != 0) {
                flag = false;
            }
            if(flag)
            tot++;
        }

        ans[x.first] = tot;
    }
    return ans;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 2];
        unordered_map<int, vector<int>> mp;
        rep(i, n) {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }

        auto ans = helper(mp, n);
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}