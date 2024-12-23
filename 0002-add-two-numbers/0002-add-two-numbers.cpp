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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead=new ListNode(-1);
        ListNode* head=dummyHead;
        int carry=0;
        while(l1||l2)
        {
            int a=(l1)?l1->val:0;
            int b=(l2)?l2->val:0;
            int sum=a+b+carry;
            if(sum>9){
                carry=1;
                sum=sum%10;
            }
            else{
                carry=0;
            }
            ListNode* newNode=new ListNode(sum);
            dummyHead->next=newNode;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            dummyHead=dummyHead->next;
        }
        if(carry==1){
            dummyHead->next=new ListNode(1);
        }
        return head->next;
    }
};