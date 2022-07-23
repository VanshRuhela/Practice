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

// In the first test, all elements are equal, therefore no operations are
// needed.

// In the second test, you can apply one operation with k=1 and l=1, set a1:=a2,
// and the array becomes [1,1] with 1 operation.

// In the third test, you can apply one operation with k=1 and l=4, set a4:=a5,
// and the array becomes [4,4,4,4,4].

// In the fourth test, you can apply one operation with k=1 and l=3, set a3:=a4,
// and the array becomes [4,2,3,3], then you can apply another operation with
// k=2 and l=1, set a1:=a3, a2:=a4, and the array becomes [3,3,3,3].

// In the fifth test, there is only one element, therefore no operations are
// needed.
int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int f = 0;
        rep(i, n) {
            cin >> a[i];
            if (i != 0 && a[i] != a[i - 1]) {
                f = 1;
            }
        }

        if (n == 1 || f == 0) {
            cout << 0;
            continue;
        }

        
    }
    return 0;
}