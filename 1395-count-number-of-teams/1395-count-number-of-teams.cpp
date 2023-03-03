class Solution {
public:
    int numTeams(vector<int>& a) {
        int n=a.size();
        
        int dp[n],ans=0;
        int dp2[n];
        memset(dp,0,sizeof(dp));
                memset(dp2,0,sizeof(dp));

        for(int i=0;i<n;i++)
        {
         for(int j=i+1;j<n;j++)
         {
             if(a[i]<a[j])dp[i]++;
             if(a[i]>a[j])dp2[i]++;
         }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
         {
             if(a[i]<a[j])ans+=dp[j];
                if(a[i]>a[j])ans+=dp2[j];
         } 
        }
        return ans;
    }
};