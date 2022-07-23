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

// In the second test case:

// The best partition for the subsegment [2,0,1]: [2],[0,1]. The cost of this partition equals to 2+mex({2})+mex({0,1})=2+0+2=4.
// The best partition for the subsegment [2,0]: [2],[0]. The cost of this partition equals to 2+mex({2})+mex({0})=2+0+1=3
// The best partition for the subsegment [2]: [2]. The cost of this partition equals to 1+mex({2})=1+0=1.
// The best partition for the subsegment [0,1]: [0,1]. The cost of this partition equals to 1+mex({0,1})=1+2=3.
// The best partition for the subsegment [0]: [0]. The cost of this partition equals to 1+mex({0})=1+1=2.
// The best partition for the subsegment [1]: [1]. The cost of this partition equals to 1+mex({1})=1+0=1.
// The sum of values over all subsegments equals to 4+3+1+3+2+1=14.

int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        ll a[n];
        rep(i,n) cin>>a[i];


        // c = num of segments + smallest non negative number not present in the set
        // ans = summation of c over all the subsets
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j = i; j<n; j++){
                ans += (j-i+1); //c
                for(int k = i; k<= j; k++){
                    if(a[k] == 0) ans++;
                }
            }
        }

        cout<<ans<<"\n";



    }
    return 0;
}