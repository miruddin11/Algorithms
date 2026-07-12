class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {arr[i], i};
        }
        sort(begin(vec), end(vec));
        int rank = 1;
        for(int i = 0; i < n; i++) {
            if(i > 0 && vec[i].first == vec[i-1].first){
                arr[vec[i].second] = arr[vec[i-1].second];
            }
            else{
                arr[vec[i].second] = rank;
                rank++;   
            }
        }
        return arr;
    }
};