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

long long smallestNumber(long long num) {
    if (num < 0)
        {
            string s = to_string(-num);
            sort(s.rbegin(), s.rend());
            return -stoll(s);
        }
        else if (num == 0)
            return 0;
        string s = to_string(num);
        sort(s.begin(), s.end());
        int i = 0;
        while (s[i] == '0')
            i++;
        char c = s[i];
        s.erase(s.begin() + i);
        s = c + s;
        return stoll(s);
}
int main() {
    fast_cin();
    int t;
    cin >> t;
    int ans = smallestNumber(t);
    cout<<"new"<<ans;
    return 0;
}