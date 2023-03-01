class Solution {
public:
   int help(string s,int k,char ch)
    {
        int l=0,r=0,cnt=0,n=s.length(),res=0;
        while(r<n)
        {
            if(s[r]==ch)cnt++;
            
            while(cnt>k)
            {
                if(s[l]==ch)cnt--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(help(s,k,'T'),help(s,k,'F'));
    }
};