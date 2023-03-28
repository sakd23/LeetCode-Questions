class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size(),ans=1;
        vector<int> dp(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j]<a[i])
                dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};