class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def hasNum(s):
            return any(ch.isdigit() for ch in s)

        letter_log , digit_log = [] , []
        ans = []
        for i, log in enumerate(logs):
            values = log.split(' ')
            if hasNum(values[1:]):
                digit_log.append(log)
            else:
                letter_log.append([' '.join(values[1:]), values[0], i])
        
        for letter in sorted(letter_log):
            ans.append(logs[letter[2]])
        
        return ans + digit_log