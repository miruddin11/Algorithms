class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(auto &x:logs)
        {
            if(x=="../"){
                if(cnt>0) cnt-=1;
                else continue;
            }
            else if(x=="./"){
                continue;
            }
            else{
                cnt+=1;
            }
        }
        return cnt;
    }
};