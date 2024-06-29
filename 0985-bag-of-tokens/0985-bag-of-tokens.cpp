class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(),token.end());
        int n=token.size();
        int l=0,r=n-1;
        int score=0,maxScore=0;
        while(l<=r)
        {
            if(power>=token[l]){
                score++;
                power-=token[l];
                l++;
                maxScore=max(score,maxScore);
            }
            else if(score>=1){
                score--;
                power+=token[r];
                r--;
            }
            else{
                return maxScore;
            }
        }
        return maxScore;
    }
};