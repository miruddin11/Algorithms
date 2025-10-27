class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0;
        int beamsCount=0;
        int n=bank.size();
        for(int i=0;i<n;i++){
            int curr=0;
            for(auto &ch:bank[i]){
                if(ch=='1'){
                    curr+=1;
                }
            }
            beamsCount+=(prev*curr);
            if(curr!=0){
                prev=curr;
            }
        }
        return beamsCount;
    }
};