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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false;
        if(root->val==targetSum && (root->left==NULL && root->right==NULL)) return true;
        return helper(root->val,root->left,targetSum)||helper(root->val,root->right,targetSum);
    }
    bool helper(int sum,TreeNode* root,int target){
        if(root==NULL) return false;
        int currSum=sum+root->val;
        if((currSum==target) && (root->left==NULL && root->right==NULL)){
            return true;
        }
        return helper(currSum,root->left,target)||helper(currSum,root->right,target);
    }
};