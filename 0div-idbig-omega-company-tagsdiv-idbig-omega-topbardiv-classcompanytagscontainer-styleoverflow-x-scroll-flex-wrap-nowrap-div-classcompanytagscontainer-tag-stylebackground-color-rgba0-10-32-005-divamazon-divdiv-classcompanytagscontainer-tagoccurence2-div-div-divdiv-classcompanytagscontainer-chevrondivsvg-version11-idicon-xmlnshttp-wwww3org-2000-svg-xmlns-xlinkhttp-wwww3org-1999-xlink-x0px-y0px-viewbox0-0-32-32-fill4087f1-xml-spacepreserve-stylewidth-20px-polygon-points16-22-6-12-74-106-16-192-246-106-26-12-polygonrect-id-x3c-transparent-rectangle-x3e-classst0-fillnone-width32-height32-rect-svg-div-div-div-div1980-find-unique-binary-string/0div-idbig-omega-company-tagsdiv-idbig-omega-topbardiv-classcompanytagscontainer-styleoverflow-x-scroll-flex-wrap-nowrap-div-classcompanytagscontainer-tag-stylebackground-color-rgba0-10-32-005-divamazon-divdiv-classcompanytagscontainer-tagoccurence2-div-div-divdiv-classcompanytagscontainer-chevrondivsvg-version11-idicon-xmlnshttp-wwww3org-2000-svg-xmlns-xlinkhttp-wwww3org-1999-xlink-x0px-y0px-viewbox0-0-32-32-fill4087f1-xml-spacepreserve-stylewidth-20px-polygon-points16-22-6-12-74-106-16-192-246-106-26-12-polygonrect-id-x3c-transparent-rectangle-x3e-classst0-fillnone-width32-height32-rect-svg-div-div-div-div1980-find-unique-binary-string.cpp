class Solution {
public:
    string ans;
    void help(int n,string s,int idx,vector<string>& nums)
    {
        if(idx==n)
        {
            if(find(nums.begin(),nums.end(),s)==nums.end())
            {
                ans=s;
            }
        return;
        }
        help(n,s+'0',idx+1,nums);
        help(n,s+'1',idx+1,nums);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        help(nums.size(),"",0,nums);
        return ans;
    }
};