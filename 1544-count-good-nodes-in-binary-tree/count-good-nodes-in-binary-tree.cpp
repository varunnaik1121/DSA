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
    int goodNodes(TreeNode* root) {
        int prevMax=INT_MIN;
        return helper(root,prevMax);
    }
    int helper(TreeNode* root,int prevMax){
        if(!root) return 0;
        int total=0;
        if(root->val>=prevMax){
            total+=1;
        }
        prevMax=max(prevMax,root->val);
        return total+helper(root->left,prevMax)+helper(root->right,prevMax);
    }
};