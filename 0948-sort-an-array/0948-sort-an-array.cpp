class Solution {
public:
    void merge(int l,int mid,int r,vector<int> &nums)
    {
        vector<int> left,right;
        int i=0;
        while(i<mid-l+1){
            left.push_back(nums[l+i]);
            i++;
        }
        int j=0;
        while(j<r-mid){
            right.push_back(nums[mid+1+j]);
            j++;
        }
        i=0,j=0;
        int k=l;
        while(i<left.size()&&j<right.size())
        {
            if(left[i]<=right[j]){
                nums[k]=left[i];
                i++;
            }
            else{
                nums[k]=right[j];
                j++;
            }
            k++;
        }
        while(i<left.size()){
            nums[k]=left[i];
            i++;
            k++;
        }
        while(j<right.size()){
            nums[k]=right[j];
            j++;
            k++;
        }
    }
    void mergeSort(int l,int r,vector<int> &nums)
    {
        if(l<r){
            int mid=l+(r-l)/2;
            mergeSort(l,mid,nums);
            mergeSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergeSort(0,n-1,nums);
        return nums;
    }
};