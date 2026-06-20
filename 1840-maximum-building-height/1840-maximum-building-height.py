class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        restrictions.append([1, 0])
        restrictions.sort()

        if restrictions[-1][0] != n:
            restrictions.append([n, n - 1])
        
        m = len(restrictions)

        # Left passing adjustment
        for i in range(1, m):
            d = restrictions[i][0] - restrictions[i - 1][0]
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + d) 
        
        # Right passing adjustment
        for i in range(m - 2, -1, -1):
            d = restrictions[i + 1][0] - restrictions[i][0]
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + d)
        
        maxHeight = 0
        for i in range(1, m):
            a , h1 = restrictions[i - 1]
            b, h2 = restrictions[i]
            d = b - a
            height = (h1 + h2 + d) // 2
            maxHeight = max(maxHeight, height)
        
        return maxHeight