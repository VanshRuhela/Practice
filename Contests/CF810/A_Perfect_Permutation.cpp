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
    while (t--) {
        ll n;
        cin >> n;

        
        // for (int i = 1; i <= n; i++) a[i] = i;

        // int m = (n + 1) / 2, c = n;
        // int i;
        // for (i = 1; i <= (n + 1) / 2; i++) {
        //     // cout <<"L1 "<<m<<"\n";
        //     a[i] = m--;
        // }
        // for (; i <= n; i++) {
        //     // cout <<"L2 "<<c<<"\n";
        //     a[i] = c--;
        // }

        // if ((n + 1) / 2 >= 3) {
        //     // cout << "swap\n";
        //     swap(a[1], a[2]);
        // }

        // for (int i = 1; i <= n; i++) cout << a[i] << " ";
        // cout << "\n";

        for(int i=1; i<=n-1; i++)
            cout<< i+1 <<" ";
        cout<<"1\n";
    }
    return 0;
}