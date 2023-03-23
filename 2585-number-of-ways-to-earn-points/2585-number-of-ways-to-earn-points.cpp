class Solution {
public:
    int mod=1e9+7;
    int help(vector<vector<int>>& a,int tar,int idx,vector<vector<int>>&dp)
    {
        if(tar==0)return 1;
        if(idx==a.size() or tar<0)
        {
            return 0;
        }
       if(dp[idx][tar]!=-1)return dp[idx][tar];
        int ans2=0;
        for(int i=0;i<=a[idx][0];i++)
         ans2=(ans2+help(a,tar-i*a[idx][1],idx+1,dp))%mod;
        return  dp[idx][tar]=ans2;
    }
    int waysToReachTarget(int tar, vector<vector<int>>& a) {
        vector<vector<int>> dp(a.size()+1,vector<int>(tar+1,-1));
        
        
     return help(a,tar,0,dp);   
    }
};