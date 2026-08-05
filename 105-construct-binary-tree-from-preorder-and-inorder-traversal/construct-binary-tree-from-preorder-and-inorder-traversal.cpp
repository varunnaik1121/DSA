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
    TreeNode* helper(vector<int> &preorder,vector<int> &inorder,int inStart,int inEnd,int &preStart){
        if(inStart>inEnd) return NULL;
        int target=preorder[preStart];
        int idx=inStart;
        for(;idx<=inEnd;idx++){
            if(inorder[idx]==target){
                break;
            }
        }
        TreeNode* root=new TreeNode(target);
        preStart+=1;
        root->left=helper(preorder,inorder,inStart,idx-1,preStart);
        root->right=helper(preorder,inorder,idx+1,inEnd,preStart);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int preStart=0;
        return helper(preorder,inorder,0,n-1,preStart);
    }
};