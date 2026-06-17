class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        if n > m:
            return self.findMedianSortedArrays(nums2, nums1)
        
        low = 0
        high = n
        while low <= high:
            Px = low + (high - low) // 2
            Py = (n + m + 1) // 2 - Px

            # left side
            x1 = float('-inf') if Px == 0 else nums1[Px - 1]
            x2 = float('-inf') if Py == 0 else nums2[Py - 1]
            # right side
            x3 = float('inf') if Px == n else nums1[Px]
            x4 = float('inf') if Py == m else nums2[Py]

            if x1 <= x4 and x2 <= x3:
                if (n + m) % 2 == 0:
                    return (max(x1, x2) + min(x3, x4)) / 2.0
                else:
                    return max(x1, x2)
            
            if x1 > x4:
                high = Px - 1
            else:
                low = Px + 1

        return -1