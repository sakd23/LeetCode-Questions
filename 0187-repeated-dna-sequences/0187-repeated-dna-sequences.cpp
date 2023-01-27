class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       map<string,int> m;
        if(s.length()<10)return {};
        string curr;
        for(int i=0;i<10;i++)
        {
            curr=curr+s[i];
        }
        m[curr]++;
        for(int i=10;i<s.length();i++)
        {
            curr=curr.substr(1);
            curr=curr+s[i];
            m[curr]++;
            
        }
         vector<string> ans;
        for(auto x:m)
        {
            if(x.second>1)ans.push_back(x.first);
        }
          return ans;  
    }
};