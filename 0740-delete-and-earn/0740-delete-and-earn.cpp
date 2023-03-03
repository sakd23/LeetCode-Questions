class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        map<int,int> map;
        int n=a.size();
        for(auto x:a)map[x]++;
        
        sort(a.begin(),a.end());
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--)
        {
            int ans=dp[i+1];
            int curr=a[i],idx=i;
            while(idx<n and (a[idx]==curr or a[idx]==curr+1))idx++;
            ans=max(ans,map[curr]*curr+dp[idx]);
            dp[i]=ans;
                        // cout<<ans<<endl;

            
        }
        return dp[0];
    }
};