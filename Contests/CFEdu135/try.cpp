#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define For(i, a, b) for (ll i = (a); i <= (b); i++)
#define Forx(i, a, b, x) for (ll i = (a); i <= (b); i += x)
#define read(a) \
    ll a;       \
    cin >> a;
#define Ford(i, a, b) for (ll i = (a); i >= (b); i--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define fast_io
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define pr pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define sz(container) int((container).size())
#define cut(x)             \
    {                      \
        cout << x << "\n"; \
        continue;          \
    }
#define setprec(x) cout << fixed << showpoint << setprecision(15) << x << "\n";
#define endl '\n';
#define fi first
#define se second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cout << '{';
    __print(x.first);
    cout << ',';
    __print(x.second);
    cout << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cout << '{';
    for (auto &i : x) cout << (f++ ? "," : ""), __print(i);
    cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void print(T t, V... v) {
    _print(t);
    if (sizeof...(v)) cout << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cout << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
#ifdef LOCAL_DEFINE
cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
typedef tree<pr, null_type, less<pr>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░

//*s.find_by_order() ->returns an iterator to the k-th largest element (counting
//from zero); s.order_of_key() ->number of elements strictly smaller then our
// item; st.rbegin()->second; last element in se st.erase(prev(st.end()));
// delete last element in set; sort(a+1,a+n+1,[](ll x,ll y){return
// abs(x)>abs(y);}); sort(v.begin(), v.end(), greater<int>()); -> not sure work
// for first also if second are equal;
// q=lower_bound(all(v[a[i]]),i)-v[a[i]].begin()+1;
// s.substr(start_ind,length);
// vpll shift={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}} ->shift
// operator;
// bool comp(pr a,pr b){return a.second<b.second;} // use for differentiate
// order of comparision;
// cntbit(x) __builtin_popcount(x); -> no. of bits in given no.;
// true false; memset(dp,-1,sizeof(dp));
// std::random_shuffle(all(vec));

//░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
const ll Maxn = 2e5 + 5;
const ll Inf = 1e18;

int get(int x) {
    string s = to_string(x);
    return s.size();
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
//“one of them is all alone and ever more shall be so”;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    read(t);
    while (t--) {
        int n;
        cin >> n;

        vi a(n + 1), b(n + 1);
        map<int, int> ma, mb;

        int ans = 0;

        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            ma[a[i]] += 1;
        }

        for (int i = 1; i <= n; i += 1) {
            cin >> b[i];

            if (ma[b[i]] > 0) {
                ma[b[i]] -= 1;
            } else
                mb[b[i]] += 1;
        }

        vi v1, v2;

        for (auto x : ma) {
            if (x.first > 9 and x.second > 0) {
                ma[x.first] = 0;
                ma[get(x.first)] += x.second;

                ans += x.second;

                // debug(x.first, x.second);
            }
        }

        debug(ans);

        for (auto x : mb) {
            if (x.first > 9 and x.second > 0) {
                mb[x.first] = 0;
                mb[get(x.first)] += x.second;

                ans += x.second;
            }
        }

        debug(ans);

        debug(ma);
        debug(mb);

        for (auto x : ma) {
            int p = min(mb[x.first], x.second);

            ma[x.first] -= p;
            mb[x.first] -= p;

            if (x.first > 1) ans += ma[x.first];

            // debug(x, ans);
        }

        for (auto x : mb)
            if (x.first > 1) ans += mb[x.first];

        cout << ans << endl;
    }
}