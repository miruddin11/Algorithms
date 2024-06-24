class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flip=0;
        int flipCountFromPastFori=0;
        vector<bool> isFlipped(n,false);
        for(int i=0;i<n;i++)
        {
            if(i>=k&&isFlipped[i-k]==true)
            {
                flipCountFromPastFori--;
            }
            if(flipCountFromPastFori%2==nums[i]){
                if(i+k>n) return -1;
                flip++;
                flipCountFromPastFori++;
                isFlipped[i]=true;
            }
        }
        return flip;
    }
};