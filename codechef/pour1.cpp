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


ll give_min_moves(int a, int b, int c){
    if(!c) return 0;
    if(c > a && c > b) return -1;
    int p=a, q=0, ans=1;
    while(p!=c && q!=c){
        int x = min(p, b-q);
        p-=x;
        q+=x;
        ans++;
        if(p==c || q==c) return ans;
        if(p==0){
            ans++;
            p=a;
        }
        if(q==b){
            ans++;
            q=0;
        }
        if(p==a && q==0) return -1;
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
    ll t,a,b,c;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cout<<min(give_min_moves(a,b,c),give_min_moves(b,a,c))<<endl;
    }
    return 0;
}

