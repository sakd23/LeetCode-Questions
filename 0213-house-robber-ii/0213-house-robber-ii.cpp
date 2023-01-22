class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1)return a[0];
        int dp1[n],dp2[n];
        
        dp1[0]=0;
        dp1[1]=a[1];
        dp2[0]=a[0];
        dp2[1]=a[0];
        
        for(int i=2;i<n;i++)
        {
            
            dp1[i]=max(dp1[i-1],a[i]+dp1[i-2]);
            dp2[i]=max(dp2[i-1],a[i]+dp2[i-2]);
            
            if(i==n-1)dp2[i]=dp2[i-1];

        }
        return max(dp1[n-1],dp2[n-1]);
    }
};