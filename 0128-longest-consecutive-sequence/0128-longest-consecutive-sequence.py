class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        st = set(nums)
        maxLen = 0
        for num in st:
            if (num - 1) not in st:
                currNum = num
                Len = 1
                while (currNum + 1) in st:
                    Len += 1
                    currNum += 1
                maxLen = max(maxLen, Len)
        return maxLen