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
    int n;
    cin >> n;
    int arr[n];
    rep(i, n) cin >> arr[i];

    int dp[n] = {0};
    int omax = INT_MIN;

    for (int i = 0; i < n; i++) {
        int max = INT_MIN;
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                if (max == INT_MAX)
                    max = dp[j];
                else if (dp[j] > max)
                    max = dp[j];
            }
        }
        if (max == INT_MIN)
            dp[i] = arr[i];
        else
            dp[i] = max + arr[i];

        if (dp[i] > omax) omax = dp[i];
    }
    cout << omax << "\n";

    return 0;
}