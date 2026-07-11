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
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
    int helper(TreeNode* root,int rev){
        if(!root) return 0;
        int currRev=(rev*10)+(root->val)%10;
        if(root->left==NULL && root->right==NULL) return currRev;
        return helper(root->left,currRev)+helper(root->right,currRev);
        
    }
};