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
#define mp make_pair
#define f first
#define s second
#define int long long int
using namespace std;

void helper(vector<pair<int , int>> &val , vector<int> &arr , map<int , int> &freq , map<int , vector<int>> &adj) {
    int ans = INT_MAX;
    for (auto i : val) {
        if (freq.find(i.second) != freq.end()) {
            if (freq[i.second] % 2) {
                ans = min(ans, i.first);
            } else {
                for (auto j : adj[i.second]) {
                    if (freq[j] % 2 == 0) {
                        ans = min(ans, i.first + arr[j - 1]);
                    }
                }
            }
        }
    }
    cout<<ans <<"\n";
}

int32_t main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<int> arr(n);
        vector<pair<int, int>> val;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            arr[i] = k;
            val.push_back({k, i + 1});
        }

        map<int, vector<int>> adj;
        map<int, int> freq;
        rep(i, m) {
            int x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
            freq[x]++;
            freq[y]++;
        }

        if (m % 2 == 0) {
            cout << "0\n";
            continue;
        }

        sort(val.begin(), val.end());

        helper(val, arr, freq,adj);
    }
    return 0;
}
