class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n-K) % (K-1) != 0) return -1;
        vector<int> cumsum(n+1);
        cumsum[0] = 0;
        for(int i=0; i<n; i++) cumsum[i+1] = cumsum[i] + stones[i];
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=K-1; l<n; l++){
            for(int x=0, y=x+l; x<n && y<n; x++, y++){
               if(l==K-1) dp[x][y] = cumsum[y+1] - cumsum[x];
                else{
                    dp[x][y] = INT_MAX;
                    for(int mid=x; mid<y; mid+=K-1)
                        dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid+1][y]);
                    if(l % (K-1) == 0)
                    dp[x][y] += cumsum[y+1] - cumsum[x];
                }
            }
        }
        return dp[0][n-1] !=INT_MAX ? dp[0][n-1] : -1;
    }
};