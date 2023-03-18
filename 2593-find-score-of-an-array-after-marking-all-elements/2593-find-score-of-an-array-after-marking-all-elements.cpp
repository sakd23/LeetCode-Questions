class Solution {
public:
    long long findScore(vector<int>& a) {
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         int n=a.size();
        long long ans=0;
        for(int i=0;i<a.size();i++)
        {
            pq.push({a[i],i});
        }
        vector<bool> v(n,false);
        while(!pq.empty())
        {
           if(v[pq.top().second])
           {
               pq.pop();
               continue;
           }
            ans+=(long long)pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            if(idx>0)
            v[idx-1]=true;
            if(idx<n-1)
            {
              v[idx+1]=true;
            }
        }
        return ans;
    }
};