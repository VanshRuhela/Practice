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
int main() {
  
  int n, m;
  cin>>n>>m;
  
  vector<vector<int>> v(n , vector<int>(m,0));
  vector<vector<int>> dp(n, vector<int>(m,0));
  cout<<n<<m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      int x;
      cin>>v[i][j];
      //cout<<"in\n";
    }
  }
  cout<<"afe\n";
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout<<v[i][j];
      //cout<<"in\n";
    }
    cout <<"\n";
  }
  int ans = INT_MIN;
  for(int i=n-1; i>=0; i--){
    for(int j =m-1; j>=0; j--){
      cout<<"loop\n";
      if(v[i][j] == 0)
        dp[i][j] = v[i][j];
      else if((i == m-1 || j == n-1) && v[i][j] == 1)
        dp[i][j] = v[i][j];
      else
        dp[i][j] = min(dp[i+1][j] , min( dp[i][j+1] ,dp[i+1][j+1]));

      ans = max(ans , dp[i][j]); 
    }
  }
  
  cout<<"ann\n"<<ans;

  return 0;
 }