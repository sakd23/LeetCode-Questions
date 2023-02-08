class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int odd[n];
        odd[0]=0;
        int ans=0;
        if(nums[0]%2!=0)odd[0]=1;
        for(int i=1;i<n;i++)
        {
            odd[i]=odd[i-1];
            if(nums[i]%2!=0)odd[i]++;
        }
        int srt=0;
        for(int i=0;i<n;i++)
        {
            if(odd[i]<k)continue;
            int cnt=0;
            while(odd[srt]==odd[i]-k)
            {
                cnt++;
                srt++;
            }
            int curr=odd[i],cnt2=0;
            while(i<n and odd[i]==curr)
            {
                cnt2++;
                i++;
            }
            i--;
            if(curr==k)cnt++;
            // cout<<cnt<<" "<<cnt2<<endl;
            ans=ans+cnt*cnt2;
        }
        return ans;
    }
};