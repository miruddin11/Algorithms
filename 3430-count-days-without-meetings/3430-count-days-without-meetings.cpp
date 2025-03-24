class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int max_end=0,wdays=0;
        for(auto &m:meetings)
        {
            if(m[0]<=max_end){
                if(m[1]>max_end){
                    wdays+=m[1]-max_end;
                }
            }
            else{
                wdays+=m[1]-m[0]+1;
            }
            max_end=max(max_end,m[1]);
        }
        return days-wdays;
    }
};