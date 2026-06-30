class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        freq = {'a': 0, 'b': 0, 'c': 0}
        n = len(s)
        i = 0
        cnt = 0
        for j, ch in enumerate(s):
            freq[ch] += 1
            while freq['a'] > 0 and freq['b'] > 0 and freq['c'] > 0 and i < n:
                cnt += (n - j)
                freq[s[i]] -= 1
                i += 1
            j += 1

        return cnt