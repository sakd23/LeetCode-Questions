class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& a, int k, int c) {
        ll ans=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq1,pq2,pq3;
        if(2*c>a.size())
        {
            sort(a.begin(),a.end());
            for(int i=0;i<k;i++)
            {
               ans+=a[i];
            }
            return ans;
        }
        for(int i=0;i<c;i++)
        {
         pq1.push(a[i]);   
        }
        int n=a.size();
         int j=n-1,s1=c;
        int siz=n;
        
        for(int i=0;i<c;i++)
        {
         pq2.push(a[j]); 
            j--;
        }
        int s2=j;
        cout<<s2<<endl;
        while(s2>=s1 and k>0)
        {
            
          ll fir=pq1.top(),sec=pq2.top();
            if(fir<=sec)
            {
                pq1.pop();
                pq1.push(a[s1]);
                s1++;
                ans+=fir;
                
            }
            else
            {
               pq2.pop();
                pq2.push(a[s2]);
                s2--;  
                ans+=sec;
            }
          
            k--;
            cout<<ans<<endl;
        }
        while(!pq1.empty())
        {
            pq3.push(pq1.top());
            pq1.pop();
        }
        
         while(!pq2.empty())
        {
            pq3.push(pq2.top());
            pq2.pop();
        }
        while(k>0 and !pq3.empty())
        {
            ans+=pq3.top();
            pq3.pop();
            k--;
            cout<<ans<<endl;
        }
        return ans;
        
    }
};