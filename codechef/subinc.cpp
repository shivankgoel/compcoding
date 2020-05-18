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


ll f(vll &a, ll n){
    ll prev =1, ans=1;
    for(ll i=1; i<n; i++){
        if(a[i] >= a[i-1])prev++;
        else prev=1;
        ans+=prev;
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
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vll a(n);
        for(ll i=0; i<n; i++)cin>>a[i];
        cout<<f(a,n)<<endl;
    }
    return 0;
}

