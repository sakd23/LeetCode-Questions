class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
       map<int,int> map;
        int n=a.size();
        int ans=n+1;
        for(int i=0;i<n;i++)
        {
            if(map.count(a[i])!=0)
            {
                ans=min(ans,i-map[a[i]]+1);
            }
            map[a[i]]=i;
        }
        return ans==n+1?-1:ans;
    }
};