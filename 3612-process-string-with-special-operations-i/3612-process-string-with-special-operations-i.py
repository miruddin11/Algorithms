class Solution:
    def processStr(self, s: str) -> str:
        ans = []
        for ch in s:
            if ch == '*':
                if ans:
                    ans.pop()
            elif ch == '#':
                ans.extend(ans)
            elif ch == '%':
                ans.reverse()
            else:
                ans.append(ch)
        return "".join(ans)