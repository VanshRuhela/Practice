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
using namespace std;
int main() {
    fast_cin();
    int n, m;
    cin >> n >> m;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<pair<ll, ll> > v;
    rep(i, m) {
        int s, t;
        cin >> s >> t;
        v.push_back({s, t});
    }

    ll pre[n + 1];
    ll suff[n + 1];
    pre[1] = 0;
    suff[n] = 0;

    for (int i = 2; i <= n; i++) {
        int val = 0;
        if (a[i - 1] > a[i]) val = a[i - 1] - a[i];
        pre[i] = pre[i - 1] + val;
        // cout << "pre #" << i << " " << pre[i] << "\n";
    }

    for (int i = n - 1; i > 0; i--) {
        int val = 0;
        if (a[i + 1] > a[i]) val = a[i + 1] - a[i];
        suff[i] = suff[i +1] + val;
        // cout << "pre #" << i << " " << suff[i] << "\n";

    }

    for (int i = 0; i < v.size(); i++) {
        ll p = v[i].first;
        ll q = v[i].second;

        if (p > q)
            cout << abs(suff[p] - suff[q]) << endl;
        else
            cout << abs(pre[q] - pre[p]) << endl;
    }

    return 0;
}