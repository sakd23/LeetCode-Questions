class Solution {
public:
    typedef long long ll;
    
    int  help(int n,map<int,vector<int>>& map,int curr,vector<vector<int>>& dp)
    {
        int mod=1e9+7;
        int ans=0;
        if(n==0)return 1;
        if(dp[n][curr]!=-1)return dp[n][curr];
        for(auto x:map[curr])
        {
            ans=(ans+help(n-1,map,x,dp))%mod;
        }
      return dp[n][curr]=ans;
    }
    
    int countVowelPermutation(int n) {
        map<int,vector<int>> map;
        map[0].push_back('e'-'a');
        map['e'-'a'].push_back('i'-'a');
        map['e'-'a'].push_back(0);
        map['i'-'a'].push_back('e'-'a');
        map['i'-'a'].push_back('o'-'a');
        map['i'-'a'].push_back('u'-'a');
        map['i'-'a'].push_back(0);
        map['u'-'a'].push_back(0);
        map['o'-'a'].push_back('i'-'a');
        map['o'-'a'].push_back('u'-'a');
    vector<vector<int>> dp(n,vector<int>(30,-1));
        int ans=0;
        int mod=1e9+7;
        vector<char> ch={'a','e','i','o','u'};
        for(auto x:ch)
        {
            ans=(ans+help(n-1,map,x-'a',dp))%mod;
        }
    return ans;
    }
};