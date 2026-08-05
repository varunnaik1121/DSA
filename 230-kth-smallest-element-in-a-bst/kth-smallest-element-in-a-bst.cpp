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
    int kthSmallest(TreeNode* root, int k) {
        int kthSmall=0;
        int count=0;
        helper(root,k,kthSmall);
        return kthSmall;
    }
    void helper(TreeNode* root,int &k,int &kthSmall){
        if(!root || k==0) return;
        helper(root->left,k,kthSmall);
        k--;
        if(k==0){
            kthSmall=root->val;
            return;
        }
        if(kthSmall!=0) return;
        helper(root->right,k,kthSmall);
    }
};