/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if (!root)
            return true;
        bool nullSeen = false;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                if (!node) {
                    nullSeen = true;
                }

                if (nullSeen && node) {
                    return false;
                }
                if(!node) continue;
               if(node->left){
                 q.push(node->left);
               
               }else{
                q.push(nullptr);
               }
               if(node->right){
                 q.push(node->right);
               }else{
                q.push(nullptr);
               }
            }
        }
        return true;
    }
};