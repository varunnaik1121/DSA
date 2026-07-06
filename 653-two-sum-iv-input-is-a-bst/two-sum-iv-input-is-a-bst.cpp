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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    TreeNode* getMin(){
        TreeNode* small=asc.top();
        TreeNode* rightChild=small->right;
        asc.pop();
        while(rightChild){
            asc.push(rightChild);
            rightChild=rightChild->left;
        }
        return small;
    }
    TreeNode* getMax(){
       
        TreeNode* maxi=desc.top();
        TreeNode* rightChild=maxi->left;
        desc.pop();
        while(rightChild){
            desc.push(rightChild);
            rightChild=rightChild->right;
        }
        return maxi;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* leftChild=root;
        TreeNode* rightChild=root;

        if(root==NULL) return false;
        while(leftChild){
            asc.push(leftChild);
            leftChild=leftChild->left;
        }
        while(rightChild){
            desc.push(rightChild);
            rightChild=rightChild->right;
        }
        if(asc.top()==0 || desc.top()==0) return false;
        TreeNode* first=getMin();
        TreeNode* last=getMax();
        while(first!=NULL && last!=NULL && first->val<last->val){
            int sum=first->val+last->val;
            if(sum==k){
                return true;
            }else if(sum>k){
                last=getMax();
            }else{
                first=getMin();
            }
        }
        return false;
    }
};