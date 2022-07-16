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
        int n, x;
        cin >> n >> x;
        n = n * 2;
        int a[n];
        rep(i, n) cin >> a[i];

        sort(a, a + n);

        int i = n/2-1, j = n - 1;
        int f = 0;
        while (i >= 0) {
            if (a[i] + x > a[j]) {
                f = 1;
                break;
                // cout<<"br\n";
            }
            
            i--;
            j--;
        }

        if (f == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}