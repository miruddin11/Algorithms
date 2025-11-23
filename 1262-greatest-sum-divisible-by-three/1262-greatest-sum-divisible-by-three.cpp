class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> remain1, remain2;
        for (int num : nums) {
            sum += num;
            if (num % 3 == 1)
                remain1.push_back(num);
            else if (num % 3 == 2) 
                remain2.push_back(num);
        }
        if (sum % 3 == 0) 
            return sum;
        sort(begin(remain1), end(remain1));
        sort(begin(remain2), end(remain2));
        int result = 0;
        if (sum % 3 == 1) {
            int remove1 = remain1.size() >= 1 ? remain1[0] : INT_MAX;
            int remove2 = remain2.size() >= 2 ? remain2[0] + remain2[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        } 
        else {
            int remove1 = remain2.size() >= 1 ? remain2[0] : INT_MAX;
            int remove2 = remain1.size() >= 2 ? remain1[0] + remain1[1] : INT_MAX;
            result      = sum - min(remove1, remove2);
        }
        return result < 0 ? 0 : result;
    }
};