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
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        vector<ll> rr(k);
        vector<ll> cl(k);
        for (int i = 0; i < k; i++) {
            rr[i] = arr[i] / m;
            cl[i] = arr[i] / n;
        }

        ll rrs = 0, rrcc = 0, cls = 0, clcc = 0;

        for (int i = 0; i < k; i++) {
            if (rr[i] > 2) {
                rrs += rr[i];
            } else if (rr[i] == 2) {
                rrcc++;
            }
            if (cl[i] > 2) {
                cls += cl[i];
            } else if (cl[i] == 2) {
                clcc++;
            }
        }

        if (rrs >= n or cls >= m) {
            cout << "Yes" << endl;
            continue;
        }

        if (!((n - rrs) % 2) and rrcc >= (n - rrs) / 2) {
            cout << "Yes" << endl;
            continue;
        }

        if (!((m - cls) % 2) and clcc >= (m - cls) / 2) {
            cout << "Yes" << endl;
            continue;
        }

        cout << "No" << endl;
    }
    return 0;
}