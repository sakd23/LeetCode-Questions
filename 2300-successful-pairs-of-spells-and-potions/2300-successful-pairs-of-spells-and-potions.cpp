class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long k) {
        sort(b.begin(),b.end());
        vector<int> ans;
        for(auto x:a)
        {
            if(x>=k)
            {
                ans.push_back(b.size());
                continue;
            }
            long long needed=(k+x-1)/x;
            if(needed>1e5)
            {
                ans.push_back(0);
                continue;
            }
            int need=(int)needed;
            int idx=lower_bound(b.begin(),b.end(),need)-b.begin();
            
           ans.push_back(b.size()-idx);
        }
        return ans;
    }
};