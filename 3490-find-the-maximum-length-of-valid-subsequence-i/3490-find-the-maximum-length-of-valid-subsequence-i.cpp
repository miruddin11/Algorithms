class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
            }else{
                odd++;
            }
        }
        int maxlen=max(odd,even);
        bool e=false,o=false;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0){
                e=true;
            }
            else if(e==true&&nums[i]%2==1){
                cnt+=1;
                e=false;
                o=false;
            }
        }
        int val=2*cnt;
        if(e==true){
            val+=1;
        }
        maxlen=max(maxlen, val);
        cnt=0;
        e=false,o=false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1){
                o=true;
            }
            else if(o==true&&nums[i]%2==0){
                cnt+=1;
                e=false;
                o=false;
            }
        }
        val=2*cnt;
        if(o==true){
            val+=1;
        }
        maxlen=max(maxlen,val);

        return maxlen;
    }
};