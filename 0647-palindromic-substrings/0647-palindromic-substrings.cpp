class Solution {
public:

    int countSubstrings(string s) {
        int n=s.size();
        
        int ans=0;
       for(int i=0;i<n;i++)
       {
           int l=i,r=i;
           while(l>=0 and r<n)
           {
               if(s[l]!=s[r])break;
               if(s[l]==s[r])ans++;
               l--;
               r++;
           }
           l=i,r=i+1;
            while(l>=0 and r<n)
           {
               if(s[l]!=s[r])break;
               if(s[l]==s[r])ans++;
               l--;
               r++;
           }
       }
       return ans;
    }
};