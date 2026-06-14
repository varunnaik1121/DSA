/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mpp;
        Node* dummy=new Node(-1);
        Node* temp=head;
        while(temp!=NULL){
            Node* tmp=new Node(temp->val);
            if(dummy->next==NULL){
                dummy->next=tmp;
            }
            mpp[temp]=tmp;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            mpp[temp]->next=mpp[temp->next];
            mpp[temp]->random=mpp[temp->random];
            temp=temp->next;
        }
        return dummy->next;
    }
};