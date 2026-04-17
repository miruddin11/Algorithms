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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> a;
        ListNode* temp = head;
        while(temp != nullptr) {
            a.push_back(temp->val);
            temp = temp->next;
        }
        ListNode *dummy = new ListNode(-1);
        temp = dummy;
        int n = a.size();
        for(int i = 0; i < n - 1; i++) {
            temp->next = new ListNode(a[i]);
            int nextNode = __gcd(a[i] , a[i + 1]);
            temp = temp->next;
            temp->next = new ListNode(nextNode);
            temp = temp->next;
        }
        temp->next = new ListNode(a[n - 1]);
        return dummy->next;
    }
};