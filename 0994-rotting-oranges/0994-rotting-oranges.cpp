class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX)),vis(m,vector<int>(n,0));
   
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==2)
                {
                     queue<pair<int,int>> q;
                   
                    ans[i][j]=0;
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty())
                    {
                        pair<int,int> p=q.front();
                        q.pop();
                        int cr=p.first;
                        int cc=p.second;
                         int curr=ans[cr][cc];
                        // cout<<curr<<endl;
                        for(int i=-1;i<=1;i++)
                        {
                            for(int j=-1;j<=1;j++)
                            {
                                if(abs(i-j)==1)
                                {
                                  if(cr+i>=0 and cr+i<m and cc+j<n and cc+j>=0 and a[cr+i][cc+j]==1 and !vis[cr+i][cc+j])
                                  {
                                      
                                      ans[cr+i][cc+j]=min(curr+1,ans[cr+i][cc+j]);
                                      vis[cr+i][cc+j]=1;
                                      q.push({cr+i,cc+j});
                                      
                                  }
                                }
                            }
                        }
                    }
                    
                    for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            vis[i][j]=0;
                        }
                    }
                }
            }
        }
        int fans=0;
                       for(int i=0;i<m;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(a[i][j]==1)
                            {
                                if(ans[i][j]==INT_MAX)return -1;
                                
                                fans=max(fans,ans[i][j]);
                            }
                        }
                    }
        return fans;
    }
};