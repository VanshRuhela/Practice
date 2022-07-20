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
    int t;
    cin >> t;
    vector<pair<int, int>> v;  // width , height
    rep(i, t) {
        int w, h;
        cin >> w >> h;
        v.push_back(make_pair(w, h));
    }

    sort(v.begin(), v.end());
    int dp[t];
    int omax = 0;
    for (int i = 0; i < t; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second && v[i].first < v[j].first) {
                if (dp[j] > max) max = dp[j];
            }
        }
        dp[i] = max + 1;
        if (dp[i] > omax) omax = dp[i];
    }
    cout << omax << "\n";
    return 0;
}