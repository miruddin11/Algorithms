class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = [0] * 26
        for ch in text:
            freq[ord(ch) - ord('a')] += 1
        
        maxFreq = 10**5
        s = "baloon"
        for ch in s:
            f = freq[ord(ch) - ord('a')]
            if  f == 0:
                return 0
            elif (ch == 'l' or ch == 'o') and f < 2:
                return 0
            else:
                if ch == 'l' or ch == 'o':
                    maxFreq = min(maxFreq, f // 2)
                else:
                    maxFreq = min(maxFreq, f)
        
        return maxFreq