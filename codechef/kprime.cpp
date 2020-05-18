#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef unordered_map<int,int> umpii;
#define EPS 1e-9
#define PI 3.14159265
#define mod 1000000009
#define N 300001
#define pb push_back

vll dp(1000001,-1);

ll f(ll x){
    if(dp[x] != -1) return dp[x]; 
    for(int i=4; i<=x; i++){
      dp[i] = (dp[i-2] + dp[i-3]) % mod;
    }
    return dp[x];
}
 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t,x;
    cin>>t;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    while(t--){
        cin>>x;
        cout<<f(x)<<endl;
    }
    return 0;
}

