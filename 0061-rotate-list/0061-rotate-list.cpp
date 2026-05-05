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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) {
            return head;
        }
        int len = 1;
        ListNode *temp = head;
        while(temp->next != nullptr) {
            len += 1;
            temp = temp->next;
        }
        k = k % len;
        if(k == 0) {
            return head;
        }
        ListNode *curr = head;
        int i = 0;
        while(i < len - k - 1) {
            curr = curr->next;
            i++;
        }
        ListNode *newHead = curr->next;
        curr->next = nullptr;
        temp->next = head;
        return newHead;
    }
};