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
        ll n, l, r;
        cin >> n >> l >> r;
        // if (n < r - l) {
        //     cout << "NO\n";
        //     continue;
        // }
        vector<ll> v;
        for (ll i = 1; i <= n; i++) {
            if (i - l % (i) + l >= l && i - l % (i) + l <= r) v.push_back(i + l - 1);
        }
        if(l == r){
            cout<<l<<"\n";
            continue;
        }
        if(v.size() < n){
            cout<<"NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto i : v) cout << i << " ";
        cout << "\n";
    }

    return 0;
}