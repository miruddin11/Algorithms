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
        if(head==NULL) return head;
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.find(head->val)!=st.end()&&head!=NULL){
            head=head->next;
        }
        ListNode *temp=head;
        ListNode *prev=head;
        while(temp!=NULL)
        {
            if(st.find(temp->val)!=st.end()){
                while(temp!=NULL&&st.find(temp->val)!=st.end()){
                    temp=temp->next;
                }
                prev->next=temp;
                prev=temp;
            }else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};