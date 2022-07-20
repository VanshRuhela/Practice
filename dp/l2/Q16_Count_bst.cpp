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

// Count the number of possible Binary Search Trees with n keys (See this)

int main() {
    fast_cin();
    int n;
    cin >> n;

    int dp[n+1]={0};
    dp[0] = 1;
    dp[1] = 1;

    for(int i =2; i<=n; i++){

        int l =0; 
        int r = i-1;
        while(l <= i-1){
            dp[i] += dp[l]*dp[r];
            l++;
            r--;
        }
    }

    cout<< dp[n];
    
    return 0;
}