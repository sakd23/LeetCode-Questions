class Solution {
public:
    int minimumScore(string s, string t) {
        int ss=s.length(),st=t.length(),k=st-1;
        vector<int> dp(st,-1);
        vector<int> dp2(st,ss);

        for(int i=ss-1;i>=0 and k>=0;i--)
        {
            if(s[i]==t[k])
            {
                dp[k]=i;
                k--;
            }
        }
        int ans=st;
        for(int i=0,j=0;i<ss and j<st;i++)
        {
            if(s[i]==t[j])
            {
                dp2[j]=i;
                ans=min(ans,st-j-1);
                j++;
            }
        }
      
        int i=st-1;
        while(i>=0 and dp[i]!=-1)
        {
         int lb=lower_bound(dp2.begin(),dp2.end(),dp[i])-dp2.begin();
           int ub=0;
            if(lb>0)ub=dp2[lb-1];
            
            ans=min({ans,i-lb});
            
            i--;
        }
        
        return max(0,ans);
    }
};