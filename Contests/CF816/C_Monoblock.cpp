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

void c1(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (a[i] != a[i + 1]) ans -= (i + 1) * (n - 1 - i);
}

void checker1(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (i + 1 < n) {
        c1(i, x, ans, a, n);
    }
}

void c4(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (a[i] != a[i - 1]) ans += i * (n - i);
}

void c3(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (i) {
        c4(i, x, ans, a, n);
    }
}
void c2(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (a[i] != a[i + 1]) ans += (i + 1) * (n - 1 - i);
}

void checker2(ll i, ll x, ll& ans, vector<ll>& a, ll& n) {
    if (i + 1 < n) {
        c2(i, x, ans, a, n);
    }
}

void solve(ll& ans, vector<ll>& a, ll n) {
    ll i, x;
    cin >> i >> x;
    i--;
    checker1(i, x, ans, a, n);

    if (i && a[i] != a[i - 1]) ans -= i * (n - i);

    a[i] = x;
    checker2(i, x, ans, a, n);
    c3(i, x, ans, a, n);

    cout << ans << "\n";
}
int main() {
    fast_cin();
    ll n, m;
    cin >> n >> m;
    // ll a[n];
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll c = 1;
    ll ans = n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) ans += i * (n - i);
    }
    while (m--) {
        solve(ans, a, n);
    }
}