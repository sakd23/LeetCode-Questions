class Solution {
public:
    void help(vector<int>& c,int s, int t,vector<vector<int>>& ans,vector<int>& cans,vector<int>& count)
    {
        if(t==0)
        {
            ans.push_back(cans);
            return;
        }
        
        if(t<0 or s==c.size())
        {
            return;
        }
        

        
           if(count[c[s]]>0)
            {
             cans.push_back(c[s]);
                count[c[s]]--;
            help(c,s,t-c[s],ans,cans,count); 
                count[c[s]]++;
                cans.pop_back();
            }
        help(c,s+1,t,ans,cans,count);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
       vector<vector<int>> ans;
        vector<int> cans;
                vector<int> a;

        vector<int> count(51,0);
        for(auto x:c)
        {
            if(count[x]==0)
            {
             a.push_back(x);   
            }
            count[x]++;
        }
        sort(c.begin(),c.end());
        help(a,0,t,ans,cans,count);
        return ans;
    }
};