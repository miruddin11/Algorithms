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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode(-1);
        ListNode* even=new ListNode(-1);
        ListNode* dummyOdd=odd;
        ListNode* dummyEven=even;
        bool flagOdd=true;
        while(head)
        {
            if(flagOdd){
                dummyOdd->next=head;
                dummyOdd=dummyOdd->next;
            }
            else{
                dummyEven->next=head;
                dummyEven=dummyEven->next;
            }
            head=head->next;
            flagOdd=!flagOdd;
        }
        even=even->next;
        dummyEven->next=NULL;
        dummyOdd->next=even;
        return odd->next;
    }
};