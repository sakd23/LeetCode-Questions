class Solution {
public:
    int help(int i,int j,int n,int m,vector<vector<int>>& a,vector<vector<int>>& dp)
    {
        if(i>=n or j>=m)return 0;
        
        if(a[i][j]==1)return 0;
        
        if(i==n-1 and j==m-1)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=help(i+1,j,n,m,a,dp)+help(i,j+1,n,m,a,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      vector<vector<int>> dp(105,vector<int>(105,-1));
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return help(0,0,n,m,obstacleGrid,dp);
    }
};