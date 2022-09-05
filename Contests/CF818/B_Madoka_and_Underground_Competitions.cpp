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
void solve(int n, int k, int r, int c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % k != (r + c - 2) % k)
                cout << '.';
            else
                cout << 'X';
        }
        cout << "\n";
    }
}
int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        ll n, k, r, c;
        cin >> n >> k >> r >> c;

        solve(n, k, r, c);
    }
    return 0;
}