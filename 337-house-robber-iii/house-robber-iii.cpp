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
    int rob(TreeNode* root) {
        vector<int> ans=helper(root);
        return max(ans[0],ans[1]);
    }
    vector<int> helper(TreeNode* root){
        if(!root) return {0,0};
        vector<int> temp;
        vector<int> left=helper(root->left);
         vector<int> right=helper(root->right);
        int include=root->val+left[1]+right[1];
        int exclude=0+max(left[0],left[1])+max(right[0],right[1]);
        temp.push_back(include);
        temp.push_back(exclude);
        return temp;
    }
};