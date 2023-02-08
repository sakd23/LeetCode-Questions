class Solution {
public:
    
    void help(int bits[],int a)
    {
        int curr=0;
        while(a>0)
        {
            if((a&1))
            {
              bits[curr]++;  
            }
            curr++;
            a=(a>>1);
        }
        
    }
    
    void help2(int bits[],int a)
    {
        int curr=0;
        while(a>0)
        {
            if((a&1))
            {
              bits[curr]--;  
            }
            curr++;
            a=(a>>1);
        }
        
    }
    int longestNiceSubarray(vector<int>& nums) {
        int bits[50]={0};
        int ans=0,n=nums.size(),srt=0;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            help(bits,nums[i]);
            for(auto x:bits)
            {
                if(x>1)
                {
                    flag=false;
                    break;
                }
            }
            
            while(!flag)
            {
               help2(bits,nums[srt]);
                bool flag1=true;
                for(auto x:bits)
            {
                if(x>1)
                {
                    flag1=false;
                    break;
                }
            }
                if(flag1)flag=true;
                srt++;
            }
            
            ans=max(ans,i-srt+1);
        }
        return ans;
    }
};