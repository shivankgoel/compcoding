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

double dist(vector<double> &p1, vector<double> &p2){ 
    return hypot(p1[0] - p2[0], p1[1] - p2[1]); 
}

vector<double> tovec(vector<double> &p1, vector<double> &p2){
    return {p2[0]-p1[0], p2[1]-p1[1]};
}

double cross(vector<double> p1, vector<double> p2){
    return (p1[0]*p2[1]) - (p1[1]*p2[0]);
}

bool ccw(vector<double> &p, vector<double> &p1, vector<double> &p2){
    return cross(tovec(p, p1), tovec(p, p2)) > 0; 
}

bool collinear(vector<double> &p, vector<double> &p1, vector<double> &p2){
    return fabs(cross(tovec(p,p1), tovec(p,p2))) < EPS;
}

vector<double> pivot{0,0};
bool angleCmp(vector<double> &p1, vector<double> &p2){ 
    if (collinear(pivot, p1, p2))  return dist(pivot, p1) < dist(pivot, p2); 
    return atan2(p1[1] - pivot[1], p1[0] - pivot[0]) < atan2(p2[1] - pivot[1], p2[0] - pivot[0]); 
}

vector<vector<double>> convexhull(vector<vector<double>> &pts){

    int n = pts.size();
    if(n<=3){
        if(pts[0] != pts[n-1]) pts.push_back(pts[0]);
        return pts;
    } 

    int pidx = 0;
    for(int i=0; i<n; i++)
        if((pts[pidx][1] > pts[i][1]) || (pts[pidx][1] == pts[i][1] && pts[pidx][1] > pts[i][1]))
            pidx = i;


    pivot = pts[pidx];
    swap(pts[pidx], pts[0]);
    sort(++pts.begin(), pts.end(), angleCmp);
   

    vector<vector<double>> ans;
    ans.push_back(pts[0]);
    ans.push_back(pts[1]);
  
    int i=2;
    while(i<n){
        while(ans.size()>= 2 && !ccw(ans[ans.size()-2], ans[ans.size()-1], pts[i])){
            ans.pop_back();
        }
        ans.push_back(pts[i++]);
    }
    ans.push_back(ans[0]);
    return ans;
}


int main(){
    int t,n;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        cin>>n;
        vector<vector<double>> pts(n,vector<double>(2));
        for(int i=0; i<n; i++) cin>>pts[i][0]>>pts[i][1];
        int temp; 
        if(t) cin>>temp;
        auto ans = convexhull(pts);
        cout<<ans.size()<<endl;
        for(auto x: ans)cout<<x[0]<<" "<<x[1]<<endl;
        if(t) cout<<-1<<endl;
    }
    return 0;
}

