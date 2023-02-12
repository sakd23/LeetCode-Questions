class Solution {
public:
    int minimumScore(string s, string t) {
        int ss=s.length(),st=t.length(),k=st-1;
        vector<int> dp(st,-1);
        for(int i=ss-1;i>=0 and k>=0;i--)
        {
            if(s[i]==t[k])
            {
                dp[k]=i;
                k--;
            }
        }
        int res=k+1;
        for(int i=0,j=0;i<ss and j<st and res>0;i++)
        {
            if(s[i]==t[j])
            {
                while(k<st and i>=dp[k])k++;
                res=min(res,k-j-1);
                j++;
            }
        }
        return res;
    }
};