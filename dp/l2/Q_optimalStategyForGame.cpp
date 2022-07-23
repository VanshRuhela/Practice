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

// Assume worst when things happen to you
// do best when you can

int main() {
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    rep(i, n) cin >> arr[i];

    int dp[n][n];

    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0)
                dp[i][j] = arr[i];

            else if (g == 1)
                dp[i][j] = max(arr[i], arr[j]);
            else {
                int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                dp[i][j] = max(val1, val2);
            }
        }
    }

    cout << dp[0][n - 1];
    return 0;
}