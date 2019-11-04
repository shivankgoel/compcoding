#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef unordered_map<int,int> umpii;

int main(){
    int t,m,n;
    cin>>t;
    while(t--){

    }
    return 0;
}


class {
    public:

};



class fenwick{
    public:
    vector<int> A;
    int n;

    fenwick(int sz){
        n = sz;
        A.resize(sz+1, 0);
    }

    fenwick(vector<int> &nums){
        n = nums.size();
        A.resize(n+1, 0);
        for(int i=1; i<=n; i++) A[i] = nums[i-1];
        for(int i=1; i<=n; i++){
            int next = i + (i & -i);
            if(next <= n) A[next] += A[i];
        } 
    }

    void add(int i, int val){
        int t = i+1;
        while(t<=n){
            A[t]+= val;
            t += (t & -t);
        }
    }

    int range(int i, int j){
        return sum(j) - sum(i-1);
    }

    int sum(int i){
        int t = i+1;
        int ans = 0;
        while(t>0){
            ans+= A[t];
            t-= (t & -t);
        }
        return ans;
    }

};


class segmenttree{
    public:
    vector<int> arr;
    int n;
    
    segmenttree(vector<int>& nums){
        n = nums.size();
        arr.resize(n*2,0);
        for(int i=0, j=n; j < 2*n; i++, j++) arr[j] = nums[i];
        //left child 2i right child 2i+1
        for(int i=n-1; i>0; i--) arr[i] = arr[i*2] + arr[i*2+1];
    }
    
    void update(int i, int val){
        i = i+n;
        arr[i] = val;
        while(i > 0){
            //right child is always odd
            int l = (i%2 == 1) ? i-1 : i;
            int r = (i%2 == 1) ? i : i+1;
            i/=2;
            arr[i] = arr[l] + arr[r];
        }
    }
    
    int range(int l, int r){
        l+=n; r+=n;
        int sum = 0;
        while(l<=r){
            if(l%2==1) sum+= arr[l++];
            if(r%2==0) sum+= arr[r--];
            l/=2; r/=2;
        }
        return sum;
    }
    
};



class unionfind{
    public:
    vector<int> arr;
    
    unionfind(int n){
        for(int i=0; i<n; i++) arr.push_back(i);
    }
    
    int find(int x){
        if(arr[x]!=x) arr[x] = find(arr[x]);
        return arr[x];
    }
    
    void unite(int a, int b){
        arr[find(a)] = find(b);
    }
};




class Trie {
public:
    unordered_map<char, Trie*> mp;
    bool end;
    Trie(){
        end = false;
    }
    void insert(string word){
        Trie* temp = this;
        for(char c:word){
            if(!temp->mp[c]) temp->mp[c] = new Trie();
            temp = temp->mp[c];
        }
        temp->end = true;
    }
    bool search(string word) {
        Trie* temp = this;
        for(char c: word){
            if(!temp->mp[c]) return false;
            temp = temp->mp[c];
        }
        if(!temp->end)return false;
        return true;
    }
    bool hasprefix(string prefix) {
        Trie* temp = this;
        for(char c: prefix){
            if(!temp->mp[c]) return false;
            temp = temp->mp[c];
        }
        return true;
    }
};






