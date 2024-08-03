class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int maxWater=0;
        while(left<right){
            int h=min(height[left],height[right]);
            int currWater=h*(right-left);
            maxWater=max(currWater,maxWater);
            if(height[left]>height[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxWater;
    }
};