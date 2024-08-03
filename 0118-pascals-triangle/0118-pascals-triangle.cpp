class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        prev.push_back(1);
        ans.push_back(prev);
        for(int i=1;i<numRows;i++)
        {
            vector<int> curr(i+1);
            for(int j=0;j<=i;j++){
                if(j==0||j==i){
                    curr[j]=1;
                }else{
                    curr[j]=prev[j-1]+prev[j];
                }
            }
            ans.push_back(curr);
            prev=curr;
        }
        return ans;
    }
};