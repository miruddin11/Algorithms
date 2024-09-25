class Solution:
    def isPalindrome(self, s: str) -> bool:
        t=""
        s=s.lower()
        for ch in s:
            if(ch.isalnum()):
                t+=ch
        
        l=0
        r=len(t)-1
        while(l<=r):
            if(t[l]!=t[r]):
                return False
            l+=1
            r-=1

        return True