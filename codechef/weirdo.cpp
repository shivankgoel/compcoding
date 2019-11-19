#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
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

bool isvowel(char &c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

bool isalice(string &x){
	int n = x.size();
	int last = -1;
	for(int i=0; i<n; i++){
		if(!isvowel(x[i])){
			if(last!=-1 && i-last <= 2) return false;
			last = i;
		}
	}
	return true;
}

ld logscore(vs &a, int n){
	vi mp1(26,0);
	vi mp2(26,0);
	for(int i=0; i<n; i++){
		vector<bool> s(26,false);
		for(char x: a[i]){
			mp1[x-'a']++;
			s[x-'a']=true;
		}
		for(int i=0; i<26; i++) if(s[i]) mp2[i]++;
	}
	ld ans = 0;
	for(int i=0; i<26; i++) if(mp1[i]>0) ans+= (log(mp2[i]) - (n*log(mp1[i])));
	return ans;
}

ld helper(vs &a, vs &b){
	int m = a.size();
	int n = b.size();
	if(!m) return 0;
	if(!n) return 1e7+1;
	ld ascore = logscore(a,m);
	ld bscore = logscore(b,n);
	return exp(ascore-bscore);
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
    string temp;
    while(t--){
    	cin>>n;
    	vs a;
    	vs b;
    	for(int i=0; i<n; i++){
    		cin>>temp;
    		if(isalice(temp)) a.pb(temp);
    		else b.pb(temp);
    	}
    	ld ans = helper(a,b);
    	if(ans > 1e7) cout<<"Infinity\n";
    	else cout<<fixed<<setprecision(7)<<ans<<endl;
    }
    return 0;
}

