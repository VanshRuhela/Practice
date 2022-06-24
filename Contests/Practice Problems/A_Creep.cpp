#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a >= b) {
            while (a > 0 and b > 0) {
                cout << "01";
                a--;
                b--;
            }
            while (a--) cout << "0";
        } else {
            while (a > 0 and b > 0) {
                cout << "10";
                a--;
                b--;
            }
            while (b--) cout << "1";
        }

        cout << endl;
    }
}
