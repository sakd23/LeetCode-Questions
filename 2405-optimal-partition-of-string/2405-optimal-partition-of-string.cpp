class Solution {
public:
    int partitionString(string s) {
        vector<int> v(26,0);
        int n=s.size(),ans=1;
        for(int i=0;i<n;i++)
        {
            char ch=s[i]-'a';
            v[ch]++;
            for(auto x:v)
            {
                if(x>1)
                {
                    ans++;
                    fill(v.begin(),v.end(),0);
                    v[ch]++;
                    break;
                }
            }
        }
        return ans;
    }
};