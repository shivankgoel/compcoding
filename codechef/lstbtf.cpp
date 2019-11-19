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
#define mod 1e9+7
#define N 300001
#define pb push_back


int cnt1;
ll dp[10][30][81*30];

bool issquare(ll sum){
    ll x = sqrt(sum);
    return (x*x) == sum;
}

bool helper(ll i, ll n, ll sum){
    if(i==10) return ((n==0) && issquare(sum+cnt1));
    if(dp[i][n][sum] != -1) return dp[i][n][sum];
    bool ans = false;
    for(int k=n; k>=0; k--)
        ans|= helper(i+1, n-k, sum + (i*i*k));
    return dp[i][n][sum] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll t,m,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        for(cnt1 = n; cnt1>=0; cnt1--){
            memset(dp,-1,sizeof(dp));
            if(helper(2,n-cnt1,0)) break;
        }
        string ans(cnt1,'1');
        ll sum = 0;
        ll remcount = n - cnt1;
        for(int i=2; i<10; i++){
            for(ll j=remcount; j>0; j--){
                if(helper(i+1,remcount-j,sum+(j*i*i))){
                    sum+= (i*i*j);
                    remcount-=j;
                    for(ll l=0; l<j; l++) ans.push_back('0'+i);
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

