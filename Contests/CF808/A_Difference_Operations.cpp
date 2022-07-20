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
        int n;
        cin >> n;
        ll a[n];
        int f = 0;
        // map<int, int> m;
        rep(i, n) {
            cin >> a[i];
            // m[a[i]]++;
        }

        string ans = "YES";

        for (int i = 1; i < n; i++) {
            if(a[i]%a[0] !=0)
                ans = "NO";
            
        }

        // cout << 6 % 7 << endl;
        cout << ans << "\n";
    }
    return 0;
}