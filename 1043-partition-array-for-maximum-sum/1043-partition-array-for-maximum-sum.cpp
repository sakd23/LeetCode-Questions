class Solution {
public:
    int help(vector<int>& a,int s,int k,vector<int>& dp)
    {
        if(s>=a.size())
        {
            return 0;
        }
        if(dp[s]!=-1)return dp[s];
        int curr=a[s],ans=INT_MIN;
        for(int i=0;i<k;i++)
        {
             if(s+i>=a.size())break;
          curr=max(curr,a[s+i]);
          int pans=INT_MIN;
           
          pans=(i+1)*curr+help(a,s+i+1,k,dp);
          ans=max(ans,pans); 
          // cout<<ans<<endl;
        }
        return dp[s]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
      int n=arr.size();
        vector<int> dp(n+1,-1);
        return help(arr,0,k,dp);
    }
};