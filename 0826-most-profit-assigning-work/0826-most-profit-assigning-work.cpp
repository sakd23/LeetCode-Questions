class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n=d.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({d[i],p[i]});
        }
        sort(v.begin(),v.end());
        map<int,int> map;
        int maxele=v[0].second;
        map[v[0].first]=maxele;
        for(int i=1;i<n;i++)
        {
            if(v[i].second>maxele)
            {
               maxele=v[i].second;
            }
            else
            {
              v[i].second=maxele;  
            }
            // cout<<maxele<<endl;
            map[v[i].first]=maxele;
        }
        int ans=0;
        sort(d.begin(),d.end());
        for(auto x:w)
        {
            int idx=lower_bound(d.begin(),d.end(),x)-d.begin();
            
            if(d[idx]!=x)
            {
                if(idx==0)
                {
                    continue;
                }
                idx--;
            }
            ans+=map[d[idx]];
         // cout<<d[idx]<<endl;
        }
        return ans;
    }
};