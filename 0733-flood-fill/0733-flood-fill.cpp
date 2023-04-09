class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
        int m=a.size(),n=a[0].size();
      vector<vector<int>> vis(m,vector<int>(n,0));  
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int curr=a[sr][sc];
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            
            q.pop();
            
            int cr=p.first,cc=p.second;
           
                a[cr][cc]=color;
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    if(abs(i-j)==1)
                    {
                        if(cr+i>=0 and cr+i<m and cc+j>=0 and cc+j<n)
                        {
                            if(!vis[cr+i][cc+j] and a[cr+i][cc+j]==curr)
                            {
                                vis[cr+i][cc+j]=1;
                                q.push({cr+i,cc+j});
                            }
                        }
                    }
                }
            }
        }
        return a;
    }
};