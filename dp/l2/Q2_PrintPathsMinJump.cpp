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
    int idx;
    string psf;
    int jmps;
};

int main() {
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // solution
    int dp[n];
    for (int i = 0; i < n; i++) dp[i] = INT_MAX;
    dp[n - 1] = 0;  // aready phouche hue hai
    for (int i = n - 2; i >= 0; i--) {
        int steps = arr[i];
        int min = INT_MAX;
        for (int j = 1; j <= steps && i + j < n; j++) {
            if (dp[i + j] != INT_MAX && dp[i + j] < min) {
                min = dp[i + j];
            }
        }
        if (min != INT_MAX) dp[i] = 1 + min;
    }

    cout << "Min Steps " << dp[0] << "\n";

    queue<Pair> Q;
    Pair p = {0, "0", dp[0]};
    Q.push(p);

    while (Q.size()>0) {
        Pair tmp = Q.front();
        Q.pop();

        if (tmp.jmps == 0) {
            cout << tmp.psf << "\n";
            continue;
        }

        for (int step = 1; step <= arr[tmp.idx]; step++) {
            if (tmp.idx + step < n && tmp.jmps - 1 == dp[tmp.idx + step]) {
                string s1 = tmp.psf+"->"+to_string((tmp.idx + step));
                Pair p2 = {tmp.idx + step, s1, tmp.jmps-1};
                Q.push(p2);
            }
        }
    }
}