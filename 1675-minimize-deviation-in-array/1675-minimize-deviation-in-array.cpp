class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<long long> st;
        
        for(auto x:nums)
        {
            if(x%2)st.insert(x*2);
            else st.insert(x);
        }
        long long ans= (*st.rbegin()-*st.begin());
        while((*st.rbegin())%2==0)
        {
            st.insert((*st.rbegin())/2);
            st.erase((*st.rbegin()));
            ans=min(ans,(*st.rbegin()-*st.begin()));
        }
        return ans;
    }
};