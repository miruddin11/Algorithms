class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        n = len(grid)
        if grid[0][0] == 1 or grid[-1][-1] == 1:
            return -1
        steps = 0
        directions = [[-1, 0], [-1, -1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, 1]]
        que = []
        que.append([0, 0])
        while que:
            sz = len(que)
            while sz:
                i , j = que.pop(0)
                if i == n - 1 and j == n - 1:
                    return steps + 1
                for di, dj in directions:
                    ni = i + di
                    nj = j + dj
                    if ni >= 0 and ni < n and nj >= 0 and nj < n and grid[ni][nj] == 0:
                        que.append([ni, nj])
                        grid[ni][nj] = 1
                sz -= 1
            steps += 1
        
        return -1