class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(),banned.end());
        long long sum=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)!=st.end()){
                continue;
            }
            sum=sum+i;
            if(sum<=maxSum){
                cnt+=1;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};