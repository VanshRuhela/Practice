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
        string s;
        cin >> s;

        if (s.length() % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        int p = 0, q = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                p++;
            else if (s[i] == ')')
                p--;
            else
                q++;
        }

        if (p < 0) p = -p;

        if ((p == 0 && q == 2) || p == q)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}