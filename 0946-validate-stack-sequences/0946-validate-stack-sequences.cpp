class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     stack<int> st;
        int j=0,n=popped.size();
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            
            st.push(pushed[i]);
            while(!st.empty() and st.top()==popped[j])
            {
                st.pop();
                j++;
                flag=true;
            }
           
           
            
        }
        return st.empty();
    }
};