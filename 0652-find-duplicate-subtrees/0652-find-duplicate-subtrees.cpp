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
    map<string,vector<TreeNode*>> m;
    string help(TreeNode* root)
    {
        if(!root)return "#";
        string ans=to_string(root->val)+"$"+help(root->left)+"$"+help(root->right);
        m[ans].push_back(root);
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        help(root);
        vector<TreeNode*> ans;
        for(auto x:m)
        {
            // cout<<x.first<<endl;
            if(x.second.size()>1)ans.push_back(x.second[0]);
        }
        return ans;
    }
};