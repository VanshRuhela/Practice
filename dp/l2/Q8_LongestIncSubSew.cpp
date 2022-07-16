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
    int arr[n];
    rep(i, n) { cin >> arr[i]; }

    int dp[n] = {0};
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int m = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                m = max(dp[j], m);
            }
        }
        dp[i] = m + 1;

        ans = max(ans, dp[i]);
    }

    cout << "LIS : " << ans << "\n";
    return 0;
}