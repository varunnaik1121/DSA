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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        unordered_map<TreeNode*,TreeNode*> parentMap;
        set<TreeNode*> visited;
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            //if its a leaf node then
            if(!node->left && !node->right){
                if(node->val==target){
                    if(parentMap.find(node)==parentMap.end()){
                        return NULL;
                    }else{
                        TreeNode* parentNode=parentMap[node];
                        if(parentNode->left==node){
                            parentNode->left=NULL;
                        }else{
                            parentNode->right=NULL;
                        }
                    }
                }
            }else if(visited.find(node)==visited.end()){
                st.push(node);
                visited.insert(node);
                if(node->left){
                    st.push(node->left);
                    parentMap[node->left]=node;
                }
                if(node->right){
                    st.push(node->right);
                    parentMap[node->right]=node;
                }
            }
        }
        return root;

    }
};