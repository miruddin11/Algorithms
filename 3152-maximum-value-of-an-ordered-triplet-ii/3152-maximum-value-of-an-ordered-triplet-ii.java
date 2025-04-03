class Solution {
    public long maximumTripletValue(int[] nums) {
        long fmax=Integer.MIN_VALUE,smax=Integer.MIN_VALUE;
        long res=0,diff=0;
        for(int i=0;i<nums.length-1;i++)
        {
            if(nums[i]>fmax)
            {
                smax=fmax=nums[i];
            }
            else{
                smax=nums[i];
            }
            if(fmax==Integer.MIN_VALUE||smax==Integer.MIN_VALUE)
                continue;
            long currdiff=fmax-smax;
            diff=Math.max(diff,currdiff);
            long curr=diff*nums[i+1];
            res=Math.max(curr,res);
        }
        return res<0? 0:res;
    }
}