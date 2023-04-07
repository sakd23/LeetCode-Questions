class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n1=a.length();
        int n2=b.length();
    
      int  dp[n1+1][n2+1];

        for(int i=0;i<=n1;i++)
        {
            dp[i][n2]=0;
        }

        for(int i=0;i<=n2;i++)
        {
            dp[n1][i]=0;
        }

        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(a[i]==b[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
       int s1=0,s2=0;
        string ans;
        while(s1<n1 and s2<n2)
        {
            if(a[s1]==b[s2])
            {
                ans=ans+a[s1];
                s1++;
                s2++;
            }
            else if(dp[s1+1][s2]>dp[s1][s2+1])
            {
                ans=ans+a[s1];
                s1++;
            }
            else{
                ans=ans+b[s2];
                s2++;
            }
        }
        while(s1<n1)
        {
            ans=ans+a[s1];
                s1++;
        }
        
         while(s2<n2)
        {
            ans=ans+b[s2];
                s2++;
        }
        return ans;
    }
};