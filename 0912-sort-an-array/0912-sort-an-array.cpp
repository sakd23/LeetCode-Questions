class Solution {
public:
    vector<int> msort(vector<int>& a)
    {
        if(a.size()==1)return {a[0]};
        vector<int> fir;
        vector<int> sec;
        int n=a.size();
        for(int i=0;i<n/2;i++)
        {
            fir.push_back(a[i]);
        }
        
         for(int i=n/2;i<n;i++)
        {
            sec.push_back(a[i]);
        }
        fir=msort(fir);
        sec=msort(sec);
        
        vector<int> ans;
        
        int s1=0,s2=0;
        
        while(s1<fir.size() and s2<sec.size())
        {
            if(fir[s1]<sec[s2])
            {
                ans.push_back(fir[s1]);
                s1++;
            }
            else
            {
                ans.push_back(sec[s2]);
                s2++;
            }
        }
        while(s1<fir.size())
        {
            ans.push_back(fir[s1]);
            s1++;
        }
        
        while(s2<sec.size())
        {
            ans.push_back(sec[s2]);
            s2++;
        }
        
        return ans;    
    }
    vector<int> sortArray(vector<int>& nums) {
        return msort(nums);
    }
};