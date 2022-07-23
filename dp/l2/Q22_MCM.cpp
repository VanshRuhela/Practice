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
    int n;
    cin >> n;
    int arr[n];
    rep(i, n) cin >> arr[i];

    int dp[n - 1][n - 1];
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) dp[i][j] = 0;

            if (g == 1)
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];

            else {
                int min = INT_MAX;
                for (int k = i; k < j; k++) {
                    // i -> k: left half
                    // k+1 -> j: right half
                    // arr -> i*k+1
                    int lc = dp[i][k];
                    int rc = dp[k + 1][j];
                    int mc = arr[i] * arr[k + 1] * arr[j + 1];
                    int tc = lc + rc + mc;
                    if (tc < min) min = tc;
                }

                dp[i][j] = min;
            }
        }
    }

    cout << dp[0][n - 1];
    return 0;
}