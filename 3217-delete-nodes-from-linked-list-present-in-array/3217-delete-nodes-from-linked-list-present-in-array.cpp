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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(),nums.end());
        while(head!=nullptr&&toRemove.count(head->val)){
            head=head->next;
        }
        ListNode* curr=head;
        ListNode* prev=head;
        while(curr!=nullptr){
            if(toRemove.count(curr->val)){
                while(curr!=nullptr&&toRemove.count(curr->val)){
                    curr=curr->next;
                }
                prev->next=curr;
                prev=curr;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};