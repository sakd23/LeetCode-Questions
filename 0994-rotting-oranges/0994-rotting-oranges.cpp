class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
           int fans=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
    queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                                if(a[i][j]==2)
                                  {
                                    q.push({i,j});
                                    vis[i][j]=1;
                                  }
            }
        }
        
        while(!q.empty())
                    {
                        int siz=q.size();
            while(siz--)
            {
                pair<int,int> p=q.front();
                        q.pop();
                        int cr=p.first;
                        int cc=p.second;
                       
                       
                        for(int i=-1;i<=1;i++)
                        {
                            for(int j=-1;j<=1;j++)
                            {
                                if(abs(i-j)==1)
                                {
                                  if(cr+i>=0 and cr+i<m and cc+j<n and cc+j>=0 and a[cr+i][cc+j]==1 and !vis[cr+i][cc+j])
                                  {
                                      
                                      
                                      vis[cr+i][cc+j]=1;
                                      q.push({cr+i,cc+j});
                                      
                                  }
                                }
                            }
                        }
                
            }
            if(!q.empty())
            fans++;
                     } 
     
                       for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(a[i][j]==1 and !vis[i][j])
                            {
                                return -1;
                            }
                        }
                    }
        return fans;
    }
};