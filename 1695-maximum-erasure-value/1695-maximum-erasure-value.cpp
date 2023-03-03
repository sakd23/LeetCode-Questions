class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int sum=0,ans=0;
        map<int,int> map;
        int srt=0,n=a.size();
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            map[a[i]]++;
        
            while(map[a[i]]==2)
            {
                map[a[srt]]--;
                sum-=a[srt];
                srt++;
            }
            ans=max(ans,sum);
        }
        
        return ans;
        
    }
};