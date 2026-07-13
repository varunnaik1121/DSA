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
        bool ans=true;
        long long prev=LLONG_MIN;
        
        return inorder(root,prev);
        
    }
    bool inorder(TreeNode* root,long long &prev){
        if(!root) return true;
        if(!inorder(root->left,prev)){
            return false;
        }
        if(root->val<=prev) return false;
        prev=root->val;
        return inorder(root->right,prev);
    }
};