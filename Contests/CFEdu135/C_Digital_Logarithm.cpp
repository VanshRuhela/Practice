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

int get(int x) {
    string s = to_string(x);
    return s.size();
}

void update(map<ll, ll>& mb, ll& ans) {
    for (auto x : mb) {
        if (x.first > 9 && x.second > 0) {
            mb[x.first] = 0;
            mb[get(x.first)] += x.second;
            ans += x.second;
        }
    }
}

void update2(map<ll, ll>& ma, map<ll, ll>& mb, ll& ans) {
    for (auto x : ma) {
        auto p = min(mb[x.first], x.second);

        ma[x.first] -= p;
        mb[x.first] -= p;

        if (x.first > 1) ans += ma[x.first];
    }
}

void update3(map<ll, ll>& ma, map<ll, ll>& mb, ll& ans){
    for (auto x : mb)
        if (x.first > 1) ans += mb[x.first];
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    map<ll, ll> ma, mb;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ma[a[i]]++;
    }

    for (int i = 1; i <= n; i++) {
        cin >> b[i];

        if (ma[b[i]] <= 0)
            mb[b[i]]++;
        else
            ma[b[i]]--;
    }

    // vector<ll> va, vb;
    ll ans = 0;

    update(ma, ans),update(mb, ans);

    update2(ma, mb , ans);

    update3(ma, mb , ans);

    cout << ans << "\n";
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