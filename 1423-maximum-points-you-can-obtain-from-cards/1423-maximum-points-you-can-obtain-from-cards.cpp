class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int dp[n],dp2[n];
        dp[0]=a[0];
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1]+a[i];
        }
        dp2[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dp2[i]=dp2[i+1]+a[i];
        }
       int ans=max(dp2[n-k],dp[k-1]);
        for(int i=1;i<k;i++)
        {
            ans=max(ans,dp[i-1]+dp2[n-k+i]);
        }
        return ans;
    }
};