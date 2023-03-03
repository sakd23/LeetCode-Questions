class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int> ch;
        int ans=0,srt=-1;
        int n=s.size(),i=0;
       
        for( ;i<n;i++)
        {
           if(ch.count(s[i])==0)ch[s[i]]=-1;
           srt=max(ch[s[i]],srt);
            ans=max(ans,i-srt);
            // cout<<ans<<endl;
            ch[s[i]]=i;
        }
        return ans;
    }
};