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



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n,k,p;
    cin>>n>>k>>p;
    vector<vi> xloc_frognum(n,vi(2,0));
    for(int i=0; i<n; i++){
        xloc_frognum[i][1] = i+1;
        cin>>xloc_frognum[i][0];
    }   
    sort(xloc_frognum.begin(), xloc_frognum.end());
    vll max_dist(n+1,0);
    for(int i=n-1; i>=0; i--){
        auto temp = xloc_frognum[i];
        if(i== n-1) max_dist[temp[1]] = temp[0]+k; 
        else if(abs(temp[0] - xloc_frognum[i+1][0]) <= k ) max_dist[temp[1]] = max_dist[xloc_frognum[i+1][1]];
        else  max_dist[temp[1]] = temp[0]+k; 
    }
    ll a,b;
    while(p--){
        cin>>a>>b;
        if(max_dist[a] == max_dist[b]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

