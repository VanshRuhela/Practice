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

void f4(vector<ll> &dmn, vector<ll> &a1, vector<ll> &a2, int &test1, int &i,
        int &n) {
    while (a1[i] > a2[test1]) test1++;

    dmn[i] = a2[test1] - a1[i];
}

void func1(vector<ll> &dmn, vector<ll> &a1, vector<ll> &a2) {
    int n = a1.size();
    int test1 = 0;
    for (int i = 0; i < n; i++) {
        f4(dmn, a1, a2, test1, i, n);
    }
}

void f3(vector<ll> &dmx, vector<ll> &a1, vector<ll> &a2, int &test2, int &i,
        int &n) {
    if (test2 <= i) test2 = i;

    while (test2 + 1 < n && a2[test2] >= a1[test2 + 1]) test2++;

    dmx[i] = a2[test2] - a1[i];
}
void func2(vector<ll> &dmx, vector<ll> &a1, vector<ll> &a2) {
    int n = a1.size();
    int test2 = 0;
    for (int i = 0; i < n; i++) {
        f3(dmx, a1, a2, test2, i, n);
    }
}
int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n), dmn(n), dmx(n);
        for (auto &i : a) cin >> i;
        for (auto &i : b) cin >> i;

        func1(dmn, a, b);
        func2(dmx, a, b);

        for (auto &ele : dmn) cout << ele << " ";

        cout << endl;

        for (auto &ele : dmx) cout << ele << " ";

        cout << endl;
    }
    return 0;
}