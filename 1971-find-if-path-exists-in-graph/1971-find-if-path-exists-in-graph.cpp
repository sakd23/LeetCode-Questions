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
        if(s==d)return true;
        vector<vector<int>> a(n);
      
        for(auto x:edges)
        {
            a[x[0]].push_back(x[1]);
            a[x[1]].push_back(x[0]);
        }
       queue<int> q;
        vector<int> vis(n,0);
        q.push(s);
       vis[s]=1;
        
        while(!q.empty())
        {
            int siz=q.size();
            for(int i=0;i<siz;i++)
            {
                int temp=q.front();
                if(temp==d)return true;
               
                q.pop();
                for(auto x:a[temp])
                {
                    if(!vis[x])
                    {
                        q.push(x);
                        vis[x]=1;
                    }
                }
            }
        }
        return false;
    }
};