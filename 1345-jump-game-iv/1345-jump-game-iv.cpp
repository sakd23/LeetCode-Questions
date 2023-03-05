class Solution {
public:
    int minJumps(vector<int>& a) {
     map<int,vector<int>> map;
        int n=a.size();
        vector<bool> vis(n,false);
        vis[0]=true;
        for(int i=0;i<n;i++)
        {
           map[a[i]].push_back(i);
            
        }
        
  queue<int> q;
        q.push(0);
        int steps=0;
        
        while(!q.empty())
        {
            int csize=q.size();
            for(int siz=csize-1;siz>=0;--siz)
            {
                int curr=q.front();
                q.pop();
                if(curr==n-1)return steps;
                
                
                
               vector<int>&  next=map[a[curr]];
                next.push_back(curr+1);
                next.push_back(curr-1);
                for(auto x:next)
                {
                    if(x>=0 and x<n and !vis[x])
                    {
                        vis[x]=true;
                        q.push(x);
                    }
                }
                next.clear();
            }
            
            steps++;
        }
        return 0;
    }
};