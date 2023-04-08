class Solution {
public:
    void dfs(vector<vector<int>>& adj,int n,int v,vector<int>& vis)
    {
        vis[v]=1;
        
        for(int i=0;i<n;i++)
        {
            if(i==v)continue;
            if(adj[v][i] and !vis[i])
            {
                dfs(adj,n,i,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int ans=0,n=adj.size();
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(adj,n,i,vis);
            }
        }
        return ans;
    }
};