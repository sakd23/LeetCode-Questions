class Solution {
public:
    int help(vector<int>& a,vector<vector<vector<int>>>& dp,int i,int tran,int s)
    {
        if(i>=a.size())return 0;
        if(dp[i][tran][s]!=-1) return dp[i][tran][s];
        int ans;
        if(s==1)
        {
            if(tran==2)ans=help(a,dp,i+1,tran,1);
        else ans=max(a[i]+help(a,dp,i+1,tran+1,0),help(a,dp,i+1,tran,1));
        }
        if(s==0)
        {
            if(tran==2)ans=help(a,dp,i+1,tran,0);
            else ans=max(-a[i]+help(a,dp,i+1,tran,1),help(a,dp,i+1,tran,0));
        }
        
        
        return dp[i][tran][s]=ans;
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return help(a,dp,0,0,0);
    }
};