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
    ListNode* rev(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* newHead=rev(head);
        vector<int> ans;
        stack<int> st;
        while(newHead)
        {
            while(!st.empty()&&newHead->val>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                ans.push_back(st.top());
            }
            else{
                ans.push_back(0);
            }
            st.push(newHead->val);
            newHead=newHead->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};