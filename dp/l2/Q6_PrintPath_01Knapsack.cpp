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

struct Pair {
    int i;
    int j;
    string psf;
};

int main() {
    fast_cin();
    int n;
    cin >> n;
    int vals[n];
    int wts[n];
    int cap;

    rep(i, n) { cin >> vals[i] >> wts[i]; }

    cin >> cap;

    // int dp[n+1][cap+1] ={0};
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < cap + 1; i++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= wts[i - 1]) {
                if (dp[i - 1][j - wts[i - 1] + vals[i - 1] > dp[i - 1][j]]) {
                }
            }
        }
    }

    int ans = dp[n][cap];
    cout << ans << "\n";

    queue<Pair> q;
    q.push({n, cap, ""});

    while (q.size() > 0) {
        Pair rem = q.front();
        q.pop();

        if (rem.i == 0 || rem.j == 0)
            cout << rem.psf << "\n";
        else {
            int exc = dp[rem.i - 1][rem.j];
            if (rem.j >= wts[rem.i - 1]) {
                int inc =
                    dp[rem.i - 1][rem.j - wts[rem.i - 1]] + vals[rem.i - 1];

                if (dp[rem.i][rem.j] == inc)
                    q.push({rem.i - 1, rem.j - wts[rem.i - 1],
                            rem.psf + to_string(rem.i - 1) + " "});
            }

            if (dp[rem.i][rem.j] == exc) {
                q.push({rem.i - 1, rem.j, rem.psf});
            }
        }
    }

    return 0;
}