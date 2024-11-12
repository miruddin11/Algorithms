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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small_head=new ListNode(0);
        ListNode* large_head=new ListNode(0);
        ListNode* s=small_head;
        ListNode* gs=large_head;
        while(head!=NULL)
        {
            if(head->val<x){
                s->next=head;
                s=s->next;
            }
            else{
                gs->next=head;
                gs=gs->next;
            }
            head=head->next;
        }
        gs->next=NULL;
        s->next=large_head->next;
        return small_head->next;
    }
};