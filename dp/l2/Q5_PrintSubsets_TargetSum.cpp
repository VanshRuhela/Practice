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
    int n;
    cin >> n;

    int arr[n];
    rep(i, n) cin >> arr[i];

    int tar;
    cin >> tar;

    bool dp[n + 1][tar + 1];

    rep(i, n + 1) {
        rep(j, tar + 1) {
            if (j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else {
                if (dp[i - 1][j])
                    dp[i][j] =
                        true;  // bat mt krna baki ki team hi bana legi runs
                else if (j >= arr[i - 1])
                    if (dp[i - 1][j - arr[i - 1]] == true) dp[i][j] = true;
            }
        }
    }

    cout << dp[n][tar] << "\n";

    // rev engg
    queue<Pair> q;
    q.push({"", n, tar});

    while (q.size() > 0) {
        Pair rem = q.front();
        q.pop();
        if (rem.i == 0 || rem.j == 0) {
            cout << rem.psf << "\n";
            continue;
        }
        bool exc = dp[rem.i - 1][rem.j];
        if (rem.j >= arr[rem.i - 1]) {
            bool inc = dp[rem.i - 1][rem.j - arr[rem.i - 1]];
            if (inc) {
                q.push({to_string(rem.i - 1) + " " + rem.psf, rem.i - 1,
                        rem.j - arr[rem.i - 1]});
            }
        }
        if (exc) {
            q.push({rem.psf, rem.i - 1, rem.j});
        }
    }

    return 0;
}