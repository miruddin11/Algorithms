class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = ""
        for word in words:
            weight_sum = 0
            for ch in word:
                idx = ord(ch) - ord('a')
                weight_sum += weights[idx]
            
            pos = weight_sum % 26
            ans = ans + chr(122 - pos)
        
        return ans