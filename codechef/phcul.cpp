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

ld dist(vi &a, vi &b){
    ld dx = a[0]-b[0];
    ld dy = a[1]-b[1];
    return sqrt(dx*dx + dy*dy);
}

ld helper(vvi &a, vvi &b, vvi &c, vi s, int n, int m, int k){
    vd dista(n);
    vd distb(m);
    for(int i=0; i<n; i++){
        dista[i] = dist(a[i], c[0]);
        for(int j=1; j<k; j++) dista[i] = min(dista[i], dist(a[i], c[j]));
    }
    for(int i=0; i<m; i++){
        distb[i] = dist(b[i], c[0]);
        for(int j=1; j<k; j++) distb[i] = min(distb[i], dist(b[i], c[j]));
    }
    ld ans = DBL_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ld temp = dist(a[i],b[j]);
            ans = min(ans, dist(s,a[i]) + temp + distb[j]);
            ans = min(ans, dist(s,b[j]) + temp + dista[i]);
        }
    }
    return ans;
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
        vi s(2);
        cin>>s[0]>>s[1];
        cin>>n>>m>>k;
        vvi a(n,vi(2));
        vvi b(m,vi(2));
        vvi c(k,vi(2));
        for(int i=0; i<n; i++) cin>>a[i][0]>>a[i][1];
        for(int i=0; i<m; i++) cin>>b[i][0]>>b[i][1];
        for(int i=0; i<k; i++) cin>>c[i][0]>>c[i][1];
        cout<<fixed<<setprecision(10)<<helper(a,b,c,s,n,m,k)<<endl;
    }
    return 0;
}

