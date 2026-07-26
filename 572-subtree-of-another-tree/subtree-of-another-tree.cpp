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
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p && !q) return true;
        if(!p && q) return false;
        if(!q && p) return false;
        return (p->val==q->val) && (isSameTree(p->left,q->left)) && (isSameTree(p->right,q->right));
    }
    void helper(TreeNode* root,TreeNode* subRoot,bool &isSame){
        if(isSame) return;
        if(!root) return;
        helper(root->left,subRoot,isSame);
        if(root->val==subRoot->val){
            if(isSameTree(root,subRoot)){
                isSame=true;
                return;
            }
        }
        helper(root->right,subRoot,isSame);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //start with visiting every node and check
        //when u find the root node then pass both the trees for the testing
       bool isSame=false; 
        helper(root,subRoot,isSame);
       return isSame; 
    }
};