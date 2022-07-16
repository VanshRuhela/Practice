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
        ll n, s = 0;
        cin >> n;
        ll a[n];
        rep(i, n) {
            cin >> a[i];
        }
        bool f = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != 0) f = true;
            if (a[i] == 0 && f) s++;
            s += a[i];
        }
        cout << s << endl;
    }
    return 0;
}