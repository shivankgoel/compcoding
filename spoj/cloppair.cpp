#include <bits/stdc++.h>
using namespace std;

vector<double> closestpoints(vector<vector<int>> &v, int n){
	sort(v.begin(), v.end());
	long long dx = v[0][0] - v[1][0];
	long long dy = v[0][1] - v[1][1];
	double ans = sqrt((dx*dx) + (dy*dy)), ansx=0, ansy=1;
  //sort points according to y-coord
	set<vector<long long>> s; 
	int l = 0;
	s.insert({v[0][1], v[0][0], v[0][2]});
	s.insert({v[1][1], v[1][0], v[1][2]});
	for(int i=2; i<n; i++){
		while(v[i][0] - v[l][0] >= ans){
			s.erase({v[l][1], v[l][0], v[l][2]});
			l++;
		}
		long long a = v[i][1] - floor(ans);
		long long b = v[i][1] + ceil(ans);
		auto it1 = s.lower_bound({a, v[i][0], v[i][2]});
    auto it2 = s.upper_bound({b, v[i][0], v[i][2]});

    for(auto it = it1; it!=it2; it++){
    	dx = v[i][0] - (*it)[1];
    	dy = v[i][1] - (*it)[0];
    	double t = sqrt((dx*dx) + (dy*dy));
    	if(t < ans){
    		ans = t;
    		ansx = (*it)[2];
    		ansy = v[i][2];
    		if(ansx > ansy) swap(ansx, ansy);
    	}
    }
    s.insert({v[i][1], v[i][0], v[i][2]});
	}
	return {ansx, ansy, ans};
}

int main(){
	int n;
    cin>>n;
   	vector<vector<int>> v(n, vector<int>(3));
   	for(int i=0; i<n; i++){
   		cin>>v[i][0]>>v[i][1];
   		v[i][2] = i;
   	}
   	auto temp = closestpoints(v, n);
   	cout<<(int)temp[0]<<" "<<(int)temp[1]<<" "<<std::fixed<<setprecision(6)<<temp[2];
    return 0;
}


