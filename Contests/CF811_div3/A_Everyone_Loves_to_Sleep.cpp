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

void solve(int& cur , int& ans) {
    int x, y;
    cin >> x >> y;
    int curr = x * 60 + y, xx;
    if (curr < cur) {
        xx = (24 * 60) - (cur - curr);
    } else {
        xx = curr - cur;
    }
    ans = min(ans, xx);
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n, h, m;
        cin >> n >> h >> m;
        int cur = h * 60 + m, ans = 1e9;
        while (n--) {
            solve(cur , ans);
        }
        cout << ans / 60 << " " << ans % 60 << "\n";
    }
    return 0;
}