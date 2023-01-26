class Solution {
public:
    int help(vector<vector<int>>& tri,int row,int col,vector<vector<int>>& dp)
    {
        if(col>row)
        {
            return 1e9;
        }
        if(row==tri.size()-1)
        {
            int n=tri.size();
            return tri[n-1][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        return dp[row][col]=tri[row][col]+min(help(tri,row+1,col,dp),help(tri,row+1,col+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(300,vector<int>(300,-1));
        
        return help(triangle,0,0,dp);
    }
};