class Solution:
    def numOfWays(self, n: int) -> int:
        mod=1_0000_0000_7
        a,b = 6,6
        for i in range(2,n+1):
            newA= (2*a+2*b) %mod
            newB= (2*a+3*b) %mod
            a=newA
            b=newB

        return (a+b) %mod