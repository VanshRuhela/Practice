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
    string psf;
    int i;
    int j;
};

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int dp[n][m];
    for (int j = m - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (j == m - 1)
                dp[i][j] = arr[i][j];
            else if (i == 0)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            else if (i == n - 1)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            else
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1],
                                                             dp[i + 1][j + 1]));
        }
    }

    int maxe = INT_MIN;
    for (int i = 0; i < n; i++)
        if (dp[i][0] > maxe) maxe = dp[i][0];
    cout<<"maxe "<<maxe<<"\n";
    queue<Pair> q;

    for (int i = 0; i < n; i++) {
        if (dp[i][0] == maxe) q.push({to_string(i)+"", i, 0});
    }

    while (q.size() > 0) {
        Pair rem = q.front();
        q.pop();

        if (rem.j == m - 1)
            cout << rem.psf << "\n";
        else if (rem.i == 0) {
            int g = max(dp[rem.i][rem.j + 1], dp[rem.i + 1][rem.j + 1]);

            if (g == dp[rem.i][rem.j + 1])
                q.push({rem.psf + " d2", rem.i, rem.j + 1});
            if (g == dp[rem.i + 1][rem.j + 1])
                q.push({rem.psf + " d3", rem.i + 1, rem.j + 1});

        } else if (rem.i == n - 1) {
            int g = max(dp[rem.i][rem.j + 1], dp[rem.i - 1][rem.j + 1]);

            if (g == dp[rem.i][rem.j + 1])
                q.push({rem.psf + " d2", rem.i, rem.j + 1});
            if (g == dp[rem.i - 1][rem.j + 1])
                q.push({rem.psf + " d1", rem.i - 1, rem.j + 1});

        } else {
            int g = max(dp[rem.i][rem.j + 1], max(dp[rem.i + 1][rem.j + 1],
                                                  dp[rem.i - 1][rem.j + 1]));

            if (g == dp[rem.i][rem.j + 1])
                q.push({rem.psf + " d2", rem.i, rem.j + 1});
            if (g == dp[rem.i + 1][rem.j + 1])
                q.push({rem.psf + " d3", rem.i + 1, rem.j + 1});
            if (g == dp[rem.i - 1][rem.j + 1])
                q.push({rem.psf + " d1", rem.i - 1, rem.j + 1});

        }
    }

    return 0;
}