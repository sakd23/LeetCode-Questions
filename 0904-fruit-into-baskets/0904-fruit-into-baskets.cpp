class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n=f.size();
        int srt=0,ans=0;
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
           
               m[f[i]]++;
           
            while(m.size()>2)
            {
                m[f[srt]]--;
                if(m[f[srt]]==0)m.erase(f[srt]);
                srt++;
            }
            
            ans=max(ans,i-srt+1);
        }
        return ans;
    }
};