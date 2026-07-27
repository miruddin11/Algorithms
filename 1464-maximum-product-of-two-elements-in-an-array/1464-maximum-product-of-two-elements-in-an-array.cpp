class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;
        for(int &num : nums) {
            if(first < num) {
                second = first;
                first = num;
            } else if(second < num) {
                second = num;
            }
        }
        return (first - 1) * (second - 1);
    }
};