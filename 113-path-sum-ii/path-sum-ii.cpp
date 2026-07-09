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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,targetSum,0,ans,temp);
        return ans;
    }
    void helper(TreeNode* root,int target,int sum,vector<vector<int>> &ans,vector<int> &temp){
        if(root==NULL) return;
        temp.push_back(root->val);
        int currSum=sum+root->val;
        if(currSum==target && root->left==NULL && root->right==NULL){
            ans.push_back(temp);    
        }
        helper(root->left,target,currSum,ans,temp);
        helper(root->right,target,currSum,ans,temp);
        
       
        temp.pop_back();
       
    }
};