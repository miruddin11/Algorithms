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
        Node* newHead=NULL;
        unordered_map<Node*,Node*> mp;
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL)
        {
            int v=curr->val;
            Node* newNode=new Node(v);
            mp[curr]=newNode;
            if(newHead==NULL){
                newHead=newNode;
            }
            else{
                prev->next=newNode;
            }
            prev=newNode;
            curr=curr->next;
        }
        Node* newCurr=newHead;
        curr=head;
        while(curr!=NULL&&newCurr!=NULL)
        {
            if(curr->random==NULL){
                newCurr->random=NULL;
            }else{
                newCurr->random=mp[curr->random];
            }
            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;
    }
};