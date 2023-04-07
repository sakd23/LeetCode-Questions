class Solution {
public:
    bool dfs(vector<vector<int>>& a,int n,int s,int d,vector<int>& vis)
    {
        if(s==d)return true;
        vis[s]=1;
        bool ans=false;
       
        for(auto x:a[s])
        {
            if(!vis[x])
            {
             ans=ans or dfs(a,n,x,d,vis);  
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> a(n);
        vector<int> vis(n+1,0);
        for(auto x:edges)
        {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
        return dfs(a,n,s,d,vis);
    }
};