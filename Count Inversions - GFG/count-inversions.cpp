//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    typedef  long long ll;
    ll help(ll a[],ll n)
    {
        if(n==1)return 0;
        
        ll ans;
        if((n&1))
         ans=help(a,n/2)+help(a+n/2,n/2+1);
        else
         ans=help(a,n/2)+help(a+n/2,n/2);
         ll tem[n],j=0;
         ll s1=0,s2=n/2;
         while(s1<n/2 and s2<n)
         {
             if(a[s1]<=a[s2])
             {
                tem[j]=a[s1];
                s1++;
                j++;
             }
             else
             {
                tem[j]=a[s2];
               
                s2++;
                j++;  
                ans+=(n/2-s1); 
                
             }
         }
        //   cout<<ans<<endl;
        
         
         while(s1<n/2)
         {
             tem[j]=a[s1];
         
          s1++;
          j++;
         }
         
          while(s2<n)
         {
          tem[j]=a[s2];
          s2++;
          j++;
         }
         for(int i=0;i<n;i++)
         {
             a[i]=tem[i];
         }
        
         return ans;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return help(arr,N);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends