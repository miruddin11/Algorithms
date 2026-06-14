# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        nodes = []
        while head != None:
            nodes.append(head.val)
            head = head.next
        n = len(nodes)
        maxSum = 0
        for i in range(0, n // 2):
            maxSum = max(maxSum, nodes[i] + nodes[n - i - 1])
        
        return maxSum