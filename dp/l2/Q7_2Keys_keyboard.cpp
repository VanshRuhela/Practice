/*=============================================================================
#  PROBLEM:          There is only one character 'A' on the screen of a notepad.
You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy
is not allowed). Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character
'A' exactly n times on the screen.



Example 1:

Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
Example 2:

Input: n = 1
Output: 0
=============================================================================*/
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

int minSteps(int n) {
    int ans = 0;
    for (int i = 2; i * i <= n;) {
        if (n % i == 0) {
            ans += i;
            n /= i;
        } else {
            i++;
        }
    }

    if (n != 1) ans += n;
    return ans;
}

int main() {
    fast_cin();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << minSteps(n) << "\n";
    }
    return 0;
}