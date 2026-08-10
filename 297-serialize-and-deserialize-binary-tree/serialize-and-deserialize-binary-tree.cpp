/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string temp="";
        preOrder(root,temp);
        return temp;

    }
    void preOrder(TreeNode* root,string &temp){
        if(!root){
            temp+="N,";
            return;
        }
        temp+=to_string(root->val);
        temp+=",";
        preOrder(root->left,temp);
        preOrder(root->right,temp);
        return;
    }

    // Decodes your encoded data to tree.
    
    stringstream ss;
    TreeNode* deserialize(string data) {
       ss.clear();
       ss.str(data);
        return dfs();

    }
    TreeNode* dfs(){
        string str;
        getline(ss,str,',');
        if(str=="N"){
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(str));
        root->left=dfs();
        root->right=dfs();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));