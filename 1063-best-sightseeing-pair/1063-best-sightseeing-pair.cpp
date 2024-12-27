class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_seen = values[0];
        int max_score = 0;
        for (int j=1;j<values.size();j++)
        {
            max_score=max(max_score,max_seen+values[j]-j);
            max_seen=max(max_seen,values[j]+j);
        }
        return max_score;
    }
};