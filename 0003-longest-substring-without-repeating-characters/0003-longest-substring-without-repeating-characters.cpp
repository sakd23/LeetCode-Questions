class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int> ch;
        int ans=0,srt=0;
        int n=s.size(),i=0;
       
        for( ;i<n;i++)
        {
            ch[s[i]]++;
            while(ch[s[i]]==2)
            {
                ch[s[srt]]--;
                srt++;
            }
            ans=max(ans,i-srt+1);
        }
        return ans;
    }
};