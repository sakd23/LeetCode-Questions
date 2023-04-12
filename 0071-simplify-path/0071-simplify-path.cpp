class Solution {
public:
    string simplifyPath(string path) {
       // int dotc=0,slashc=0;
        
        stack<string> ans;

        int n=path.size();
        
      
        for(int i=1;i<n;i++)
        {
            
            string curr_dir="";
      
            while(i<n and path[i]!='/')
            {
              curr_dir=curr_dir+path[i];
                i++;
            }
            
            
            if(curr_dir=="" or curr_dir==".")
            {
                
                curr_dir="";
                
            }
            
          
            else if(curr_dir=="..")
            {
               // pop last directory
                if(!ans.empty())
                {
                    
                    ans.pop();
                }
                
                
            }
            
           
            else
            {
                ans.push(curr_dir);
                
            }
            
            curr_dir="";
            
     
        }
         string sans="/";
        
               while(!ans.empty())
               {
                   cout<<ans.top()<<endl;
                   sans=ans.top()+sans;
                   sans="/"+sans;
                   ans.pop();
               }

        

        
        if(sans.size()>1)
        sans=sans.substr(0,sans.size()-1);
        return sans;
    }
};