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
        long long int n, k, b, s;
        cin >> n >> k >> b >> s;

        vector<long long int> a(n);

        if (b * k > s) {
            cout << -1 << "\n";
            continue;
        } else if (n * (k - 1) + k * b < s) {
            cout << -1 << "\n";
            continue;
        } else {
            vector<long long int> a(n);
            for (int i : a) i = 0;

            a[0] = b * k;
            s = s - b * k;

            for (int i = 0; i < n; i++) {
                int x = min(s, k - 1);
                a[i] += x;
                s -= x;
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}