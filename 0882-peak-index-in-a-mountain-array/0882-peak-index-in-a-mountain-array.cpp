class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int peakIdx=-1;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            if(mx<arr[i]){
                mx=arr[i];
                peakIdx=i;
            }
        }
        return peakIdx;
    }
};