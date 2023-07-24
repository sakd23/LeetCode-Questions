//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    string bfs(vector<vector<int>>& adj,int n)
{
   
     vector<int> indeg(n,0);
       string topo;    
        for(int i=0;i<n;i++)
        {
            for(auto x:adj[i])
            {
         
          indeg[x]++;
            }
           
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            // cout<<indeg[i]<<endl;
            if(indeg[i]==0)
            {
                q.push(i);
               char ch=(i+'a');
                       topo=topo+ch;
            }
        }
   
        while(!q.empty())
        {
            int siz=q.size();
            while(siz--)
            {
               int curr=q.front();
               q.pop();

               for(auto x:adj[curr])
               {
                   indeg[x]--;
                   if(indeg[x]==0)
                   {
                       q.push(x);
                       char ch=(x+'a');
                       topo=topo+ch;
                   }
               }
            }
        }
        
        return topo;
}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(26);
     
      
        for(int i=0;i<N-1;i++)
        {
           string a=dict[i],b=dict[i+1];
           int i1=0,i2=0;
           while(i1<a.length() and i2<b.length())
           {
               if(a[i1]!=b[i2])
               {
                   adj[a[i1]-'a'].push_back(b[i2]-'a');
                //   cout<<a[i1]<<" "<<b[i2]<<endl;
                   break;
               }
               i1++;
               i2++;
           }
        }
        string ans=bfs(adj,K);
     
        // cout<<ans<<endl;
        return ans;
        
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends