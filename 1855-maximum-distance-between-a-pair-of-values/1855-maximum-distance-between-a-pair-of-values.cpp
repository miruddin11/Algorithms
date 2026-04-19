class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int i = 0 , j= 1;
        for(; i < n && j < m; j++) {
            i += (nums1[i] > nums2[j]);
        } 
        return j - i - 1;
    }
};