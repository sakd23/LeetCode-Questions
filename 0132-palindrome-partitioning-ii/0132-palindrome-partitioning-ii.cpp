class Solution {
public:
    bool pal(string& str,int s,int e)
    {
        while(s<e)
        {
            if(str[s]!=str[e])return false;
            s++;
            e--;
        }
        return true;
    }
    int help(string s,int srt,int n,vector<int>& dp)
    {
          if(srt>=n)return 0;
        if(pal(s,srt,n))return 0;
      
        if(dp[srt]!=-1)return dp[srt];
        int fans=INT_MAX;
        for(int i=srt;i<n;i++)
        {
            if(pal(s,srt,i))
            {
            int ans=1+help(s,i+1,n,dp);
            fans=min(fans,ans);
            }
            
        }
        return dp[srt]=fans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return help(s,0,n-1,dp);
    }
};