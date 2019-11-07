#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef unordered_map<int,int> umpii;


#define EPS 1e-9
#define PI 3.14159265
#define mod 1e9+7
#define N 300001
#define pb push_back

ll arr[N];
ll dist1to1[21][21];
ll mindist[N][21];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t,m,n,q,a,b;
    cin>>n>>q;
    for(ll i=1; i<=n; i++)
    	cin>>arr[i];

    memset(dist1to1, INT_MAX, sizeof(dist1to1));
    for(ll i=0; i<21; i++) dist1to1[i][i] = 0;

    for(ll i=n;i>=1;i--){
    	vector<ll> zeros, ones;
    	for(ll j=0;j<21;j++){
    		if(arr[i] & (1<<j)){
	    		mindist[i][j] = 0;
	    		ones.pb(j);
	    		for(ll k=0; k<21; k++) if(arr[i] & (1<<k)) dist1to1[j][k] = 0;
    		}
    		else zeros.pb(j);
    	}
    	for(auto x: zeros){
    		ll temp = INT_MAX;
    		for(auto y: ones){
    			temp = min(temp, dist1to1[y][x]);
    		}
    		for(auto y: ones) dist1to1[y][x] = temp;
    		mindist[i][x] = temp;
    	}
    	for(ll j=0; j<21; j++)
    		for(ll k=0; k<21; k++)
    			if(j!=k) dist1to1[j][k]++;
    }

    while(q--){
    	cin>>a>>b;
    	ll mi = INT_MAX;
    	for(ll j=0; j<21; j++){
    		if(arr[b] & (1<<j)){
	    		mi = min(mi, mindist[a][j]);
    		}
    	}
        if(mi <= b-a) cout<<"Shi\n"; 
        else cout<<"Fou\n";
    }
    return 0;
    	
}


