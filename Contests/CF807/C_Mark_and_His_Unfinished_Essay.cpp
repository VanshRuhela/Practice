#include <bits/stdc++.h>  
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;++i)
#define re(i,a,n) for(int i=a;i<=n;++i)
#define repr(i,a,n) for(int i=a;i>=n;--i)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;

char helper(vector<vector<ll>> &v , string &s , ll k){
    if(k < 0)
        return '0';
    
    else if(k < s.size())
        return s[k];
    
    else {
        for(int i =0; i<v.size(); i++){
            if(v[i][0] <= k && v[i][1] >= k){
                return helper(v,s, v[i][2] + k - v[i][3]);
            }
        }
    }
    
    return '0';
}

int32_t main() {
 fast_cin();
 int t; cin>>t;
 while(t--){ 
    ll n, c, q;

    cin>>n>>c>>q; // size of s , copy-paste ops , queries

    string s; cin>>s;
    vector<vector<ll>> v;
    v.push_back({0, n - 1, 0, n - 1});

    ll p =n; 
    for(int i=0; i<c; i++){
        ll l,r;
        cin>>l>>r;

        l--; r--;

        v.push_back({p,p+r-l, l,r});
        p+= r-l+1;
    }

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<4; j++){
            cout<< v[i][j] <<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<q; i++){
        ll k; cin>>k;
        k--;
        char ans = helper(v,s,k);
        cout<< ans<<"\n";
    }
 } 
   return 0;
}