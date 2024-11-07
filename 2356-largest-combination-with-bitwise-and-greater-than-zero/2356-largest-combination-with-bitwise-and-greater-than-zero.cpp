class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result=0;
        for(int i=0;i<24;i++)
        { 
            int count_ith=0;
            for(int &num:candidates) 
            { 
                if((num&(1<<i))!=0) 
                {
                    count_ith+=1;
                }
            }
            result=max(result,count_ith);
        }
        return result;
    }
};