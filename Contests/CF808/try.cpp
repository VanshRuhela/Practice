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
    vector<int> i = {2, 1, 1, 1, 2, 3, 34, 5, 6, 6, 7, 8};
    map<int, int> m;
    for (int x : i) {
        m[x]++;
    }

    for(auto x : m){
        cout << x.first <<" "<<x.second<<"\n";
    }

    return 0;
}