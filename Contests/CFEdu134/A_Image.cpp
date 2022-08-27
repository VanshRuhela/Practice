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
       unordered_map<char , int> m;
       for( int i =0 ; i<2; i++){
        char x; cin>>x;
        m[x]++;
       }
       for( int i =0 ; i<2; i++){
        char x; cin>>x;
        m[x]++;
       }

       int n = m.size();
       if(n == 1) cout<< "0\n";
       else if(n == 2) cout<<"1\n";
       else if(n == 4) cout<< "3\n";
       else cout<< "2\n";
    }
    return 0;
}