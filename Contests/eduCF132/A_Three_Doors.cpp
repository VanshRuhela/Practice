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
        int x;
        cin >> x;

        int a[4];
        for (int i = 1; i < 4; i++) cin >> a[i];
        string ans = "";

        for (int i = 1; i < 4; i++) {
            if (x == i && a[i] == 0) ans = "NO";
        }
        bool khuli[4]= {false};
        while(x != 0){
            khuli[x] = true;
            int key = a[x];
            x = key;
        }

        for(int i=1; i<4; i++){
            if(khuli[i] == false){
                ans = "NO";
                break;
            }
        }

        if(ans == "NO")
            cout<<"NO\n";
        else 
            cout<<"YES\n";
        

    }
    return 0;
}