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
void reduceFraction(ll& x, ll& y) {
    ll d;
    d = __gcd(x, y);

    x = x / d;
    y = y / d;

    // cout << "x = " << x << ", y = " << y << endl;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;

        cin >> a >> b >> c >> d;

        if (a == 0 && c == 0)
            cout << "0\n";
        else if (a == 0 || c == 0)
            cout << "1\n";
        // else if( a/b == c/d ) cout << "0\n";
        else {
            reduceFraction(a, b);
            reduceFraction(c, d);

            if (a == c && b == d)
                cout << "0\n";
            else if (a == b || b == d)
                cout << 1 << "\n";
            else {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}