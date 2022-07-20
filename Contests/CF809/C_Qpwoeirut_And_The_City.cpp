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



int32_t main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll a[n];
        rep(i, n) cin >> a[i];

        if (n % 2 != 0) { // odd case
            ll ans = 0;
            for (int i = 1; i < n - 1; i += 2)
                ans += max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
            cout << ans << "\n";
        } else {
            ll ans = 0, ans1 = 0;
            vector<ll> p(n / 2);
            vector<ll> q(n / 2);
            ll j = 1;
            for (int i = 1; i < n - 1; i += 2) {
                int res = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
                p[j] = p[j - 1] + res;
                j++;
            }
            j = 1;
            for (int i = 2; i < n - 1; i += 2) {
                int res = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0LL);
                q[j] = q[j - 1] + res;
                j++;
            }

            ans = INT_MAX;

            for (int i = 0; i < n / 2; i++) {
                ans = min(ans, p[i] + q[n / 2 - 1] - q[i]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}