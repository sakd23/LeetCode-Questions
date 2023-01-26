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
        vector<int> dp(210);
        int m=grid.size(),n=grid[0].size();
        
       
        
        for(int i=m-1;i>=0;i--)
        {
            
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)dp[j]=grid[i][j];
               else if(i==m-1)dp[j]=dp[j+1]+grid[i][j];
               else if(j==n-1)dp[j]=dp[j]+grid[i][j];
               else dp[j]=grid[i][j]+min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};