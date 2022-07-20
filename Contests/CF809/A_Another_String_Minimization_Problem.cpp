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
        int n, m;
        cin >> n >> m;
        string s;
        rep(i, m) s += "B";
        // cout <<"formed string "<<s<<"\n";
        int a[n];
        rep(i, n) { cin >> a[i]; }

        for (int i = 0; i < n; i++) {
            int p1 = a[i] - 1;
            int p2 = m + 1 - a[i] - 1;
            bool flag = false;
            int mini = min(p1, p2);

            if (p1 <= p2) {
                if (s[p1] == 'B') {
                    flag = true;
                    s[p1] = 'A';
                }
            } else {
                if (s[p2] == 'B') {
                    flag = true;
                    s[p2] = 'A';
                }
            }

            if (!flag) {
                s[m - mini - 1] = 'A';
            }
        }

        cout << s << "\n";
    }
    return 0;
}