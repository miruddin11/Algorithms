class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> v(n,vector<int>(11,0));
        for(int i=0;i<pick.size();i++){
            int xi=pick[i][0];
            int yi=pick[i][1];
            v[xi][yi]+=1;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<11;j++){
                if(v[i][j]>i){
                    cnt+=1;
                    break;
                }
            }
        }
        return cnt;
    }
};