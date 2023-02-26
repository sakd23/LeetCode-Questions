class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0)
        {
            return word2.size();
        }
        
        if(word2.size()==0)
        {
            return word1.size();
        }
        vector<int> curr(word2.size()+1,0),next(word2.size()+1,0);
        curr[word2.size()]=1;
        for(int i=0;i<=word2.size();i++)
        {
            next[i]=word2.size()-i;
        }
        
        for(int i=word1.size()-1;i>=0;i--)
        { 
            curr[word2.size()]=word1.size()-i;
            
            for(int j=word2.size()-1;j>=0;j--)
            {
                if(word1[i]==word2[j])
                {
                    curr[j]=next[j+1];
                }
                
                else
                {
                    curr[j]=1+min(curr[j+1],min(next[j],next[j+1]));
                }
                
                // cout<<curr[j]<<" ";
            }
            
            next=curr;
              
        }
        return curr[0];
    }
};