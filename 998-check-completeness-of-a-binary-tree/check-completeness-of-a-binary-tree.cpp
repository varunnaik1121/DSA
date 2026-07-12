class Solution {
public:
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }

    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;

        int N=getHeight(root);

        queue<TreeNode*> q;
        q.push(root);

        int level=0;

        while(!q.empty()){

            int sz=q.size();

            int nodesToBe=pow(2,level);
            int nodesPresent=sz;

            if(level!=N-1){

                if(nodesToBe!=nodesPresent)
                    return false;

            }else{

                //its the last level so do check for ur conditions here

                int firstNullIdx=sz;
                int lastNumIdx=-1;

                int temp=0;
                cout<<"sz is "<<sz<<endl;
                while(!q.empty()){

                    if(firstNullIdx==sz && q.front()==NULL){
                        firstNullIdx=temp;
                    }

                    if(q.front()!=NULL){
                        lastNumIdx=temp;
                    }

                    temp++;

                    q.pop();
                }

                cout<<"level is "<<level<<endl;
                cout<<"Null idx is "<<firstNullIdx<<endl;
                cout<<"Num idx "<<lastNumIdx<<endl;

                if(lastNumIdx==-1 || firstNullIdx>lastNumIdx)
                    return true;

                return false;
            }

            //this will end and below lines are for the inserting the next nodes

            int temp=sz;

            while(temp--){

                TreeNode* tp=q.front();

                if(level<N-2){
                    if(tp->left){
                        q.push(tp->left);
                    }
                    if(tp->right){
                        q.push(tp->right);
                    }

                    

                }else{
                    if(!tp->left){
                        q.push(nullptr);
                    }else{
                        q.push(tp->left);
                    }

                    if(!tp->right){
                        q.push(nullptr);
                    }else{
                        q.push(tp->right);
                    }
                }
                q.pop();
            }

            level++;
        }

        return true;
    }
};