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

void solve() {
    int n;
    cin >> n;
    if (n == 5) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    if (n % 2 != 0) {
        for (int i = 1; i <= 3; i++) cout << i << " ";
        for (int i = 4; i <= n - 2; i += 2) cout << i + 1 << " " << i << " ";

    } else {
        for (int i = n - 2; i >= 1; i--) {
            cout << i << " ";
        }
    }
    cout << n - 1 << " " << n << "\n";
}
int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}