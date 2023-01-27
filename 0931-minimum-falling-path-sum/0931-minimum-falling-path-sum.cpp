class Solution {
public:
    int help(vector<vector<int>>& a,int i,int j,int row,int col,vector<vector<int>>& dp)
    {
        if(j>=col or j<0)return INT_MAX;
        
        if(i==row-1)return a[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=a[i][j]+min({help(a,i+1,j-1,row,col,dp),help(a,i+1,j+1,row,col,dp),help(a,i+1,j,row,col,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int ans=1e9;
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>> dp(200,vector<int>(200,-1));
        for(int i=0;i<col;i++)
        {
            ans=min(ans,help(matrix,0,i,row,col,dp));
        }
        return ans;
         
        
    }
};