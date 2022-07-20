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
    // first lis cal krte hai
    // phir uske baad dec decreasing longest subseq banayenge

    int n;
    int arr[n];
    rep(i, n) cin >> arr[i];

    // lis
    int lis[n];
    rep(i, n) {
        int max = 0;
        rep(j, i) {
            if (arr[j] <= arr[i]) {
                if (lis[j] > max) max = lis[j];
            }
        }

        lis[i] = max + 1;
    }

    // lds
    int lds[n];
    repr(i, n - 1, 0) {
        int max = 0;
        repr(j, n - 1, i - 1) {
            if (arr[j] <= arr[i]) {
                if (lds[j] > max) max = lds[j];
            }
        }

        lis[i] = max + 1;
    }
    int omax = 0;
    rep(i, n) {
        if (lis[i] + lds[i] > omax) omax = lis[i] + lds[i];
    }

    cout<< omax-1 <<endl;
    return 0;
}