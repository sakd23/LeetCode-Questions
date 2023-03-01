class Solution {
public:
    vector<string> letterCombinations(string s) {
        int n=s.size();
         vector<string> ans;
        if(n==0)return ans;
       vector<string> chars{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       
        int digit=s[n-1]-'0';
        string curr=chars[digit];
        for(auto x:curr)
        {
            // cout<<x<<endl;
            string st;
            st=st+x;
            ans.push_back(st);
        }
        for(int i=n-2;i>=0;i--)
        {
            int csize=ans.size();
            int digit=s[i]-'0';
        string curr=chars[digit];
            for(int j=1;j<curr.size();j++)
            {
                for(int k=0;k<csize;k++)
                {
                    ans.push_back(curr[j]+ans[k]); 
                }
               
            }
            for(int k=0;k<csize;k++)
                {
                    ans[k]=curr[0]+ans[k]; 
                }
            
        }
        return ans;
        
    }
};