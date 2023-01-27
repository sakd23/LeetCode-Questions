class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
        int n=a.size();
        int presum[n];
        presum[0]=a[0];
        map<int,int> mmap;
        mmap[a[0]]++;
        mmap[0]++;
        int ans=0;
        if(a[0]==k)ans++;
        for(int i=1;i<n;i++)
        {
            presum[i]=presum[i-1]+a[i];
            int req=presum[i]-k;
            if(mmap.count(req))ans+=mmap[req];
            
            mmap[presum[i]]++;
        }
        return ans;
    }
};