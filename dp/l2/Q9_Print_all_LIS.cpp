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
    int l;
    int i;
    int val;
    string psf;
};

int main() {
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    rep(i, n) { cin >> arr[i]; }

    int dp[n] = {0};
    int ans = 0, omi = 0;

    for (int i = 0; i < n; i++) {
        int m = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                m = max(dp[j], m);
            }
        }
        dp[i] = m + 1;
        if (ans > dp[i]) {
            ans = max(ans, dp[i]);
            omi = i;
        }
    }

    cout << "LIS : " << ans << "\n";

    // printing the paths for LIS

    queue<Pair> q;
    q.push({ans, omi, arr[omi], to_string(arr[omi]) + ""});

    while (q.size() > 0) {
        Pair rem = q.front();
        q.pop();

        if (rem.l == 1) cout << rem.psf << endl;

        for (int j = rem.i; j >= 0; j++) {
            if (dp[j] == rem.i && arr[j] <= rem.val)
                q.push({dp[j], j, arr[j], to_string(arr[j]) + "->" + rem.psf});
        }
    }

    return 0;
}