class Solution {
public:
    int help(vector<int>& a,vector<vector<int>>& dp,int i,int st)
    {
        if(i>=a.size())return 0;
        if(dp[i][st]!=-1)return dp[i][st];
        int ans;
        if(st==0)ans=max(help(a,dp,i+1,1)-a[i],help(a,dp,i+1,st));
        else ans=max(help(a,dp,i+1,0)+a[i],help(a,dp,i+1,st));
        return dp[i][st]=ans;
    }
    int maxProfit(vector<int>& a) {
        int n=a.size();
        // int dp[n+1][2];
        vector<vector<int>>  dp(n+1,vector<int>(2,-1));
//       memset(dp,0,sizeof(dp));
        
//         for(int i=n-1;i>=0;i--)
//         {
//             dp[i][1]=max(a[i]+dp[i+1][0],dp[i+1][1]);
//             dp[i][0]=max(dp[i+1][1]-a[i],dp[i+1][0]);
//         }
        return help(a,dp,0,0);
    }
};