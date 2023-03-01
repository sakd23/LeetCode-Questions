class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
     map<char,int> m;
        
        int srt=0,cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
           m[s[i]]++;
            cnt=max(cnt,m[s[i]]);
          if(i-srt+1-k>cnt)
          {
             m[s[srt]]--; 
              srt++;
          }
            
        }
        return n-srt;
    }
};