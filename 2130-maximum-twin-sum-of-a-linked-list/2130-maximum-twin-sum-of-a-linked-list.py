# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        st = []
        slow = fast = head
        while fast != None:
            st.append(slow.val)
            slow = slow.next
            fast = fast.next.next
        
        maxSum = 0
        for val in st[::-1]:
            maxSum = max(maxSum, val + slow.val)
            slow = slow.next
        return maxSum