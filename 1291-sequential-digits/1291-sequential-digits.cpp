class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n = 9;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            string num = "";
            for(int j = i; j < n; j++) {
                num += s[j];
                int numVal = stoi(num);
                if(numVal >= low && numVal <= high) {
                    ans.push_back(numVal);
                }
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};