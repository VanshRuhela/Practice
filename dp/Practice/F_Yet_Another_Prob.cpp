#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int long long int
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
#define all(v) v.begin() , v.end()
using namespace std;
int32_t main() {
    fast_cin();
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pair<int , int>> v;
        for(int i=1; i<=n; i++){
            int x;
            cin>>x; 
            v.push_back({x , i});
        }

        sort(all(v));

        for(auto i : v){
            if(i.first < i.second){
                
            }
        }


    }

    return 0;
}