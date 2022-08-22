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
    long long int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;

    for (int i = 1; i <= n; i += 2) {
        if (((a[i] + k) * a[i + 1]) % 4 != 0) {
            swap(a[i], a[i + 1]);
            if (((a[i] + k) * a[i + 1]) % 4 == 0) {
                continue;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i += 2) cout << a[i] << " " << a[i + 1] << "\n";
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