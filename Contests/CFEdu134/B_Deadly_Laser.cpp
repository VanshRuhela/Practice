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
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        if ((sy - d > 1 and sx + d < n) || (sx - d > 1 and sy + d < m))
            cout << m + n - 2;
        else
            cout << "-1";

        cout << "\n";
    }
    return 0;
}