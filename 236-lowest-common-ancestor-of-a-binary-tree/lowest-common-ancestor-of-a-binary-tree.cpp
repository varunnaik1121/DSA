/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode*  &ans){
        if(root==NULL) return 0;
        int cnt=0;
        if(root->val==p->val || root->val==q->val){
            cnt+=1;
        }
        cnt=cnt+helper(root->left,p,q,ans)+helper(root->right,p,q,ans);
        if(cnt>=2 && !ans){
            ans=root;
        }
        return cnt;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       TreeNode* ans=NULL;
       helper(root,p,q,ans);
       return ans; 
    }
};