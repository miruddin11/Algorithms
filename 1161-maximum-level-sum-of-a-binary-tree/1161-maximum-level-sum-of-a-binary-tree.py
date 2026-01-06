# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0

        que = deque([root])
        max_sum = float('-inf')
        maxSum_level = 1
        curr_level = 1

        while que:
            size = len(que)
            level_sum = 0
            while size > 0:
                node = que.popleft()
                level_sum += node.val
                if node.left:
                    que.append(node.left)
                if node.right:
                    que.append(node.right)
                size -= 1
            
            if level_sum > max_sum:
                max_sum = level_sum
                maxSum_level = curr_level
            
            curr_level += 1

        return maxSum_level        