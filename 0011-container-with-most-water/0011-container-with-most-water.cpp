class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n=height.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int currW=(r-l)*min(height[l],height[r]);
            ans=max(ans,currW);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};