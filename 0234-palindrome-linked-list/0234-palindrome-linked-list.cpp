/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode *head)
    {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        // If it contains only one Node
        if(head==NULL||head->next==NULL) return true;
        ListNode *mid=findMid(head);
        //reverse right Halve of the LL
        ListNode *right=reverse(mid);
        ListNode *left=head;
        //Compare both the halves
        while(right!=NULL){
            if(right->val!=left->val){
                return false;
            }
            right=right->next;
            left=left->next;
        }
        return true;
    }
};