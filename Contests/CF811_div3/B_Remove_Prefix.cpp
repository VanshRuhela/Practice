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
        int a[n];
        for (auto &x : a) cin >> x;
        reverse(a, a+n);
        unordered_set<int> s;

        int ans = 0;
        rep(i, n) {
            if (s.find(a[i]) != s.end())
                break;
            else
                s.insert(a[i]);

            ans++;
        }

        cout << n - ans << "\n";
    }
    return 0;
}