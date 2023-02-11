class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int curr=1;
        int m[3010]={0},ans;
        
        for(auto x:arr)
        {
            m[x]++;
        }
        
        for(int i=1;i<=3000;i++)
        {
            if(m[i]==0)k--;
            if(k==0)
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};