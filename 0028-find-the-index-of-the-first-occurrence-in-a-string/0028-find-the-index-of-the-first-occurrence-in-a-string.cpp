class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        vector<int> next(n,n);
        vector<int> ch(26,-1);

        for(int i=n-1;i>=0;i--)
        {
           if(ch[haystack[i]-'a']!=-1)next[i]=ch[haystack[i]-'a'];
           ch[haystack[i]-'a']=i;
        }
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(haystack[i]!=needle[j])continue;
            int curr=i;
            while(i<n and needle[j]==haystack[i])
            {
                i++;
                j++;
            }
            if(j>=m)
            {
                return curr;
            }
            i=next[curr]-1;
            j=0;
        }
        return -1;
    }
};