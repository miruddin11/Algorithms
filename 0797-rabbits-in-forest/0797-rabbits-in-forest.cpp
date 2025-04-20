class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map <int,int> mpp;
        for (int i : nums) mpp[i]++;
        int total=0;
        for (auto& p : mpp) total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};