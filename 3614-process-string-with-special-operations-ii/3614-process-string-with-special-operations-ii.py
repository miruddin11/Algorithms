class Solution:
    def processStr(self, s: str, k: int) -> str:
        # 1st pass to calculate the total length
        L = 0
        for ch in s:
            if ch == '*':
                L = max(0, L - 1)
            elif ch == '#':
                L = L + L
            elif ch == '%':
                continue
            else:
                L = L + 1
        if k >= L:
            return '.'
        # 2nd pass for reverse simulation i.e, right to left
        # there are 3 cases for 3 special characters 
        # if it's # then L = L // 2 , k = k - L // 2 (k >= L)
        # for % L no change, k = L - k - 1 (k >= L)
        # for * L = L + 1 , K no change
        # if at any point k == L then return s[i]

        for ch in reversed(s):
            if ch == '#':
                L = L // 2
                if k >= L:
                    k = k - L
            elif ch == '%':
                k = L - k - 1
            elif ch == '*':
                L = L + 1
            else: 
                L = L - 1
            if k == L:
                return ch
        return '.'