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
    
    vector<int> rob1(TreeNode* root)
    {
        vector<int> ans(2,0);
        if(!root)return ans;
        vector<int> left=rob1(root->left);
        vector<int> right=rob1(root->right);
        ans[0]=max(right[0],right[1])+max(left[0],left[1]);
        
        ans[1]=root->val+right[0]+left[0];
        
        return ans;
    }
    int rob(TreeNode* root) {
        
        vector<int>ans=rob1(root);
        return max(ans[0],ans[1]);
    }
};