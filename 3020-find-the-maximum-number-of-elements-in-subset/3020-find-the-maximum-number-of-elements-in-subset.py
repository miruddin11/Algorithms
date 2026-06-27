class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        freqMap = {}
        for num in nums:
            freqMap[num] = freqMap.get(num , 0) + 1
        
        ans = 1
        if freqMap.get(1, 0) > 0:
            val = freqMap.get(1, 0)
            ans = max(ans, val - 1 if val % 2 == 0 else val)
        
        for num in nums:
            if num == 1:
                continue
            len = 0
            x = num
            while freqMap.get(x, 0) >= 2:
                len += 2
                if x > 10**9:
                    break
                x = x * x
            if freqMap.get(x, 0) >= 1:
                len += 1
            else:
                len -= 1
            ans = max(ans, len)
        
        return ans