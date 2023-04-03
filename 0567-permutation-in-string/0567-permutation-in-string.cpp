class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ch[26]={0},ch2[26]={0},cnt=0,srt=0;
        
        for(auto x:s1)
        {
            ch[x-'a']++;
        }
        int n=s2.size();
        for(int i=0;i<n;i++)
        {
            int curr=s2[i]-'a';
            ch2[curr]++;
            cnt++;
          while(ch2[curr]>ch[curr])
          {
              int curr2=s2[srt]-'a';
              ch2[curr2]--;
              cnt--;
              srt++;
          }
            if(cnt==s1.size())
            {
                return true;
            }
            
            
        }
        return false;
    }
};