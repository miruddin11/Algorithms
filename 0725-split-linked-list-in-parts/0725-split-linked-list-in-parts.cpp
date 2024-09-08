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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode* curr=head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        vector<ListNode*> ans(k,NULL);
        curr=head;
        ListNode* prev=NULL;
        int rem=len%k;
        int size=len/k;
        for(int i=0;i<k&&curr!=NULL;i++)
        {
            ans[i]=curr;
            for(int count=1;count<=size+(rem>0?1:0);count++)
            {
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
                prev->next=NULL;
            }
            rem--;
        }
        return ans;
    }
};