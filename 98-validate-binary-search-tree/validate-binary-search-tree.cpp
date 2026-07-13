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
        
        inorder(root,ans,prev);
        return ans;
    }
    void inorder(TreeNode* root,bool &ans,long long &prev){
        if(!root) return;
        inorder(root->left,ans,prev);
        if(root->val<=prev){
            ans=false;
            return;
        }
        prev=root->val;
        inorder(root->right,ans,prev);
       

    }
};