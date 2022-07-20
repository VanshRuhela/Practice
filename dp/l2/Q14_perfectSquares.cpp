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

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int min = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            int rem = i - j * j;
            if (dp[rem] < min) min = dp[rem];
        }

        dp[i] = min + 1;
    }

    cout<< dp[n]<<"\n";
    return 0;
}