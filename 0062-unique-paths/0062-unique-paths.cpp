class Solution {
public:
    
    int help(int i,int j,int m,int n,vector<vector<int>>& dp)
    {
       if(i==m-1 and j==n-1)return 1;
        
        if(i>=m or j>=n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=help(i+1,j,m,n,dp)+help(i,j+1,m,n,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<int> dp(100,1);
        
       for(int i=m-2;i>=0;i--)
       {
           for(int j=n-2;j>=0;j--)
           dp[j]=dp[j]+dp[j+1];
       }
        return dp[0];
    }
};