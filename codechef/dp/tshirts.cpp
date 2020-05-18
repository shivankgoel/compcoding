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
#define mod 1000000007
#define N 300001
#define pb push_back

int dp[(1<<10)+1][101];

ll f(int mask, int tid, int n, vvi &v){
    if(mask == (1<<n)-1) return 1;
    if(tid == 101) return 0;
    if(dp[mask][tid] != -1) return dp[mask][tid];
    int ans = 0;
    ans = (ans + f(mask, tid+1, n, v)) % mod;
    for(int p: v[tid]){
        if( (mask & (1<<p)) == 0){
            ans = (ans + f(mask | (1<<p), tid+1, n, v)) % mod;
        }
    }
    return dp[mask][tid] = ans % mod;
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
        memset(dp, -1, sizeof dp);
        vvi v(101, vector<int>());
        cin>>n;
        string s;
        string temp;
        cin.get();
        for(int i=0;i<n;i++){
            getline(cin, s);
            stringstream ss(s);
            while(ss >> temp){
                v[stoi(temp)].push_back(i);
            }
        }
        cout<<f(0,1,n,v)<<endl;
        // for(int i=1; i<101; i++){
        //     cout<<i<<" : ";
        //     for(int p: v[i]){
        //         cout<<p<<" ";
        //     }
        //     cout<<endl;
        // }

    }
    return 0;
}

