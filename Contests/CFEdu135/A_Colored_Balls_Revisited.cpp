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

void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>> q;
    // vector<int> a(n);
    // for (auto& i : a) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push({a, i + 1});
    }

    while (q.size() > 1) {
        auto t = q.top();
        q.pop();
        if (q.size() < 0)
            break;
        else {
            auto b = q.top();
            q.pop();
            t.first--;
            b.first--;

            if (t.first != 0) q.push(t);
            if (b.first != 0) q.push(b);
        }
    }

    cout << q.top().second << "\n";
}
int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}