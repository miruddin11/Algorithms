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
    ListNode* mergeTwoList(ListNode *l1,ListNode *l2)
    {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            l1->next=mergeTwoList(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoList(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* merge(vector<ListNode*> &lists,int s,int e)
    {
        if(s>e){
            return NULL;
        }
        if(s==e) return lists[s];
        int mid=s+(e-s)/2;
        ListNode* l1=merge(lists,s,mid);
        ListNode* l2=merge(lists,mid+1,e);
        return mergeTwoList(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return NULL;
        int s=0,e=k-1;
        return merge(lists,s,e);
    }
};