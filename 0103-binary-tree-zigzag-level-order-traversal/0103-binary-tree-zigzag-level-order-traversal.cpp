/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode*> q;
        vector<vector<int>> a;
    if(!root)return a;

        q.push(root);
        bool flag=false;
        int idx=0;
        while(!q.empty())
        {
            
            int n=q.size();
            if(n>0)a.push_back({});
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
               
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
               
             
                
                
                a[idx].push_back(curr->val);
                q.pop();
                
            }
            // flag=!flag;
            idx++;
                
        }
        for(int i=0;i<a.size();i++)
        {
          if(i%2!=0)
          {
              reverse(a[i].begin(),a[i].end());
          }
        }
        return a;
    }
};