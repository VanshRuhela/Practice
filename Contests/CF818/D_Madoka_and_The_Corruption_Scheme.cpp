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
ll mod = 1000000000 + 7;
int fact(int n);

unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1;  // Initialize result

    x = x % p;  // Update x if it is more than or
    // equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res * x) % p;

        // y must be even now
        y = y >> 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p) {
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n, int r, int p) {
    // If n<r, then nCr should return 0
    if (n < r) return 0;
    // Base case
    if (r == 0) return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) %
            p) %
           p;
}

int main() {
    fast_cin();
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    ll mini = min(n, k) + 1;
    ll minn = min(n, k);
    for (ll i = 0; i < mini; i++) {
        if (i < minn)
            ans = (ans % mod) + (nCrModPFermat(n - 1, i, mod) * 2) % mod;

        else
            ans = ans % mod + nCrModPFermat(n - 1, i, mod) % mod;
    }

    cout << ans << "\n";

    return 0;
}