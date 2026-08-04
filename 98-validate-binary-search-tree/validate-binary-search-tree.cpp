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
    bool isValidBST(TreeNode* root) {
        long long mini=LLONG_MIN;
        return helper(root,mini);
    }
    bool helper(TreeNode* root,long long &mini){
        if(!root) return true;
        bool leftStatus=helper(root->left,mini);
        if(!leftStatus) return false;
        if(root->val<=mini) return false;
        mini=root->val;
        return helper(root->right,mini);
        
    }
};