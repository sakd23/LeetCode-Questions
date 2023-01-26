class Solution {
public:
    // int help(vector<vector<int>>& g,int i,int j,int m,int n,vector<vector<int>>& dp)
    // {
    //     if(i==m-1 and j==n-1)
    //     {
    //         return g[i][j];
    //     }
    //     if(j>=n or i>=m)
    //     {
    //         return 100000;
    //     }
    //      if(dp[i][j]!=-1)return dp[i][j];
    //     return dp[i][j]=g[i][j]+min(help(g,i+1,j,m,n,dp),help(g,i,j+1,m,n,dp));
    // }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(210,vector<int>(210,-1));
        int m=grid.size(),n=grid[0].size();
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-2;i>=0;i--)
        {
            dp[i][n-1]=dp[i+1][n-1]+grid[i][n-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            dp[m-1][i]=dp[m-1][i+1]+grid[m-1][i];
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=n-2;j>=0;j--)
            {
                dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};