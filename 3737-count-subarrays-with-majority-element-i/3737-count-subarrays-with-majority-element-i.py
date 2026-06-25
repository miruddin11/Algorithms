class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        count = 0
        n = len(nums)
        for i in range(n):
            freq = {}
            for j in range(i, n):
                freq[nums[j]] = freq.get(nums[j], 0) + 1
                totalElement = j - i + 1
                if  2 * freq.get(target, 0) > totalElement:
                    count += 1

        return count