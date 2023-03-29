class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     map<int,int> m;
        
        for(auto num:nums)
        {
            m[num]++;
            if(m.count(num)>0 and m[num]>1)
            {
                return true;
            }
             
            
        }
        return false;
    }
};