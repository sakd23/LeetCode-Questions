class Solution {
public:
    int help(vector<int>& a,int idx,int fee,vector<vector<int>>& dp,int st)
    {
        if(idx==a.size())return 0;
        if(dp[idx][st]!=-1)return dp[idx][st];
        int ans;
        if(st==0)ans=max(help(a,idx+1,fee,dp,st),help(a,idx+1,fee,dp,1)-a[idx]);
        if(st==1) ans=max(help(a,idx+1,fee,dp,st),help(a,idx+1,fee,dp,0)-fee+a[idx]);
        
        return dp[idx][st]=ans;
    }
    
    int maxProfit(vector<int>& a, int fee) {
        int  n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return help(a,0,fee,dp,0);
    }
};