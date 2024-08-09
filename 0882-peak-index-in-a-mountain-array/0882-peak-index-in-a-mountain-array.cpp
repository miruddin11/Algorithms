class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx=max_element(arr.begin(),arr.end())-arr.begin();
        return idx;
    }
};