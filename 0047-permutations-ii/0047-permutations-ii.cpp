class Solution {
public:
    void help(set<vector<int>>& ans,vector<int>& a,int idx)
    {
        if(idx>=a.size())
        {
            ans.insert(a);
            return;
        }
        for(int i=idx;i<a.size();i++)
        {
            swap(a[i],a[idx]);
            help(ans,a,idx+1);
            swap(a[i],a[idx]);

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        help(st,nums,0);
        for(auto x:st)ans.push_back(x);
        return ans;
    }
};