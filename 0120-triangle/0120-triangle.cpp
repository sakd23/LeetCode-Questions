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
    int minimumTotal(vector<vector<int>>& tri) {
        vector<int> dp(300),curr(300);
        int m=tri.size();
        for(int i=m-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==m-1)curr[j]=tri[i][j];
                else 
                {
                    curr[j]=tri[i][j]+min(dp[j],dp[j+1]);
                   
                }
            }
            
             dp=curr;
        }
        return dp[0];
    }
};