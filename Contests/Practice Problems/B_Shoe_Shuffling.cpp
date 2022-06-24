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
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n), p(n);
        rep(i, n) {
            cin >> v[i];
            p[i] = i + 1;
        }

        ll l = 0, r = 0;
        bool ans = true;

        while (r < n) {
            while (r < n - 1 && v[r] == v[r + 1])  // range with equal values
            {
                ++r;
                if (l == r)
                    ans = false;
                else
                    rotate(p.begin() + l, p.begin() + r,
                           p.begin() + r + 1);  // rotate right in range [l,r]
                l = r + 1;
                ++r;
            }
            if (ans) {
                rep(i, n) cout << p[i] << " ";
                cout << "\n";
            } else {
                cout << "-1\n";
            }
        }
        return 0;
    }
}