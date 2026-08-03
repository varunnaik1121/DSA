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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(!root){
            return {};
        }
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* topNode=q.front();
                q.pop();
                if(sz==0){
                    ans.push_back(topNode->val);
                }
                if(topNode->left){
                    q.push(topNode->left);
                }
                if(topNode->right){
                    q.push(topNode->right);
                }
            }
            
        }
        return ans;
    }
};