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
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1)
            cout << 0 << "\n";
        else if (n == 1) {
            cout << m << "\n";
        } else if (m == 1) {
            cout << n << "\n";
        } else {
            int sm = min(n, m);
            int lr = max(n, m);
            int ans = 4 * (sm - 1) / 2 + lr;
            cout << ans << "\n";
        }
    }
    return 0;
}