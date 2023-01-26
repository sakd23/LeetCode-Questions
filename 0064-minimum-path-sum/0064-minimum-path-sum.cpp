class Solution {
public:
    int help(vector<vector<int>>& g,int i,int j,int m,int n,vector<vector<int>>& dp)
    {
        if(i==m-1 and j==n-1)
        {
            return g[i][j];
        }
        if(j>=n or i>=m)
        {
            return 1e9;
        }
         if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=g[i][j]+min(help(g,i+1,j,m,n,dp),help(g,i,j+1,m,n,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(210,vector<int>(210,-1));
        return help(grid,0,0,grid.size(),grid[0].size(),dp);
    }
};