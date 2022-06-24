#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v;

        for (int i = 0; i < n; i++) {
            vector<int> x(m);
            for (int j = 0; j < m; j++) cin >> x[j];
            v.push_back(x);
        }

        if(n==m){
            if(n==1) cout<<"1\n";
            else cout<<(n-1)*(m-1)<<"\n";
        }

        else if(n>m){
            cout<<m*m<<"\n";
        }else{
            cout<<n*n<<"\n";
        }
        
    }
}