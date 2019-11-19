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

int helper(vvi &a, int n, int m){
    sort(a.begin(),a.end());
    vi mp(m,0);
    int l = 0;
    unordered_set<int> s;
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
        int color = a[i][1];
        s.insert(color);
        mp[color]++;
        if(s.size() == m){
            while(mp[a[l][1]] > 1 && l<=i) mp[a[l++][1]]--;
            ans = min(ans, a[i][0] - a[l][0]);
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
        cin>>n>>m;
        vvi a(n, vi(2));
        for(int i=0; i<n; i++){
            cin>>a[i][0];
            a[i][1] = i%m;
        }
        cout<<helper(a,n,m)<<endl;
    }
    return 0;
}

